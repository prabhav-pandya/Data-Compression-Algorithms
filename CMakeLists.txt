cmake_minimum_required(VERSION 3.17)
project(Data_Compression)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Data_Compression
        Huffman.cpp
        huffman.h
        LZ78.cpp
        LZ78.h
        main.cpp
        RLE.cpp
        rle.h)
