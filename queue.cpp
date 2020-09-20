#include<iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

void codeForQueue(){
    queue<int> myqueue;
    myqueue.push(0);
    myqueue.push(1);
    myqueue.push(2);
    cout<<myqueue.front()<<endl;
    myqueue.pop();
    cout<<myqueue.front();
    cout<<endl<<myqueue.empty();
}

void codeForStack(){
    stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top();
}

struct Node{
    int key;
    Node *left;
    Node *right;
};

Node* createNode(int key){
    Node *node;
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    return node;
}


//change function name to main to run the code
int test() {

    //Node* node=createNode(10);
    //cout<<node->key;
    Node *root=createNode(1);
    root->left=createNode(2);
    root->left->left=createNode(4);

    root->right=createNode(3);
    root->right->left=createNode(5);

    return 0;
}


