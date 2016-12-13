// Lab11_OOP.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Lab11_OOP.h"
#include <vector>
std::vector<HWND> vec;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR mainMessage[] = L"Some text!";
int count = 1;
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	TCHAR szClassName[] = L"Мой класс";
	HWND hMainWnd;
	MSG msg;
	WNDCLASSEX wc;
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	wc.cbWndExtra = NULL;
	wc.cbClsExtra = NULL;
	wc.hIcon = LoadIcon(NULL,IDI_WINLOGO);
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hInstance = hInstance;
	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, L"Не получилось зарегистрировать класс!", L"Ошибка", MB_OK);
		return NULL;
	}
	hMainWnd = CreateWindow(szClassName, L"Полноценная оконнная процедура", WS_OVERLAPPEDWINDOW | WS_VSCROLL, CW_USEDEFAULT, NULL, CW_USEDEFAULT, NULL, (HWND)NULL, NULL, HINSTANCE(hInstance), NULL);
	vec.push_back(hMainWnd);
	if (!hMainWnd) {
		MessageBox(NULL, L"Не получилось создать окно", L"Ошибка", MB_OK);
		return NULL;
	}
	ShowWindow(hMainWnd, nCmdShow);
	UpdateWindow(hMainWnd);
	while (GetMessage(&msg, NULL, NULL, NULL)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hDc;
	PAINTSTRUCT ps;
	RECT rect;
	COLORREF colorText = RGB(255, 0, 0);
	switch (uMsg) {
	case WM_LBUTTONDOWN:
		SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM)"Hello World");
		if (count < 5)
		{
			HWND handle;
			handle = CreateWindow(L"My class", L"Полноценная оконнная процедура", WS_OVERLAPPEDWINDOW | WS_VSCROLL, CW_USEDEFAULT, NULL, CW_USEDEFAULT, NULL, vec[count-1], NULL, NULL, NULL);
			ShowWindow(handle, SW_SHOWDEFAULT);
			UpdateWindow(handle);
			vec.push_back(handle);
			++count;
		}
		break;
	case WM_KEYDOWN:
	case WM_CLOSE:
		MessageBox(NULL, L"Close Window", L"Close Window", MB_OKCANCEL | MB_DEFBUTTON1);
		DestroyWindow(vec.back());
		vec.pop_back();
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return NULL;
}