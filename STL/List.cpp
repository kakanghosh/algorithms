#include <iostream>
#include <list>
using namespace std;

void listSize(list<char> myList){

    cout << "The size of the list: "<< myList.size() << endl;
}

list<char>::iterator go(list<char>::iterator point, int n){

     for(int i = 0; i < n ; i++)
        point++;

     return point;
}

int main()
{
    list<char> myTodoList, revList;
    list<char>::iterator myList;

    listSize(myTodoList);

    for(int i = 0; i < 26; i++)
        myTodoList.push_back( (char)(i+65));


    myTodoList.push_front('I');
    myTodoList.push_front('V');
    myTodoList.push_front('P');


    listSize(myTodoList);




    myList = myTodoList.begin();
    myList ++;

    myTodoList.insert( go(myList,5), 'Q');

    myTodoList.sort();

    myList = myTodoList.begin();

   // myTodoList.sort();

    cout << "My ToDO list elements: ";

    while(myList!= myTodoList.end()){
        cout << *myList << " ";
        revList.push_front(*myList);
        myList++;
    }



    myList = myTodoList.end();
    myList--;

    cout << "\nMy ToDO list elements (rev): ";

    while(1){

        cout << *myList << " ";

        if( myList == myTodoList.begin()) break;

        myList--;
    }




    // reverse list

//    myList = revList.begin();
//
//    cout << "\nMy ToDO list elements (reverse) : ";
//
//    while(myList!= revList.end()){
//        cout << *myList << " ";
//        myList++;
//    }







    return 0;
}


