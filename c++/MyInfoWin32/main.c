/**
 * @file    main.c
 * @brief   Main program code
 *
 * @addtogroup MAIN
 * @{
 */
#include <windows.h>
#include <stdio.h>
#include "sysinfo.h"

#define IDM_CONSOLE 1
#define IDM_MESSAGE 2
#define IDM_EXIT	3

char msg_info[2048];

void Widget_Create(HWND hwnd){
	/* Button Console */
	CreateWindowW(
		L"Button",L"Console",
		WS_VISIBLE | WS_CHILD,
		20, 50, 80, 25, hwnd,
		(HMENU) IDM_CONSOLE, NULL, NULL);

	/* Button Message */
	CreateWindowW(
		L"Button",L"Message",
		WS_VISIBLE | WS_CHILD,
		120, 50, 80, 25, hwnd,
		(HMENU) IDM_MESSAGE, NULL, NULL);

	/* Button Exit */
	CreateWindowW(
		L"Button",L"Exit",
		WS_VISIBLE | WS_CHILD,
		220, 50, 80, 25, hwnd,
		(HMENU) IDM_EXIT, NULL, NULL);
}

void Widget_Callback(WPARAM wParam,HWND hwnd){
	switch(LOWORD(wParam)){
	/* Button Exit */
	case IDM_EXIT:
		PostQuitMessage(0); break;
	/* Button Message */
	case IDM_MESSAGE:
		sprintf(msg_info,"");
		ExePathInfo(msg_info);
		HardInfo(msg_info);
		MessageBox(hwnd, msg_info, "Sys Info", MB_OK | MB_ICONINFORMATION);
		break;
	}
}

/*===========================================================================*/
/* System Space                                                              */
/*===========================================================================*/

/**
 * @brief   Window Process Callback
 */
LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam){
	switch(msg){
	case WM_CREATE:
		Widget_Create(hwnd); break;
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
int WINAPI wWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PWSTR lpCmdLine,int nCmdShow){
	MSG msg;
	
	WNDCLASSW wc = {0};
	wc.lpszClassName = L"Win32 SySInfo";
	wc.hInstance = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpfnWndProc = WndProc;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL,IDI_APPLICATION);

	RegisterClassW(&wc);
	CreateWindowW(
				wc.lpszClassName,
				L"Win32 Sys Info",
				WS_OVERLAPPEDWINDOW | WS_VISIBLE,
				150, 150, 320, 150,
				0, 0, hInstance, 0);
					
	while(GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}	

	return (int)msg.wParam;
}
/** @} */