#include <iostream>
using namespace std;
int naive(int a , int b);
int russian(int a, int b);
void compare(int a, int b);

int main(){

   //cout << naive(14,11);
   cout << endl;
   compare(14,11);

 return 0;
}


void compare( int a , int b ){

    if(naive(a,b) < russian(a,b)){
       cout  << "naive is more faster than russian." << endl;
    }else{
     cout << "russian is more faster than naive." << endl;
    }
}

int naive(int a , int b){

    int x = a, y = b , z = 0 , i = 1;

     while( x > 0){
        z += y;
        x -= 1;
        i++;

     }
   return i;
}


int russian(int a, int b){

     int x = a , y = b , z = 0, i = 1;

     while( x > 0){
       if( x % 2 == 1){
          z += y;
       }

       y = y << 1;
       x = x >> 1;

      // cout << "Step:  " << i++ << " x = " <<  x  << "  " << " y = " <<  y <<  endl;
      i++;

     }

  return i;
}
