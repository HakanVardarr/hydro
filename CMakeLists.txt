cmake_minimum_required(VERSION 3.22)
project(hydro)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(FETCHCONTENT_QUIET NO)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/vendor
)
file(GLOB CORE_SOURCE ${CMAKE_SOURCE_DIR}/src/Core/*.cc)
file(GLOB GRAPHICS_SOURCE ${CMAKE_SOURCE_DIR}/src/Graphics/*.cc)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG        master
)

FetchContent_MakeAvailable(glfw)
FetchContent_GetProperties(glfw)
if (NOT glfw_POPULATED) 
    FetchContent_Populate(glfw)

    set(GLFW_BUILD_EXAMPLES OFF)
    set(GLFW_BUILD_TESTS OFF)

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

FetchContent_Declare(
    spdlog
	GIT_REPOSITORY https://github.com/gabime/spdlog.git
	GIT_TAG v1.x
)

FetchContent_MakeAvailable(spdlog)
FetchContent_GetProperties(spdlog)
if (NOT spdlog_POPULATED) 
    FetchContent_Populate(spdlog)


    add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR})
endif()

add_executable(${PROJECT_NAME} main.cc ${CORE_SOURCE} ${GRAPHICS_SOURCE} ${CMAKE_SOURCE_DIR}/vendor/glad.c)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw spdlog)