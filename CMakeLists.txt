cmake_minimum_required(VERSION 3.22)
project(hydro)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(FETCHCONTENT_QUIET NO)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/vendor
)
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG        228e58262e18f2ee61799bd86d0be718b1e31f9f 
    FIND_PACKAGE_ARGS NAMES glfw
)

FetchContent_MakeAvailable(glfw)
FetchContent_GetProperties(glfw)
if (NOT glfw_POPULATED) 
    FetchContent_Populate(glfw)

    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

add_executable(${PROJECT_NAME} main.cc ${SOURCES} ${CMAKE_SOURCE_DIR}/vendor/glad.c)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)