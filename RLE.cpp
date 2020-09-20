#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
#include<cstdlib>

#include "rle.h"


using namespace std;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}



void getFileSize(){
   ifstream in_file("test.txt", ios::binary);
   in_file.seekg(0, ios::end);
   int file_size = in_file.tellg();
   cout<<"Size of the file is"<<" "<< file_size<<" "<<"bytes";
   in_file.close();
}

void RLE(string sample){
    stringstream ss;
    string newString="";
    char currentLetter=sample[0];
    int letterNum=1,i=1, len=sample.length();


    while(i<len){
        if(sample[i]==currentLetter){
            letterNum++;
            i++;
        }
        else{

            newString+=currentLetter+patch::to_string(letterNum);
            currentLetter=sample[i];
            letterNum=1;
            i++;
        }

    }
    cout<<newString;
    saveFile(newString);

}

//Doesn't work when frequency is more than 1 digit!

void decodeRLE(string text){
    string decodedText="";
    int index=0,len=text.length(),freq;
    while(index<len){
        freq=text[index+1]-48;

        for(int i=0;i<freq;i++){
            decodedText+=text[index];
        }
        index+=2;
    }
    cout<<decodedText;
    saveFile(decodedText);


}

void saveFile(string text){
    ofstream outFile("encoded.txt");
    outFile<<text;
    outFile.close();
}

void mainCode(){
        string text="",line;
    ifstream inFile;
    inFile.open("encoded.txt");

    while(!inFile.eof()){
        getline(inFile,line);
        text+=line+"\n";
    }
    cout<<text<<endl;

    decodeRLE(text);
    cout<<endl;
    cout<<"Compression done!";

    inFile.close();
}
