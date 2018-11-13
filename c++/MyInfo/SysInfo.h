// SysInfo.h: interface for the SysInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSINFO_H__2650E999_D0DE_42CE_88EF_504F363ABBD9__INCLUDED_)
#define AFX_SYSINFO_H__2650E999_D0DE_42CE_88EF_504F363ABBD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define ARCHITECTURE_INTEL            0
#define ARCHITECTURE_MIPS             1
#define ARCHITECTURE_ALPHA            2
#define ARCHITECTURE_PPC              3
#define ARCHITECTURE_SHX              4
#define ARCHITECTURE_ARM              5
#define ARCHITECTURE_IA64             6
#define ARCHITECTURE_ALPHA64          7
#define ARCHITECTURE_MSIL             8
#define ARCHITECTURE_AMD64            9
#define ARCHITECTURE_IA32_ON_WIN64   10

class SysInfo  
{
public:
	SysInfo();
	virtual ~SysInfo();
	CString HardInfo(void);
	CString GetCpuArch(int sysCpuArch);
	CString GetOsInfo(int osMajor, int osMinor);
};

#endif // !defined(AFX_SYSINFO_H__2650E999_D0DE_42CE_88EF_504F363ABBD9__INCLUDED_)
