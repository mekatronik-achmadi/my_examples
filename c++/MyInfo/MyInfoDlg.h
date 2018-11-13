// MyInfoDlg.h : header file
//

#if !defined(AFX_MYINFODLG_H__3364D287_A954_408B_A6F7_3E6BD1A42D8E__INCLUDED_)
#define AFX_MYINFODLG_H__3364D287_A954_408B_A6F7_3E6BD1A42D8E__INCLUDED_

#include "SysInfo.h"	// Added by ClassView
#include "MyConsole.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyInfoDlg dialog

class CMyInfoDlg : public CDialog
{
// Construction
public:
	MyConsole* mycsl;
	SysInfo* mysysinfo;
	CString m_strResult;
	CMyInfoDlg(CWnd* pParent = NULL);	// standard constructor
	void MySetFont(void);

// Dialog Data
	//{{AFX_DATA(CMyInfoDlg)
	enum { IDD = IDD_MYINFO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTEXT();
	afx_msg void OnGUI();
	afx_msg void OnEXIT();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYINFODLG_H__3364D287_A954_408B_A6F7_3E6BD1A42D8E__INCLUDED_)
