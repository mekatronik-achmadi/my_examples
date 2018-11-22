/**
 * @file    main.c
 * @brief   Main program code
 *
 * @addtogroup MAIN
 * @{
 */
#include <windows.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include "mapp.h"
#include "sysinfo.h"

/**
 * @brief   Window Process Callback
 */
LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam){
	switch(msg){
	case WM_CREATE:
        Widget_Create(hwnd); Menubar_Create(hwnd); break;
	case WM_COMMAND:
		Widget_Callback(wParam,hwnd); break;
	case WM_DESTROY:
		PostQuitMessage(0);break;

	default:
		return DefWindowProcW(hwnd, msg, wParam, lParam);
	}

	return 0;
}

/**
 * @brief   Main Process Routine
 */
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR lpCmdLine,int nCmdShow){
	MSG msg;

	WNDCLASSW wc = {0};
	wc.lpszClassName = L"Win32 SySInfo";
	wc.hInstance = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpfnWndProc = WndProc;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL,IDI_APPLICATION);

	RegisterClassW(&wc);
	Console_Create();
	CreateWindowW(
				wc.lpszClassName,
				L"Win32 Sys Info",
				WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                150, 150, 250, 200,
				0, 0, hInstance, 0);

	while(GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}
/** @} */
