#!/bin/bash

#######################

doxyfile_config() {
	sed -i "s#PROJECT_NAME           = \"My Project\"#PROJECT_NAME           = \"$1\"#g" doxyconf
	sed -i "s#OUTPUT_DIRECTORY       =#OUTPUT_DIRECTORY       = ./doxydoc#g" doxyconf

	sed -i "s#OPTIMIZE_OUTPUT_FOR_C  = NO#OPTIMIZE_OUTPUT_FOR_C  = YES#g" doxyconf
	sed -i "s#ALWAYS_DETAILED_SEC    = NO#ALWAYS_DETAILED_SEC    = YES#g" doxyconf
	sed -i "s#EXTRACT_ALL            = NO#EXTRACT_ALL            = YES#g" doxyconf
	sed -i "s#EXTRACT_PRIVATE        = NO#EXTRACT_PRIVATE        = YES#g" doxyconf
	sed -i "s#EXTRACT_STATIC         = NO#EXTRACT_STATIC         = YES#g" doxyconf
	sed -i "s#EXTRACT_LOCAL_CLASSES  = NO#EXTRACT_LOCAL_CLASSES  = YES#g" doxyconf
	sed -i "s#HIDE_UNDOC_MEMBERS     = NO#HIDE_UNDOC_MEMBERS     = YES#g" doxyconf
	sed -i "s#HIDE_UNDOC_CLASSES     = NO#HIDE_UNDOC_CLASSES     = YES#g" doxyconf
	sed -i "s#HAVE_DOT               = NO#HAVE_DOT               = YES#g" doxyconf
	sed -i "s#UML_LOOK               = NO#UML_LOOK               = YES#g" doxyconf
	sed -i "s#CALL_GRAPH             = NO#CALL_GRAPH             = YES#g" doxyconf
	sed -i "s#CALLER_GRAPH           = NO#CALLER_GRAPH           = YES#g" doxyconf
	sed -i "s#CLASS_DIAGRAMS         = NO#CLASS_DIAGRAMS         = YES#g" doxyconf
	sed -i "s#DOT_TRANSPARENT        = NO#DOT_TRANSPARENT        = YES#g" doxyconf
	sed -i "s#DOT_MULTI_TARGETS      = NO#DOT_MULTI_TARGETS      = YES#g" doxyconf
	sed -i "s#INCLUDE_GRAPH          = NO#INCLUDE_GRAPH          = YES#g" doxyconf
	sed -i "s#INCLUDED_BY_GRAPH      = NO#INCLUDED_BY_GRAPH      = YES#g" doxyconf
	sed -i "s#DIRECTORY_GRAPH        = NO#DIRECTORY_GRAPH        = YES#g" doxyconf
	sed -i "s#SOURCE_BROWSER         = NO#SOURCE_BROWSER         = YES#g" doxyconf
	sed -i "s#GENERATE_TREEVIEW      = NO#GENERATE_TREEVIEW      = YES#g" doxyconf
	sed -i "s#STRIP_CODE_COMMENTS    = NO#STRIP_CODE_COMMENTS    = YES#g" doxyconf
	sed -i "s#CASE_SENSE_NAMES       = NO#CASE_SENSE_NAMES       = YES#g" doxyconf
	sed -i "s#WARN_NO_PARAMDOC       = NO#WARN_NO_PARAMDOC       = YES#g" doxyconf
	sed -i "s#REFERENCED_BY_RELATION = NO#REFERENCED_BY_RELATION = YES#g" doxyconf
	sed -i "s#REFERENCES_RELATION    = NO#REFERENCES_RELATION    = YES#g" doxyconf
	sed -i "s#ENABLE_PREPROCESSING   = NO#ENABLE_PREPROCESSING   = YES#g" doxyconf
	sed -i "s#MACRO_EXPANSION        = NO#MACRO_EXPANSION        = YES#g" doxyconf
	sed -i "s#EXPAND_ONLY_PREDEF     = NO#EXPAND_ONLY_PREDEF     = YES#g" doxyconf
	sed -i "s#HTML_TIMESTAMP         = NO#HTML_TIMESTAMP         = YES#g" doxyconf
	sed -i "s#SEARCHENGINE           = NO#SEARCHENGINE           = YES#g" doxyconf

	sed -i "s#VERBATIM_HEADERS       = YES#VERBATIM_HEADERS       = NO#g" doxyconf
	sed -i "s#GENERATE_LATEX         = YES#GENERATE_LATEX         = NO#g" doxyconf
	sed -i "s#GENERATE_RTF           = YES#GENERATE_RTF           = NO#g" doxyconf
	sed -i "s#FULL_PATH_NAMES        = YES#FULL_PATH_NAMES        = NO#g" doxyconf
	sed -i "s#INHERIT_DOCS           = YES#INHERIT_DOCS           = NO#g" doxyconf
	sed -i "s#SORT_MEMBER_DOCS       = YES#SORT_MEMBER_DOCS       = NO#g" doxyconf
	sed -i "s#REFERENCES_LINK_SOURCE = YES#REFERENCES_LINK_SOURCE = NO#g" doxyconf
	sed -i "s#ALPHABETICAL_INDEX     = YES#ALPHABETICAL_INDEX     = NO#g" doxyconf
	sed -i "s#SKIP_FUNCTION_MACROS   = YES#SKIP_FUNCTION_MACROS   = NO#g" doxyconf

	sed -i "s=CLANG_ASSISTED_PARSING=#CLANG_DISABLED_AT_COMPILE=g" doxyconf
	sed -i "s=CLANG_OPTIONS=#CLANG_DISABLED_AT_COMPILE=g" doxyconf

	sed -i "s#DOT_FONTSIZE           = 10#DOT_FONTSIZE           = 8#g" doxyconf
	sed -i "s#MAX_DOT_GRAPH_DEPTH    = 0#MAX_DOT_GRAPH_DEPTH    = 2#g" doxyconf
}

#######################

if [ ! -f /usr/bin/doxygen ]; then
    echo "doxygen not found"
    exit
fi

if [ ! -f /usr/bin/dot ]; then
	echo "graphviz not found"
    exit
fi

if [ -d doxydoc ]; then
	echo "doxydoc exist and may not empty"
    exit
fi

if [ -z "${1}" ];then
	echo "specify project name"
	exit
fi

#######################

echo "starting build documents"

doxygen -g doxyconf > /dev/null 2>&1
doxyfile_config

mkdir doxydoc
doxygen doxyconf > /dev/null 2>&1
ln -sf html/index.html doxydoc/index.html

rm -f doxyconf
rm -f doxyconf.bak

echo "build documents completed"


