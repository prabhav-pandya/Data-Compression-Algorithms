using namespace std;

#define MAX 256

//Table that stores Characters and their codes after encoding
typedef struct CodeTable{
    char character;
    string code;
} CodeTable;

//Table that stores frequency of the characters
typedef struct CharFreq{
    char character;
    int freq;
} CharFreq;

//Node structure
typedef struct Node{
    int data;
    char character;
    Node *next, *left, *right;
} Node;


class huffman{

    private:
        CharFreq arr[MAX];
        CodeTable codeTable[MAX];
        int sizeAfterEncoding;
        int table_index;
        int debug;
        string text;

    public:

        huffman(string file_content, int debug_mode=0);

        /**********************************/

        void encode();
        int cmpFreq(const void* a, const void* b);
        void printCharFreq(CharFreq arr[],int len);
        void sortNodes(Node *head, int len);
        void printNodeArr(Node *head);
        void printCharTable(Node *head, string code);
        void printNodeChar(Node *head, int len);
        void textToCharFreq(char text[], int len);
        Node* createNode(int value);

        /***********************************/

};
