# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/hakanvardar/Programming/C++/Hydro/build/_deps/glfw-src"
  "/Users/hakanvardar/Programming/C++/Hydro/build/_deps/glfw-build"
  "/Users/hakanvardar/Programming/C++/Hydro/build/_deps/glfw-subbuild/glfw-populate-prefix"
  "/Users/hakanvardar/Programming/C++/Hydro/build/_deps/glfw-subbuild/glfw-populate-prefix/tmp"
  "/Users/hakanvardar/Programming/C++/Hydro/build/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp"
  "/Users/hakanvardar/Programming/C++/Hydro/build/_deps/glfw-subbuild/glfw-populate-prefix/src"
  "/Users/hakanvardar/Programming/C++/Hydro/build/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/hakanvardar/Programming/C++/Hydro/build/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/hakanvardar/Programming/C++/Hydro/build/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
