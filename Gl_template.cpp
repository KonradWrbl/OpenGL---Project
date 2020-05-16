#define  _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#ifdef _MSC_VER
#   ifndef _MBCS
#      define _MBCS
#   endif
#   ifdef _UNICODE
#      undef _UNICODE 
#   endif
#   ifdef UNICODE
#      undef UNICODE 
#   endif
#endif

#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <math.h>
#include <stdio.h>
#include "RESOURCE.H"
#include "Cuboid.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Terrain.h"
#include "Rover.h"
#include "Rocket.h"


static LPCTSTR lpszAppName = "£azik - Grafika Komputerowa";
float xRot = 20, yRot;

void ChangeSize(GLsizei w, GLsizei h) {
	GLfloat nRange = 100.0f;
	GLfloat fAspect;

	if (h == 0) {
		h = 1;
	}

	fAspect = (GLfloat)w / (GLfloat)h;
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h) {
		glOrtho(-nRange, nRange, -nRange * h / w, nRange * h / w, -nRange, nRange);
	}
	else {
		glOrtho(-nRange * w / h, nRange * w / h, -nRange, nRange, -nRange, nRange);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SetupRC() {
	glEnable(GL_NORMALIZE);
	GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	GLfloat  diffuseLight[] = { 1, 1, 1, 1 };
	GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat	 lightPos[] = { 0, 0, 500, 1 };
	GLfloat  specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.094, 0.050, 0.027, 1.0f);
}

void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	glScalef(.2, .2, .2);
	Terrain terr(1000, 1000);
	
	Rover rover;
	rover.draw();

	terr.draw();

	Rocket rocket;
	rocket.draw();

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glFlush();
}

void SetDCPixelFormat(HDC hDC) {
	int nPixelFormat;

	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		32, 0, 0, PFD_MAIN_PLANE, 0, 0, 0, 0
	};

	nPixelFormat = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, nPixelFormat, &pfd);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static HGLRC hRC;
	static HDC hDC;

	switch (message) {
	case WM_CREATE:
		hDC = GetDC(hWnd);
		SetDCPixelFormat(hDC);
		hRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, hRC);
		SetupRC();
		break;
	case WM_DESTROY:
		wglMakeCurrent(hDC, NULL);
		wglDeleteContext(hRC);
		PostQuitMessage(0);
		break;
	case WM_SIZE:
		ChangeSize(LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_PAINT:
		RenderScene();
		SwapBuffers(hDC);
		ValidateRect(hWnd, NULL);
		break;
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_UP:
			xRot -= 5;
			break;
		case VK_DOWN:
			xRot += 5;
			break;
		case VK_LEFT:
			yRot -= 5;
			break;
		case VK_RIGHT:
			yRot += 5;
			break;
		}

		xRot = (float)((const int)xRot % 360);
		yRot = (float)((const int)yRot % 360);

		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_FILE_EXIT) {
			DestroyWindow(hWnd);
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	WNDCLASS wc;
	HWND hWnd;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	wc.hbrBackground = NULL;

	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
	wc.lpszClassName = lpszAppName;

	if (RegisterClass(&wc) == 0) {
		return FALSE;
	}

	hWnd = CreateWindow(
		lpszAppName,
		lpszAppName,
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		50, 50,
		800, 800,
		NULL,
		NULL,
		hInstance,
		NULL);

	if (hWnd == NULL) {
		return FALSE;
	}

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}