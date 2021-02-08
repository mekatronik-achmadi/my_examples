##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased
##
## Release
ProjectName            :=wxSerTerm
ConfigurationName      :=Release
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=./
ProjectPath            :=./
IntermediateDirectory  :=./build-$(ConfigurationName)/
OutDir                 :=./build-$(ConfigurationName)/
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=
CodeLitePath           :=~/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c
OutputFile             :=./build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)__WX__ $(PreprocessorSwitch)NDEBUG
ObjectSwitch           :=-o
ArchiveOutputSwitch    :=
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=   $(shell wx-config-gtk3 --debug=no --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/usr/include/wx-3.0
IncludePCH             :=
RcIncludePath          :=
Libs                   :=
ArLibs                 :=
LibPath                := $(LibraryPathSwitch).

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O2 -Wall $(shell wx-config-gtk3 --cxxflags --unicode=yes --debug=no) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(shell wx-config-gtk3 --cxxflags --unicode=yes --debug=no) $(Preprocessors)
ASFLAGS  :=
AS       := /usr/bin/as


##
## User defined environment variables
##
Objects0=./build-$(ConfigurationName)//main.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//gui.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//ceSerial.cpp$(ObjectSuffix)



Objects=$(Objects0)

##
## Main Build Targets
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ./build-$(ConfigurationName)//.d $(Objects)
	@mkdir -p "./build-$(ConfigurationName)/"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "./build-$(ConfigurationName)/"
	@mkdir -p ""./build-$(ConfigurationName)/bin""

./build-$(ConfigurationName)//.d:
	@mkdir -p "./build-$(ConfigurationName)/"

PreBuild:


##
## Objects
##
./build-$(ConfigurationName)//main.cpp$(ObjectSuffix): main.cpp ./build-$(ConfigurationName)//main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//main.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//main.cpp$(DependSuffix) -MM main.cpp

./build-$(ConfigurationName)//main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//main.cpp$(PreprocessSuffix) main.cpp

./build-$(ConfigurationName)//gui.cpp$(ObjectSuffix): gui.cpp ./build-$(ConfigurationName)//gui.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "gui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//gui.cpp$(DependSuffix): gui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//gui.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//gui.cpp$(DependSuffix) -MM gui.cpp

./build-$(ConfigurationName)//gui.cpp$(PreprocessSuffix): gui.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//gui.cpp$(PreprocessSuffix) gui.cpp

./build-$(ConfigurationName)//ceSerial.cpp$(ObjectSuffix): ceSerial.cpp ./build-$(ConfigurationName)//ceSerial.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "ceSerial.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ceSerial.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//ceSerial.cpp$(DependSuffix): ceSerial.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//ceSerial.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//ceSerial.cpp$(DependSuffix) -MM ceSerial.cpp

./build-$(ConfigurationName)//ceSerial.cpp$(PreprocessSuffix): ceSerial.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//ceSerial.cpp$(PreprocessSuffix) ceSerial.cpp


-include ./build-$(ConfigurationName)///*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


