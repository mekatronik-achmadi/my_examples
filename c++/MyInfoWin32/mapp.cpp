/**
 * @file    app.c
 * @brief   Main App code
 *
 * @addtogroup SYS_INFO
 * @{
 */

#include <windows.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include "mapp.h"
#include "sysinfo.h"

HFONT hFont;
char msg_info[2048];

void Setfont_Create(void){
    LOGFONT logFont;
    int szFont = 11;

    memset(&logFont, 0, sizeof(logFont));
    logFont.lfHeight = -szFont;
    strcpy(logFont.lfFaceName, "Arial");
    hFont = CreateFontIndirect(&logFont);
}

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
    HWND btnConsole = CreateWindowW(
		L"Button",L"Console",
		WS_VISIBLE | WS_CHILD,
        70, 20, 80, 25, hwnd,
		(HMENU) IDM_CONSOLE, NULL, NULL);

	/* Button Message */
    HWND btnMessage = CreateWindowW(
		L"Button",L"Message",
		WS_VISIBLE | WS_CHILD,
        70, 60, 80, 25, hwnd,
		(HMENU) IDM_MESSAGE, NULL, NULL);

	/* Button Exit */
    HWND btnExit = CreateWindowW(
		L"Button",L"Exit",
		WS_VISIBLE | WS_CHILD,
        70, 100, 80, 25, hwnd,
		(HMENU) IDM_EXIT, NULL, NULL);

    Setfont_Create();
    SendMessage(btnConsole, WM_SETFONT, (WPARAM)hFont, (LPARAM)MAKELONG(TRUE, 0));
    SendMessage(btnMessage, WM_SETFONT, (WPARAM)hFont, (LPARAM)MAKELONG(TRUE, 0));
    SendMessage(btnExit, WM_SETFONT, (WPARAM)hFont, (LPARAM)MAKELONG(TRUE, 0));
}

void Menubar_Create(HWND hwnd){
	HMENU hMenu, hSubMenu;

	hMenu = CreateMenu();

	hSubMenu = CreatePopupMenu();
	AppendMenu(hSubMenu, MF_STRING, IDM_CONSOLE, "&Console");
	AppendMenu(hSubMenu, MF_STRING, IDM_MESSAGE, "&Message");
	AppendMenu(hSubMenu, MF_STRING, IDM_TEXT, "&Save txt");
	AppendMenu(hSubMenu, MF_STRING, IDM_EXIT, "E&xit");
	AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&File");

	hSubMenu = CreatePopupMenu();
	AppendMenu(hSubMenu, MF_STRING, IDM_ABOUT, "&About");
	AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Help");

	SetMenu(hwnd, hMenu);
}

void TextInfo_Write(void){
	HANDLE hFile;
	DWORD wmWritten;

	hFile = CreateFile("sysinfo.txt",
                GENERIC_WRITE | GENERIC_READ,
                0,
                NULL,
                CREATE_ALWAYS,
                FILE_ATTRIBUTE_TEMPORARY,
                NULL);

	WriteFile(hFile,
			msg_info,
			(DWORD)strlen(msg_info),
			&wmWritten,
			NULL);

	CloseHandle(hFile);
}

void MsgInfo(void){
	sprintf(msg_info,"");
	ExePathInfo(msg_info);
	SysAllInfo(msg_info);
}

void Widget_Callback(WPARAM wParam,HWND hwnd){
	switch(LOWORD(wParam)){
	/* Button Exit */
	case IDM_EXIT:
		PostQuitMessage(0); break;
	/* Button Message */
	case IDM_MESSAGE:
		MsgInfo();
		MessageBox(hwnd, msg_info, "Sys Info", MB_OK | MB_ICONINFORMATION);
		break;
	/* Button Console */
	case IDM_CONSOLE:
		MsgInfo();
		printf("%s",msg_info);
		break;
	/* Button Text */
	case IDM_TEXT:
		MsgInfo();
		TextInfo_Write();
		break;
	/* Button About */
	case IDM_ABOUT:
		MessageBox(hwnd, "Simple System Information Program", "About", MB_OK | MB_ICONINFORMATION);
		break;
	}
}
/** @} */
