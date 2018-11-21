/**
 * @file    sysinfo.c
 * @brief   Win32 System Info code
 *
 * @addtogroup SYS_INFO
 * @{
 */

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include "sysinfo.h"

void ExePathInfo(char* str_var){
	char exename[MAX_PATH];
	HINSTANCE hinst = GetModuleHandle(NULL);

	GetModuleFileName(hinst,exename,MAX_PATH);
    sprintf(str_var,"%sEXE path: \n%s\n",str_var,exename);
}

void HardInfo(char* str_var){
	OSVERSIONINFO siOSInfo;
	siOSInfo.dwOSVersionInfoSize = sizeof(siOSInfo);

	SYSTEM_INFO siSysInfo;
    char strTemp[32];

    TCHAR siCompName[INFO_BUFFER_SIZE];
    TCHAR siUserName[INFO_BUFFER_SIZE];
    TCHAR siWinDir[INFO_BUFFER_SIZE];
    TCHAR siSysDir[INFO_BUFFER_SIZE];
    TCHAR siEnVar[INFO_BUFFER_SIZE];
    DWORD bufCharCount = INFO_BUFFER_SIZE;
    DWORD envarCharCount = 2*INFO_BUFFER_SIZE;

    MEMORYSTATUSEX siMemInfo;
    siMemInfo.dwLength = sizeof(siMemInfo);

	GetVersionEx(&siOSInfo);
	GetSystemInfo(&siSysInfo);
    GlobalMemoryStatusEx(&siMemInfo);
    GetComputerName(siCompName,&bufCharCount);
    GetUserName(siUserName,&bufCharCount);
    GetSystemDirectory(siSysDir,INFO_BUFFER_SIZE);
    GetWindowsDirectory(siWinDir,INFO_BUFFER_SIZE);

	sprintf(str_var,"%s\nHardware information:\n",str_var);
	sprintf(str_var,"%sCPU Number: %d\n",str_var,siSysInfo.dwNumberOfProcessors);

	GetCpuArch(strTemp,siSysInfo.wProcessorArchitecture);
	sprintf(str_var,"%sCPU Arch: %s\n",str_var,strTemp);

	GetCpuType(strTemp,siSysInfo.dwProcessorType);
	sprintf(str_var,"%sCPU Type: %s\n",str_var,strTemp);

	sprintf(str_var,"%sCPU Level: %d\n",str_var,siSysInfo.wProcessorLevel);
	sprintf(str_var,"%sCPU Rev: %d\n",str_var,siSysInfo.wProcessorRevision);
    sprintf(str_var,"%sCPU Mask: %d\n",str_var,siSysInfo.dwActiveProcessorMask);

    sprintf(str_var,"%sMEM Total: %d MB\n",str_var,siMemInfo.ullTotalPhys/DIV);
    sprintf(str_var,"%sMEM Free: %d MB\n",str_var,siMemInfo.ullAvailPhys/DIV);
    sprintf(str_var,"%sMEM Load: %d%%\n",str_var,siMemInfo.dwMemoryLoad);

    GetKeyType(strTemp,GetKeyboardType(0));
    sprintf(str_var,"%sKeyboard Type: %s\n",str_var,strTemp);

	sprintf(str_var,"%s\nSoftware information:\n",str_var);
	sprintf(str_var,"%sOEM ID: %d\n",str_var,siSysInfo.dwOemId);

	GetOsInfo(strTemp,siOSInfo.dwMajorVersion, siOSInfo.dwMinorVersion);
	sprintf(str_var,"%sOS Version: %s\n",str_var,strTemp);

	sprintf(str_var,"%sOS Build: %d\n",str_var,siOSInfo.dwBuildNumber);

    sprintf(str_var,"%s\nComputer information:\n",str_var);
    sprintf(str_var,"%sComp Name: %s\n",str_var,siCompName);
    sprintf(str_var,"%sUser Name: %s\n",str_var,siUserName);
    sprintf(str_var,"%sSys Dir: %s\n",str_var,siSysDir);
    sprintf(str_var,"%sWin Dir: %s\n",str_var,siWinDir);

    sprintf(str_var,"%s\nEnVar information:\n",str_var);

    GetEnvironmentVariable("HOMEPATH", siEnVar, envarCharCount);
    sprintf(str_var,"%sHOMEPATH= %s\n",str_var,siEnVar);

    GetEnvironmentVariable("PATH", siEnVar, envarCharCount);
    sprintf(str_var,"%sPATH= %s\n",str_var,siEnVar);

    GetEnvironmentVariable("TEMP", siEnVar, envarCharCount);
    sprintf(str_var,"%sTEMP= %s\n",str_var,siEnVar);

    GetEnvironmentVariable("OS", siEnVar, envarCharCount);
    sprintf(str_var,"%sOS= %s\n",str_var,siEnVar);
}

void GetCpuArch(char* str_var, int sysCpuArch){
	char strResult[32];

	switch(sysCpuArch){
		case ARCHITECTURE_INTEL:
			sprintf(strResult,"Intel");
			break;
		case ARCHITECTURE_MIPS:
			sprintf(strResult,"MIPS");
			break;
		case ARCHITECTURE_ALPHA:
			sprintf(strResult,"ALPHA");
			break;
		case ARCHITECTURE_PPC:
			sprintf(strResult,"PPC");
			break;
		case ARCHITECTURE_SHX:
			sprintf(strResult,"SHX");
			break;
		case ARCHITECTURE_ARM:
			sprintf(strResult,"ARM");
			break;
		case ARCHITECTURE_IA64:
			sprintf(strResult,"IA64");
			break;
		case ARCHITECTURE_ALPHA64:
			sprintf(strResult,"ALPHA64");
			break;
		case ARCHITECTURE_MSIL:
			sprintf(strResult,"MSIL");
			break;
		case ARCHITECTURE_AMD64:
			sprintf(strResult,"AMD64");
			break;
		case ARCHITECTURE_IA32_ON_WIN64:
			sprintf(strResult,"IA32_ON_WIN64");
			break;
		default:
			sprintf(strResult,"%d",sysCpuArch);
	}

	sprintf(str_var,"%s",strResult);
}

void GetCpuType(char* str_var, int sysCpuType){
	char strResult[32];

	switch(sysCpuType){
		case CPU_INTEL_386:
			sprintf(strResult,"Intel 386");
			break;
		case CPU_INTEL_486:
			sprintf(strResult,"Intel 486");
			break;
		case CPU_INTEL_PENTIUM:
			sprintf(strResult,"Intel Pentium");
			break;
		case CPU_INTEL_IA64:
			sprintf(strResult,"Intel IA 64");
			break;
		case CPU_AMD_X8664:
			sprintf(strResult,"AMD x86_64");
			break;
		default:
			sprintf(strResult,"%d",sysCpuType);
	}

	sprintf(str_var,"%s",strResult);
}

void GetOsInfo(char* str_var, int osMajor, int osMinor){
	char strResult[32];

	if(osMajor==4){
		if(osMinor==0){sprintf(strResult,"Windows 95");}
		else if(osMinor==10){sprintf(strResult,"Windows 98");}
		else if(osMinor==90){sprintf(strResult,"Windows ME");}
		else{sprintf(strResult,"Unknown");}
	}
	else if(osMajor==5){
		if(osMinor==0){sprintf(strResult,"Windows 2000");}
		else if(osMinor==1){sprintf(strResult,"Windows XP");}
		else if(osMinor==2){sprintf(strResult,"Windows XP x64");}
		else{sprintf(strResult,"Unknown");}
	}
	else if(osMajor==6){
		if(osMinor==0){sprintf(strResult,"Windows Vista");}
		else if(osMinor==1){sprintf(strResult,"Windows 7");}
		else if(osMinor==2){sprintf(strResult,"Windows 8");}
		else if(osMinor==3){sprintf(strResult,"Windows 8.1");}
		else{sprintf(strResult,"Unknown");}
	}
	else if(osMajor==10){
		if(osMinor==0){sprintf(strResult,"Windows 10");}
		else{sprintf(strResult,"Unknown");}
	}
	else{sprintf(strResult,"Unknown");}

	sprintf(str_var,"%s",strResult);
}

void GetKeyType(char* str_var, int sysKeyType){
    char strResult[32];

    switch(sysKeyType){
        case KEY_IBM_PCXT:
            sprintf(strResult,"IBM PC/XT");
            break;
        case KEY_OLIVETTI:
            sprintf(strResult,"Olivetti");
            break;
        case KEY_IBM_PCAT:
            sprintf(strResult,"IBM PC/AT");
            break;
        case KEY_IBM_ENC:
            sprintf(strResult,"IBM Enhanced");
            break;
        default:
            sprintf(strResult,"%d",sysKeyType);
    }

    sprintf(str_var,"%s",strResult);
}
/** @} */
