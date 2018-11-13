// MyConsole.h: interface for the MyConsole class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCONSOLE_H__870BBF9F_9D87_4FA8_9A30_3BD0AD96A752__INCLUDED_)
#define AFX_MYCONSOLE_H__870BBF9F_9D87_4FA8_9A30_3BD0AD96A752__INCLUDED_

#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MyConsole  
{
public:
	MyConsole();
	virtual ~MyConsole();
	void RedirectIOToConsole();

private:
	double MAX_CONSOLE_LINES;
};

#endif // !defined(AFX_MYCONSOLE_H__870BBF9F_9D87_4FA8_9A30_3BD0AD96A752__INCLUDED_)
