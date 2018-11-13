// MyInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SysInfo.h"
#include "MyConsole.h"
#include "MyInfo.h"
#include "MyInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyInfoDlg dialog

CMyInfoDlg::CMyInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	mysysinfo = new SysInfo();
	mycsl = new MyConsole();
	mycsl->RedirectIOToConsole();
}

void CMyInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyInfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CMyInfoDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TEXT, OnTEXT)
	ON_BN_CLICKED(IDC_GUI, OnGUI)
	ON_BN_CLICKED(IDC_EXIT, OnEXIT)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyInfoDlg message handlers

BOOL CMyInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	MySetFont();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyInfoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CMyInfoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyInfoDlg::OnTEXT() 
{
	// TODO: Add your control notification handler code here
	m_strResult = mysysinfo->HardInfo(); 
	printf(m_strResult);
}

void CMyInfoDlg::OnGUI() 
{
	// TODO: Add your control notification handler code here
	m_strResult = mysysinfo->HardInfo();
	AfxMessageBox(m_strResult,MB_OK | MB_ICONINFORMATION);
}

void CMyInfoDlg::OnEXIT() 
{
	// TODO: Add your control notification handler code here
	EndDialog(IDCANCEL);
}

void CMyInfoDlg::MySetFont(){
	CFont *m_pFont = new CFont();

    m_pFont->CreateFont(
      12,                        // nHeight
      0,                         // nWidth
      0,                         // nEscapement
      0,                         // nOrientation
      FW_NORMAL,                 // nWeight
      FALSE,                     // bItalic
      FALSE,                     // bUnderline
      0,                         // cStrikeOut
      ANSI_CHARSET,              // nCharSet
      OUT_DEFAULT_PRECIS,        // nOutPrecision
      CLIP_DEFAULT_PRECIS,       // nClipPrecision
      DEFAULT_QUALITY,           // nQuality
      DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
      _T("Dejavu Sans")			 // lpszFacename
	  );

    GetDlgItem(IDC_GUI)->SetFont(m_pFont, TRUE);
	GetDlgItem(IDC_TEXT)->SetFont(m_pFont, TRUE);
	GetDlgItem(IDC_EXIT)->SetFont(m_pFont, TRUE);
}
