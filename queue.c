#include<iostream>

using namespace std;

int main() {
    queue<int> myqueue;
    myqueue.push(0);
    myqueue.push(1);
    myqueue.push(1);

    cout<<myqueue.front();

    return 0;
}
