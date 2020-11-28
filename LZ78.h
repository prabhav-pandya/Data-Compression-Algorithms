#include <bits/stdc++.h>

using namespace std;

typedef struct Node{
    char ch;
    int index;
    vector<Node *>child;
}Node;

typedef struct trie{
    char ch;
    //int parent_index;
    int index;
} trie;

Node *createNode(char ch, int index);

class LZ78{
    private:
        string text;
        Node *root;
        int index;
        int debug;
        int encoded_data_len=0;
        trie encoded_data[100];

    public:
        LZ78(string raw_text, int is_debug);
        void encode();
        void decode();
        int checkChild(Node *parent_node, char ch);
        void displayEncodedData(trie encoded_data[], int encoded_data_len);
        string findChild(Node *node,int index, string s);
};
