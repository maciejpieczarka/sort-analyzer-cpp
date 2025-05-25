cmake_minimum_required(VERSION 3.30)
project(sort_analyzer_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(data)
include_directories(headers)
include_directories(src)
include_directories(tests)

add_executable(sort_analyzer_cpp
    data/data.txt
    data/Tablica10.txt
    data/wyniki.txt
    headers/AlgorithmComparison.h
    headers/BubbleSort.h
    headers/HeapSort.h
    headers/InsertionSort.h
    headers/MenuManager.h
    headers/MergeSort.h
    headers/QuickSort.h
    headers/SelectionSort.h
    headers/SortAlgorithm.h
    src/AlgorithmComparision.cpp
    src/BubbleSort.cpp
    src/HeapSort.cpp
    src/InsertionSort.cpp
    src/Main.cpp
    src/MenuManager.cpp
    src/MergeSort.cpp
    src/QuickSort.cpp
    src/SelectionSort.cpp
    tests/data/smallArray.txt
        headers/ConsoleUtils.h
        src/ConsoleUtils.cpp)
