# Makefile for MinGW compilation

##########################################################
# Executable Name
EXES				= FuzzySim.exe

##########################################################
# Settings

SRCDIR				= .
SUBDIRS				=
DLLS				=
LIBS				=
C_FILES				=
CXX_FILES			= ../main.cpp ../my_fuzzy.cpp

CEXTRA				= -m32 -static-libgcc
CXXEXTRA			= -m32 -static-libgcc -std=c++11
RCEXTRA				=
DEFINES				=
INCLUDE_PATH		= -I.
DLL_PATH			=
DLL_IMPORTS			=
LIBRARY_PATH		=
LIBRARIES			= -luser32
S_LIBRARIES			= -lstdc++ -lpthread

EXE_C_SRCS			= $(C_FILES)
EXE_CXX_SRCS		= $(CXX_FILES)
EXE_MODULE			= $(EXES)
EXE_RC_SRCS			=
EXE_LDFLAGS			= -m32 -static-libgcc -std=c++11
EXE_ARFLAGS			=
EXE_DLL_PATH		=
EXE_DLLS			= odbc32 ole32 oleaut32 winspool odbccp32
EXE_LIBRARY_PATH	=
EXE_LIBRARIES		= uuid
EXE_OBJS			= $(EXE_C_SRCS:.c=.o) $(EXE_CXX_SRCS:.cpp=.o) $(EXE_RC_SRCS:.rc=.res)

C_SRCS				= $(EXE_C_SRCS)
CXX_SRCS			= $(EXE_CXX_SRCS)
RC_SRCS				= $(EXE_RC_SRCS)

CC					= i686-w64-mingw32-gcc
CXX					= i686-w64-mingw32-g++
RC					= i686-w64-mingw32-windres
AR					= i686-w64-mingw32-ar

##########################################################
# Compilation

all: $(SUBDIRS) $(DLLS:%=%.so) $(LIBS) $(EXES)

##########################################################

.PHONY: all clean dummy

$(SUBDIRS): dummy
	@cd $@ && $(MAKE)

.SUFFIXES: .cpp .cxx .rc .res
DEFINCL = $(INCLUDE_PATH) $(DEFINES) $(OPTIONS)

.c.o:
	$(CC) -c $(CFLAGS) $(CEXTRA) $(DEFINCL) -o $@ $<

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(CXXEXTRA) $(DEFINCL) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(CXXEXTRA) $(DEFINCL) -o $@ $<

.rc.res:
	$(RC) $(RCFLAGS) $(RCEXTRA) $(DEFINCL) -fo$@ $<

##########################################################

CLEAN_FILES     = y.tab.c y.tab.h lex.yy.c core *.orig *.rej \
                  \\\#*\\\# *~ *% .\\\#*

clean:: $(SUBDIRS:%=%/__clean__) $(EXTRASUBDIRS:%=%/__clean__)
	$(RM) $(CLEAN_FILES) $(RC_SRCS:.rc=.res) $(C_SRCS:.c=.o) $(CXX_SRCS:.cpp=.o)
	$(RM) $(DLLS:%=%.so) $(LIBS) $(EXES) $(EXES:%=%.so)

$(SUBDIRS:%=%/__clean__): dummy
	cd `dirname $@` && $(MAKE) clean

$(EXTRASUBDIRS:%=%/__clean__): dummy
	-cd `dirname $@` && $(RM) $(CLEAN_FILES)

##########################################################

DEFLIB = $(LIBRARY_PATH) $(LIBRARIES) $(DLL_PATH) $(DLL_IMPORTS:%=-l%)

$(EXE_MODULE): $(EXE_OBJS)
	$(CXX) $(EXE_LDFLAGS) -o $@ $(EXE_OBJS) $(EXE_LIBRARY_PATH) $(EXE_DLL_PATH) $(DEFLIB) $(EXE_DLLS:%=-l%) $(EXE_LIBRARIES:%=-l%)  -Wl,-Bstatic $(S_LIBRARIES)
