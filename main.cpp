#include<iostream>
#include<fstream>
#include "rle.h"
#include "huffman.h"

using namespace std;



int main() {

    string text="Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s,";

    huffman compressor(text,0);

    compressor.encode();

    return 0;
}

