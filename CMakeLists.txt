cmake_minimum_required(VERSION 3.25.0)
project(PadWrite VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_definitions(
    /D_UNICODE=1
    /DUNICODE=1
)

set(MY_EXECUTABLE_NAME "PadWrite")
set(
  SOURCE_FILES
  "./src/Common.h"
  "./src/DrawingEffect.h"
  "./src/EditableLayout.cpp"
  "./src/EditableLayout.h"
  "./src/InlineImage.cpp"
  "./src/InlineImage.h"
  "./src/PadWrite.cpp"
  "./src/PadWrite.h"
  "./src/PadWrite.manifest"
  "./src/PadWrite.rc"
  "./src/RenderTarget.cpp"
  "./src/RenderTarget.h"
  "./src/resource.h"
  "./src/TextEditor.cpp"
  "./src/TextEditor.h"
)

add_executable(${MY_EXECUTABLE_NAME} WIN32 ${SOURCE_FILES})

# Link Direct2D, DirectWrite, and Windows Imaging Component libraries
target_link_libraries(${MY_EXECUTABLE_NAME} PRIVATE
    d2d1
    dwrite
    windowscodecs
    msimg32
)
