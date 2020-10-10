#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
#include<cstdlib>
#include<cstring>
#include <bits/stdc++.h>

#include "huffman.h"

#define MAX 256


using namespace std;

//constructor
huffman :: huffman(string file_content, int debug_mode){
            text=file_content;
            debug=debug_mode;
            sizeAfterEncoding=0;
            table_index=0;
        }

//encode function
string huffman :: encode(){
    int text_length=text.size();
    cout<<"\nSize of text (raw) in bits: "<<text.size()*8<<endl;
        string uniqChars="";
    int index=0, cnt=0;
    for(int i=0; i<text_length; i++){
        if(uniqChars.find(text[i])==string::npos){
            uniqChars+=text[i];
            cnt=count(text.begin(),text.end(),text[i]);
            arr[index].freq=cnt;
            arr[index].character=text[i];
            index++;
        }
    }
    if(debug==1){
        cout<<"\nUnique Chars: "<<uniqChars<<endl;
    }

    int len=index;
    cout<<"Character Frequency: "<<endl;
    printCharFreq(arr,len);

    int n;
    Node *newNode, *temp;

    head=createNode(arr[0].freq);
    head->character=arr[0].character;
    temp=head;


    for(int i=1;i<len;i++){
        newNode=createNode(arr[i].freq);
        newNode->character=arr[i].character;
        temp->next=newNode;
        temp=temp->next;
    }

    if(debug==1){
        cout<<"\nInitial Linked List: "<<endl;
        printNodeArr(head);
        printNodeChar(head, len);

        sortNodes(head,len);
        cout<<"\nSorted Linked List: "<<endl;
        printNodeArr(head);
        printNodeChar(head, len);

        cout<<"\nArray Convergence:"<<endl;
        printNodeArr(head);
        cout<<"\n";
    }

    //Create the binary tree
    while(head->next!=NULL){
        newNode=createNode(0);
        temp=head;
        newNode->left=temp;
        newNode->right=temp->next;
        newNode->data=temp->data+(temp->next)->data;
        newNode->next=(temp->next)->next;
        head=newNode;
        if(debug==1){
            printNodeArr(head);
        }
        sortNodes(head,--len);
    }

    cout<<endl;

    cout<<"\nCharacter Codes : "<<endl;

    printCharTable(head, "");

    cout<<"\nSize after encoding (bits) : "<<sizeAfterEncoding<<endl;

    return textToBin();
}

//text to binary using CodeTable after encoding
string huffman :: textToBin(){
    string bin="";
    for(int i=0;i<text.size();i++){
        for(int j=0;j<table_index;j++){
            if(text[i]==codeTable[j].character){
                bin+=codeTable[j].code;
                break;
            }
        }
    }
    return bin;
}

//Print all the characters in the linked list
void huffman :: printNodeChar(Node *head, int len){
     Node *temp=head;
    for(int i=0;i<len;i++){
        cout<<temp->character<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
}

//Print the data in linked list
void huffman :: printNodeArr(Node *head){
    Node *temp;
    temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
}

//sort the list using bubble sort
void huffman :: sortNodes(Node *head, int len){
    Node *p, *q, *temp_left, *temp_right;
    int temp_data;
    char temp_char;
    cout<<"\n";

    for(int i=0;i<len-1;i++){

        p=head;
        q=head->next;
        for(int j=0;j<len-i-1;j++){
            if(p->data>q->data){
                    temp_data=p->data;
                    temp_char=p->character;
                    temp_left=p->left;
                    temp_right=p->right;
                    p->data=q->data;
                    p->character=q->character;
                    p->left=q->left;
                    p->right=q->right;
                    q->data=temp_data;
                    q->character=temp_char;
                    q->right=temp_right;
                    q->left=temp_left;
            }
        p=p->next;
        q=q->next;
        }
    }

}

//Print characters and their frequency
void huffman :: printCharFreq(CharFreq arr[],int len){
        for(int i=0;i<len;i++){
        cout<<arr[i].character<<" "<<arr[i].freq<<endl;
    }
}

//Function to create and return a node
Node* huffman :: createNode(int value){
    Node *node;
    node=(Node*)malloc(sizeof(Node));
    node->data=value;
    node->character=NULL;
    node->next=NULL;
    node->left=NULL;
    node->right=NULL;
    return node;
}

//Print the encoded values
void huffman :: printCharTable(Node* node, string code){
    Node *temp;
    temp=node;

    if(node->character!=NULL){
        int i=0;
        cout<<node->character<<" : "<<code<<endl;
        //Find the character frequency and calculate its bit size in the text after encoding
        while(arr[i].character!=node->character){
            i++;
        }

        codeTable[table_index].character=node->character;
        codeTable[table_index++].code=code;

        sizeAfterEncoding+=code.size()*arr[i].freq;

    }

    if(temp->right!=NULL){
    printCharTable(temp->right, code+"1");
    }
    if(temp->right!=NULL){
    printCharTable(temp->left, code+"0");
    }
}


//Decode function (needs encoded binary string as a parameter)
string huffman :: decode(string binary){
    Node *temp;
    temp=head;
    string binToText="";

    for(int i=0;i<binary.size();i++){
        if(binary[i]=='1'){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
        if(temp->character!=NULL){
            binToText+=temp->character;
            temp=head;
        }
    }

    return binToText;
}

