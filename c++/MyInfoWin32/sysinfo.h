/**
 * @file    sysinfo.h
 * @brief   Win32 System Info header
 *
 * @addtogroup SYS_INFO
 * @{
 */
#ifndef _SYSINFO_H_
#define _SYSINFO_H_

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

#define CPU_INTEL_386				386
#define CPU_INTEL_486				486
#define CPU_INTEL_PENTIUM			586
#define CPU_INTEL_IA64				2200
#define CPU_AMD_X8664				8664

#define KEY_IBM_PCXT    1
#define KEY_OLIVETTI    2
#define KEY_IBM_PCAT    3
#define KEY_IBM_ENC     4

#define INFO_BUFFER_SIZE    32767
#define DIV                 1048576 //to MB size
#define ENV_VAR_SIZE        3

void ExePathInfo(char* str_var);
void HardInfo(char* str_var);
void GetCpuArch(char* str_var, int sysCpuArch);
void GetCpuType(char* str_var, int sysCpuType);
void GetOsInfo(char* str_var, int osMajor, int osMinor);
void GetKeyType(char* str_var, int sysKeyType);

#endif
/** @} */
