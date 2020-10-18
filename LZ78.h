#include <bits/stdc++.h>

using namespace std;

typedef struct Node{
    char ch;
    int index;
    vector<Node *>child;
}Node;

Node *createNode(char ch, int index);

class LZ78{
    private:
        string text;
        Node *root;
        int index;
        int debug;

    public:
        LZ78(string raw_text, int is_debug);
        void encode();
        int checkChild(Node *parent_node, char ch);

};
