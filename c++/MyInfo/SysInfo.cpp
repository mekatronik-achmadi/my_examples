// SysInfo.cpp: implementation of the SysInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyInfo.h"
#include "SysInfo.h"
#pragma comment(lib, "user32.lib")

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SysInfo::SysInfo()
{

}

SysInfo::~SysInfo()
{

}

CString SysInfo::HardInfo(void){
	CString strDWord;
	CString strResult;

	OSVERSIONINFO siOSInfo;
	SYSTEM_INFO siSysInfo;
	
	siOSInfo.dwOSVersionInfoSize = sizeof(siOSInfo);
	GetVersionEx(&siOSInfo);
	GetSystemInfo(&siSysInfo);

	strResult = "\nHardware information:\n";

	strDWord.Format("%d", siSysInfo.dwNumberOfProcessors);
	strResult += "CPU Number: " + strDWord + "\n";

	strResult += "CPU Arch: " + GetCpuArch(siSysInfo.wProcessorArchitecture) + "\n";

	strDWord.Format("%d", siSysInfo.dwProcessorType);
	strResult += "CPU Type: " + strDWord + "\n";

	strDWord.Format("%d", siSysInfo.wProcessorLevel);
	strResult += "CPU Level: " + strDWord + "\n";

	strDWord.Format("%d", siSysInfo.wProcessorRevision);
	strResult += "CPU Rev: " + strDWord + "\n";

	strDWord.Format("%d", siSysInfo.dwActiveProcessorMask);
	strResult += "CPU Mask: " + strDWord + "\n";
	
	strResult += "\nSoftware information:\n";

	strDWord.Format("%d", siSysInfo.dwOemId);
	strResult += "OEM ID: " + strDWord + "\n";

	strResult += "OS Version: " + GetOsInfo(siOSInfo.dwMajorVersion, siOSInfo.dwMinorVersion) + "\n";

	strDWord.Format("%d", siOSInfo.dwBuildNumber);
	strResult += "OS Build: " + strDWord + "\n";

	return strResult;	
}

CString SysInfo::GetCpuArch(int sysCpuArch){
	CString strResult;

	switch(sysCpuArch){
		case ARCHITECTURE_INTEL:
			strResult = "Intel";
			break;
		case ARCHITECTURE_MIPS:
			strResult = "MIPS";
			break;
		case ARCHITECTURE_ALPHA:
			strResult = "ALPHA";
			break;
		case ARCHITECTURE_PPC:
			strResult = "PPC";
			break;
		case ARCHITECTURE_SHX:
			strResult = "SHX";
			break;
		case ARCHITECTURE_ARM:
			strResult = "ARM";
			break;
		case ARCHITECTURE_IA64:
			strResult = "IA64";
			break;
		case ARCHITECTURE_ALPHA64:
			strResult = "ALPHA64";
			break;
		case ARCHITECTURE_MSIL:
			strResult = "MSIL";
			break;
		case ARCHITECTURE_AMD64:
			strResult = "AMD64";
			break;
		case ARCHITECTURE_IA32_ON_WIN64:
			strResult = "IA32_ON_WIN64";
			break;
	}

	return strResult;	
}

CString SysInfo::GetOsInfo(int osMajor, int osMinor){
	CString strResult;

	if(osMajor==4){
		if(osMinor==0){strResult="Windows 95";}
		else if(osMinor==10){strResult="Windows 98";}
		else if(osMinor==90){strResult="Windows ME";}
		else{strResult="Unknown";}
	}
	else if(osMajor==5){
		if(osMinor==0){strResult="Windows 2000";}
		else if(osMinor==1){strResult="Windows XP";}
		else if(osMinor==2){strResult="Windows XP x64";}
		else{strResult="Unknown";}
	}
	else if(osMajor==6){
		if(osMinor==0){strResult="Windows Vista";}
		else if(osMinor==1){strResult="Windows 7";}
		else if(osMinor==2){strResult="Windows 8";}
		else if(osMinor==3){strResult="Windows 8.1";}
		else{strResult="Unknown";}
	}
	else if(osMajor==10){
		if(osMinor==0){strResult="Windows 10";}
		else{strResult="Unknown";}
	}
	else{strResult="Unknown";}

	return strResult;
}

