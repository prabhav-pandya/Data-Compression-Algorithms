#ifndef DATA_COMPRESSION_LZ77_H
#define DATA_COMPRESSION_LZ77_H
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

#define searchBufferLength 7
#define lookAheadBufferLength 5

using namespace std;

typedef struct triple{
    int offset;
    int length;
    char symbol;
} triple;

class LZ77 {
    string text;
    int debug_mode;
    deque<char> searchBuffer;
    deque<char> lookAheadBuffer;
    vector<triple> encodedData;
public:
    LZ77(string raw_string, int debug);
    void encode();
    void decode();
};


#endif //DATA_COMPRESSION_LZ77_H
