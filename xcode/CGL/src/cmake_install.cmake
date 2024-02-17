# Install script for directory: /Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

set(CMAKE_BINARY_DIR "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/xcode")

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/xcode/CGL/src/Debug/libCGL.a")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCGL.a" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCGL.a")
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCGL.a")
    endif()
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/xcode/CGL/src/Release/libCGL.a")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCGL.a" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCGL.a")
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCGL.a")
    endif()
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/xcode/CGL/src/MinSizeRel/libCGL.a")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCGL.a" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCGL.a")
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCGL.a")
    endif()
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/xcode/CGL/src/RelWithDebInfo/libCGL.a")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCGL.a" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCGL.a")
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCGL.a")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/xcode/CGL/src/CMakeFiles/CGL.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/xcode/CGL/src/CMakeFiles/CGL.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    include("/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/xcode/CGL/src/CMakeFiles/CGL.dir/install-cxx-module-bmi-MinSizeRel.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    include("/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/xcode/CGL/src/CMakeFiles/CGL.dir/install-cxx-module-bmi-RelWithDebInfo.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/CGL" TYPE FILE FILES
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/CGL.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/vector2D.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/vector3D.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/vector4D.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/matrix3x3.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/matrix4x4.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/quaternion.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/complex.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/color.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/osdtext.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/viewer.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/base64.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/tinyxml2.h"
    "/Users/sueshim/Desktop/cs184/hw2-meshedit-sp24-sueyoungshim/CGL/src/renderer.h"
    )
endif()

