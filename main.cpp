#include<iostream>
#include<fstream>
//#include "rle.h"
//#include "huffman.h"
#include "LZ78.h"

using namespace std;

string readTextFile(){
    ifstream inFile;
    string line;
    char addr[100];
    cout<<"\nEnter File Address : ";
    gets(addr);

    inFile.open(addr);

    while(inFile){
        getline(inFile, line);
    }
    inFile.close();
    return line;
}

void writeTextFile(string text){
    ofstream file;
    char fileName[100];
    cout<<"\nEnter file address : ";
    gets(fileName);
    file.open(fileName);
    file<<text;
    file.close();
}

int main() {

    string text;

    /**text=readTextFile();
    cout<<text<<endl;**/

    text="abababcbababaa";

    LZ78 compressor(text, 0);

    compressor.encode();

    compressor.decode();


    /** For RLE
    RLE rle(text);

    cout<<"\nEncoded String : "<<endl;
    string encoded_text=rle.encode();
    cout<<"\n\nDecoded String : "<<endl;
    rle.decode(encoded_text);
    **/


    /**For huffman

    huffman compressor(text,1);

    string compressedBinary=compressor.encode();

    cout<<"\nAfter decoding : \n";
    cout<<compressor.decode(compressedBinary);

     **/

    return 0;
}


