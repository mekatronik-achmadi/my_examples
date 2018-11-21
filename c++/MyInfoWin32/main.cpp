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
#include "sysinfo.h"

#define IDM_CONSOLE 1
#define IDM_MESSAGE 2
#define IDM_EXIT	3

char msg_info[2048];

void Console_Create(void){
    int hCrt;

	FreeConsole();
	AllocConsole();

    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    hCrt = _open_osfhandle((long) handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_err = GetStdHandle(STD_ERROR_HANDLE);
    hCrt = _open_osfhandle((long) handle_err, _O_TEXT);
    FILE* hf_err = _fdopen(hCrt,"w");
    setvbuf(hf_err, NULL, _IONBF, 1);
    *stderr = *hf_err;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;
}

void Widget_Create(HWND hwnd){
	/* Button Console */
	CreateWindowW(
		L"Button",L"Console",
		WS_VISIBLE | WS_CHILD,
		50, 20, 80, 25, hwnd,
		(HMENU) IDM_CONSOLE, NULL, NULL);

	/* Button Message */
	CreateWindowW(
		L"Button",L"Message",
		WS_VISIBLE | WS_CHILD,
		50, 60, 80, 25, hwnd,
		(HMENU) IDM_MESSAGE, NULL, NULL);

	/* Button Exit */
	CreateWindowW(
		L"Button",L"Exit",
		WS_VISIBLE | WS_CHILD,
		50, 100, 80, 25, hwnd,
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
	case IDM_CONSOLE:
		sprintf(msg_info,"");
		ExePathInfo(msg_info);
		HardInfo(msg_info);
		printf("%s",msg_info);
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
				150, 150, 200, 200,
				0, 0, hInstance, 0);

	while(GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}
/** @} */
