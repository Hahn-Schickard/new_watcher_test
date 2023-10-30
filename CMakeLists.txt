cmake_minimum_required(VERSION 3.13.4)

project(watcher_test CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads)

set(EXE_NAME ${PROJECT_NAME}_runner)

add_executable(${EXE_NAME}
               ${CMAKE_CURRENT_LIST_DIR}/watcher.hpp
               ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(${EXE_NAME}
                      PUBLIC
                      Threads::Threads
)

target_compile_features(${EXE_NAME}
                        PUBLIC 
                        cxx_std_17
)