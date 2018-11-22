/**
 * @file    app.h
 * @brief   Main App header
 *
 * @addtogroup SYS_INFO
 * @{
 */
#ifndef _MAPP_H_
#define _MAPP_H_

#define IDM_CONSOLE 1
#define IDM_MESSAGE 2
#define IDM_TEXT	3
#define IDM_EXIT	4
#define IDM_ABOUT	5

void Setfont_Create(void);
void Console_Create(void);
void Widget_Create(HWND hwnd);
void Menubar_Create(HWND hwnd);
void TextInfo_Write(void);
void MsgInfo(void);
void Widget_Callback(WPARAM wParam,HWND hwnd);

#endif
/** @} */
