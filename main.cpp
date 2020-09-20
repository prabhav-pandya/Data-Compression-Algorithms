#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
#include<cstdlib>

#include "rle.h"

using namespace std;

typedef struct CharFreq{
    char character;
    int freq;
} CharFreq;

typedef struct Node{
    int data;
    char character;
    Node *next, *left, *right;
} Node;

int cmpFreq(const void* a, const void* b);
void printCharFreq(CharFreq arr[],int len);
Node* createNode(int value);
void sortNodes(Node *head, int len);
void printNodeArr(Node *head);


int main() {
    CharFreq arr[]={{'A',3},{'B',5},{'C',6},{'D',4},{'E',2}};
    int len=sizeof(arr)/sizeof(arr[0]);

    cout<<"Sorted Character Frequency: "<<endl;
    printCharFreq(arr,len);

    int n;
    Node *head, *newNode, *temp;

    head=createNode(arr[0].freq);

    temp=head;


    for(int i=1;i<len;i++){
        newNode=createNode(arr[i].freq);
        temp->character=arr[i].character;
        temp->next=newNode;
        temp=temp->next;
    }

    cout<<"\nInitial Linked List: "<<endl;
    printNodeArr(head);

    sortNodes(head,len);
    cout<<"\nSorted Linked List: "<<endl;

    printNodeArr(head);
    temp=head;
    for(int i=0;i<len;i++){
        cout<<temp->character<<" ";
        temp=temp->next;
    }
    cout<<endl;

    /*
    Problems Right Now:
    1. Character Swapping
    2. Tree Structuring
    */

    cout<<"\nArray Convergence:"<<endl;
    printNodeArr(head);
    cout<<"\n";
    while(head->next!=NULL){
        newNode=createNode(0);
        temp=head;
        newNode->left=temp;
        newNode->right=temp->next;
        newNode->data=temp->data+(temp->next)->data;
        newNode->next=(temp->next)->next;
        head=newNode;
        printNodeArr(head);
        sortNodes(head,--len);
    }


    return 0;
}

void printNodeArr(Node *head){
    Node *temp;
    temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
}

void sortNodes(Node *head, int len){
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


int cmpFreq(const void* a, const void* b)
{
	CharFreq x = *(CharFreq*) a;
	CharFreq y = *(CharFreq*) b;
    return x.freq-y.freq;
}

void printCharFreq(CharFreq arr[],int len){
        for(int i=0;i<len;i++){
        cout<<arr[i].character<<" "<<arr[i].freq<<endl;
    }
}


Node* createNode(int value){
    Node *node;
    node=(Node*)malloc(sizeof(Node));
    node->data=value;
    node->character=NULL;
    node->next=NULL;
    node->left=NULL;
    node->right=NULL;
    return node;
}

