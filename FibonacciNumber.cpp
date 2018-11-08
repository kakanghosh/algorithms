#include <iostream>
using namespace std;

int main()
{
   int a = 0, b = 1, c, temp;

   cout << "Enter position number: ";
   cin >> c;

   for(int i = 2; i < c; i++){
      temp = b;
      b = a + b;
      a = temp;

   }

   if( c == 0){
     cout << 0 << endl;
   }else if(c == 1){
     cout << 1 << endl;
   }else{
      cout << b << endl;
   }

    return 0;
}
