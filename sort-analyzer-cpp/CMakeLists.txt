cmake_minimum_required(VERSION 3.30)
project(sort_analyzer_cpp)

set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(.)
include_directories(data)
include_directories(headers)
include_directories(src)
include_directories(tests)

# Source files (only .h and .cpp)
set(SOURCE_FILES
        src/Main.cpp
        headers/AlgorithmComparison.h
        headers/BubbleSort.h
        headers/HeapSort.h
        headers/InsertionSort.h
        headers/MenuManager.h
        headers/MergeSort.h
        headers/QuickSort.h
        headers/SelectionSort.h
        headers/SortAlgorithm.h
        headers/DatabaseManager.h
        headers/ConsoleUtils.h
        src/AlgorithmComparision.cpp
        src/BubbleSort.cpp
        src/HeapSort.cpp
        src/InsertionSort.cpp
        src/MenuManager.cpp
        src/MergeSort.cpp
        src/QuickSort.cpp
        src/SelectionSort.cpp
        src/DatabaseManager.cpp
        src/ConsoleUtils.cpp
)

# Create executable
add_executable(sort_analyzer_cpp ${SOURCE_FILES})

# SQLite3 library
add_library(sqlite3 STATIC external/sqlite/sqlite3.c)
target_include_directories(sqlite3 PUBLIC external/sqlite)
target_link_libraries(sort_analyzer_cpp PRIVATE sqlite3)