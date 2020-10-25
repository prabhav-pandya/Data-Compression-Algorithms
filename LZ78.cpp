#include <iostream>
#include <bits/stdc++.h>
#include "LZ78.h"
#include<string.h>

using namespace std;

//Initialise the parameters
LZ78 :: LZ78(string raw_text, int is_debug){
    text=raw_text;
    index=-1;
    root=createNode(' ',++index);
    debug=is_debug;
}


//Function to check to check for a vector's child
int LZ78 :: checkChild(Node *parent_node, char ch){
    int child_index=-1,i=0;
    if(debug) cout<<"\nChild Size : " <<parent_node->child.size()<<endl;
    while(!parent_node->child.empty() && i<parent_node->child.size() && child_index==-1){
       if(debug) cout<<parent_node->child[i]->ch<<", ";
        if(parent_node->child[i]->ch==ch){
            child_index=i;
        }
        i++;
    }
    if(debug) cout<<"\nChild Index : " <<child_index<<endl;
    return child_index;
}

//Function to encode the string
void LZ78 :: encode(){
    char ch;
    int child_index, parent_index;
    Node *parent_node;

    parent_node=root;
    parent_index=parent_node->index;

    cout<<"Raw string : "<<text<<endl<<endl;

    for(int i=0;i<text.size();i++){
        if(debug) cout<<endl<<text[i]<<endl;
        if(debug) cout<<"Parent Index: "<<parent_index<<endl;
        if(debug) cout<<"\nParent Node :"<<parent_node->index<<endl;

        child_index=checkChild(parent_node, text[i]);

        if(child_index==-1){
            parent_node->child.push_back(createNode(text[i],++index));
            encoded_data[encoded_data_len++]={text[i], parent_index, index};
            parent_node=root;
            parent_index=root->index;
        }
        else{
            parent_node=parent_node->child[child_index];
            parent_index=parent_node->index;
        }
    }

    displayEncodedData(encoded_data,encoded_data_len);

}

//Display the encoded data
void LZ78 :: displayEncodedData(trie encoded_data[], int encoded_data_len){
    for(int i=0;i<encoded_data_len;i++){
        cout<<"("<<encoded_data[i].parent_index<<", "<<encoded_data[i].ch<<")"<<encoded_data[i].index<<", ";
    }
    cout<<endl;
}

//find child using recursion
string LZ78 :: findChild(Node *node,int index, string s){
    if(node->index==index){
        return s;
    }

    string substr="", empty="";

    for(int i=0;i<node->child.size();i++){
        substr=findChild(node->child[i],index, s+ node->child[i]->ch);
        if(empty.compare(substr)!=0){
            return substr;
        }
    }
    return "";
}


//Decode the data
void LZ78 :: decode(){
    string decoded_string="";
    for(int i=0;i<encoded_data_len;i++){
        decoded_string += findChild(root, encoded_data[i].index, "");
    }

    cout<<"\nDecoded String : "<<decoded_string;

}

//Function to create and return a node
Node *createNode(char ch, int index){
    Node *node=new Node;
    //node=(Node *)malloc(sizeof(Node));
    node->ch=ch;
    node->index=index;
    node->child={};
    return node;
}
