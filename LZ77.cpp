#include "LZ77.h"

/*  Class call
    LZ77 lz77(text,1);
    lz77.encode();
    lz77.decode();
 */

LZ77::LZ77(string raw_string, int debug){
    text = raw_string;
    debug_mode = debug;
}

void printDeque(deque<char> d){
    auto it = d.begin();
    cout<<endl;
    while(it!=d.end()){
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}

void LZ77::encode(){
    int textPointer;

    // insert the first elements in lookAheadBuffer
    for(int i=0;i<lookAheadBufferLength;i++){
        lookAheadBuffer.push_back(text[i]);
    }

    // After pushing the first few characters in the look ahead buffer
    // the text pointer will now have a value of
    textPointer = lookAheadBufferLength-1;

    deque<char>::iterator searchIt,lookAheadIt,tempIt;

    while(!lookAheadBuffer.empty()){

        int length=0, tempLength,offset=0;

        //search for the longest pattern
        for(searchIt=searchBuffer.begin();searchIt!=searchBuffer.end();searchIt++){
            tempLength = 0;
            lookAheadIt = lookAheadBuffer.begin();
            tempIt = searchIt;
            while(tempIt!=searchBuffer.end() && lookAheadIt!=lookAheadBuffer.end() && *tempIt==*lookAheadIt){
                tempIt++;
                lookAheadIt++;
                tempLength++;
            }
            if(tempLength > length){
                length = tempLength;
                offset = searchBuffer.end() - searchIt;
            }
        }

        if(length>0){
            for(int i=0;i<=length;i++){
                if(i==length) {
                    cout << "(" << offset << "," << length << "," << *lookAheadBuffer.begin() << ") ";
                    encodedData.push_back({offset,length,*lookAheadBuffer.begin()});
                }

                if(searchBuffer.size()==searchBufferLength)
                    searchBuffer.pop_front();
                searchBuffer.push_back(*lookAheadBuffer.begin());

                lookAheadBuffer.pop_front();
                if(textPointer<text.size())
                    lookAheadBuffer.push_back(text[++textPointer]);
            }

        }
        else{
            cout<<"("<<offset<<","<<length<<","<<*lookAheadBuffer.begin()<<") ";
            encodedData.push_back({offset,length,*lookAheadBuffer.begin()});

            if(searchBuffer.size()==searchBufferLength)
                searchBuffer.pop_front();
            searchBuffer.push_back(*lookAheadBuffer.begin());

            lookAheadBuffer.pop_front();
            if(textPointer<text.size())
                lookAheadBuffer.push_back(text[++textPointer]);
        }

    }
}


void LZ77::decode() {
    string decodedMessage="";

    for(int i=0;i<encodedData.size()-1;i++){
        int index=decodedMessage.size()-encodedData[i].offset;
        //cout<<"\n"<<encodedData[i].offset<<","<<encodedData[i].length<<","<<encodedData[i].symbol<<endl;
        for(int j=0;j<encodedData[i].length;j++){
            decodedMessage+=decodedMessage[index++];
        }
        decodedMessage+=encodedData[i].symbol;
    }

    cout<<decodedMessage<<endl;

}