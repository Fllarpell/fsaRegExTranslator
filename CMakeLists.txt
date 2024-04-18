cmake_minimum_required(VERSION 3.27)
project(fsaRegExTranslator)

set(CMAKE_CXX_STANDARD 17)

add_executable(fsaRegExTranslator main/main.cpp
        errors/ErrorHandling.cpp
        errors/ErrorHandling.h
        main/include.h
        "kleene's algorithm/KleeneAlgorithm.cpp"
        "kleene's algorithm/KleeneAlgorithm.h"
        fsa/FSA.cpp
        fsa/FSA.h
        "incoming data/InputData.cpp"
        "incoming data/InputData.h")
