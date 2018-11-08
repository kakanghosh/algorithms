#include <iostream>
#include <queue>

using namespace std;

void listSize(queue<char> myList){

    cout << "The size of the list: "<< myList.size() << endl;
}


int main()
{

    queue<char> myQueue;

    listSize(myQueue);

    for(char a = 'A' ; a <= 'Z'; a++)
        myQueue.push(a);

    while(!myQueue.empty()){
        cout << myQueue.front() << " ";
        myQueue.pop();

    }


    return 0;
}
