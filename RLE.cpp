#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
#include<cstdlib>

#include "rle.h"


/** Call Implementation

    RLE rle(text);

    cout<<"\nEncoded String : "<<endl;
    string encoded_text=rle.encode();

    cout<<"\n\nDecoded String : "<<endl;
    rle.decode(encoded_text);
**/


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

RLE :: RLE(string raw_string){
    text=raw_string;
}

string RLE :: encode(){
    stringstream ss;
    string newString="";
    char currentLetter=text[0];
    int letterNum=1,i=1, len=text.length();


    while(i<=len){
        if(text[i]==currentLetter){
            letterNum++;
            i++;
        }
        else{
            while(letterNum>9){
                newString+=currentLetter+patch::to_string(9);
                letterNum-=9;
            }
            newString+=currentLetter+patch::to_string(letterNum);
            currentLetter=text[i];
            letterNum=1;
            i++;
        }
    }
    cout<<newString;

    return newString;
}


void RLE :: decode(string text){
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
}



