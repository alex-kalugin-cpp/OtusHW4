cmake_minimum_required(VERSION 3.2)
if ($ENV{TRAVIS_BUILD_NUMBER})
    project(print_ip VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(print_ip VERSION 0.0.1)
endif()
add_executable(print_ip main.cpp)
target_include_directories(print_ip PRIVATE ${PROJECT_SOURCE_DIR})
set_target_properties(print_ip PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON

)
if (MSVC)
    target_compile_options(print_ip PRIVATE
        /W4
    )
else ()
    target_compile_options(print_ip PRIVATE
        -Wall -Wextra -pedantic
        #-Werror
    )
endif()
install(TARGETS print_ip RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
#find_package(GTest REQUIRED)

enable_testing()
add_executable(gtest_hw4 tests/gtests.cpp)
#target_link_libraries(gtest_hw4 GTest::Main)
target_link_libraries(gtest_hw4 gtest_main)
target_include_directories(gtest_hw4 PRIVATE ${PROJECT_SOURCE_DIR})
set_property(TARGET gtest_hw4 PROPERTY CXX_STANDARD 14)
