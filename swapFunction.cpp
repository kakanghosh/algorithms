#include <iostream>
using namespace std;
void swapFunction(int *a , int *b);

int main(){

   int a,b;

   cout<< "Enter two number: ";
   cin >> a >> b;

   cout << "A = " << a << " B =  " << b << endl;

   swapFunction(&a, &b );

   cout << "A = " << a << " B =  " << b << endl;

   return 0;
}


void swapFunction(int *a , int *b){

    //  cout  << *a << " " << *b << endl;

    *a = *a + *b;
    *b = *a - *b;
    *a =  *a - *b;
}
