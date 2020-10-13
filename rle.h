using namespace std;

class RLE{
    private:
        string text;
    public:

         RLE(string raw_string);
         string encode();
         void decode(string text);
};
