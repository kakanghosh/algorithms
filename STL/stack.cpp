#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    stack<int> *myStack = new stack<int>;
    queue<int> *myQueue = new queue<int>;

    int n = 6;

    /*

    for(int i = 1; i < n; i++){

        cout << i << " pushed into the stack!" << endl;
        myStack->push(i);
    }

    for( int i = n - 1; i > 0; i--){

        cout << i << "th item: " << myStack->top() << endl;
        myStack->pop();
    } */

    for(int i = 1; i < n; i++){

        cout << i << " pushed into the queue!" << endl;
        myQueue->push(i);
    }
    int i = 1;

      while(!myQueue->empty()){

        cout << i++ << "th item: " << myQueue->front() << endl;
        myQueue->pop();
    }



    return 0;
}

