cmake_minimum_required(VERSION 3.0)
project(nedit-regex-test CXX)

add_executable(nedit-regex-test
	Test.cpp
)

target_link_libraries(nedit-regex-test
	Regex
)

if(NEDIT_INCLUDE_DECOMPILER)
	target_compile_definitions(nedit-regex-test -DNEDIT_INCLUDE_DECOMPILER)
endif()

set_property(TARGET nedit-regex-test PROPERTY RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set_property(TARGET nedit-regex-test PROPERTY CXX_STANDARD 17)

add_test(
	NAME nedit-regex-test
	COMMAND $<TARGET_FILE:nedit-regex-test>
)
