#include <iostream>
#include <bits/stdc++.h>
#include "LZ78.h"

using namespace std;

LZ78 :: LZ78(string raw_text, int is_debug){
    text=raw_text;
    index=-1;
    root=createNode(' ',++index);
    debug=is_debug;
}

int LZ78 :: checkChild(Node *parent_node, char ch){
    int child_index=-1,i=0;
    if(debug) cout<<"\nChild Size : " <<parent_node->child.size()<<endl;
    while(!parent_node->child.empty() && i<parent_node->child.size() /*&& child_index==-1*/){
       if(debug) cout<<parent_node->child[i]->ch<<", ";
        if(parent_node->child[i]->ch==ch){
            child_index=i;
        }
        i++;
    }
    if(debug) cout<<"\nChild Index : " <<child_index<<endl;
    return child_index;
}

void LZ78 :: encode(){
    char ch;
    int child_index, parent_index;
    Node *parent_node;

    parent_node=root;
    parent_index=parent_node->index;

    for(int i=0;i<text.size();i++){
           if(debug) cout<<endl<<text[i]<<endl;
            if(debug) cout<<"Parent Index: "<<parent_index<<endl;
            if(debug) cout<<"\nParent Node :"<<parent_node->index<<endl;
        child_index=checkChild(parent_node, text[i]);
        if(child_index==-1){
            parent_node->child.push_back(createNode(text[i],++index));
            cout<<" ( "<<parent_index<<", "<<text[i]<<" )"<<index<<" ,";
            parent_node=root;
            parent_index=root->index;
        }
        else{
            parent_node=parent_node->child[child_index];
            parent_index=parent_node->index;
        }
    }

    }


Node *createNode(char ch, int index){
    Node *node=new Node;
    //node=(Node *)malloc(sizeof(Node));
    node->ch=ch;
    node->index=index;
    node->child={};
    return node;
}
