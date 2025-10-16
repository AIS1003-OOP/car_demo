cmake_minimum_required(VERSION 3.19)
project(soc_demo)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
set(THREEPP_BUILD_TESTS OFF)
set(THREEPP_BUILD_EXAMPLES OFF)
FetchContent_Declare(
        threepp
        GIT_REPOSITORY https://github.com/markaren/threepp.git
        GIT_TAG 619cdaacc2e7dc6ea709d8c7f482e2994af7349d
)
FetchContent_MakeAvailable(threepp)

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.11.0
)
FetchContent_MakeAvailable(catch2)

enable_testing()
add_subdirectory(tests)

add_executable(soc_demo main.cpp)
target_link_libraries(soc_demo PUBLIC threepp::threepp)
target_include_directories(soc_demo PUBLIC "include")

