#include<iostream>
#include<fstream>
//#include "rle.h"
//#include "huffman.h"
//#include "LZ78.h"
#include "LZ77.h"

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


int on_extract_entry(const char *filename, void *arg) {
    static int i = 0;
    int n = *(int *)arg;
    printf("Extracted: %s (%d of %d)\n", filename, ++i, n);

    return 0;
}


int main() {
    string text;

    text=readTextFile();
    cout<<"Original String : "<<text<<endl;

    //class call code here...
    LZ77 lz77(text,1);
    lz77.encode();
    cout<<"\nDecoded string:"<<endl;
    lz77.decode();
    return 0;
}


