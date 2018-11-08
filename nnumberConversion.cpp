#include <iostream>
using namespace std;

int decimalToBinary(int x);
int binaryTODecimal(int x);

int main()
{

   cout << decimalToBinary(101) << endl;
   cout << binaryTODecimal(101);

   return 0;
}


//decimal to binary conversion

int decimalToBinary(int x){

    string binary;
    int decimalNumber = x;
    int counter = 0;
    int binaryValue = 0;

    while( decimalNumber > 0 ){

         if( decimalNumber % 2 == 0 ){
            binary += '0';
            counter++;
         }else{
            binary += '1';
            counter++;
         }

         decimalNumber /= 2;

    }

    for( int i = counter-1; i >= 0; i-- ){

        binaryValue = binaryValue * 10;
        binaryValue += (binary[i] - 48) ;
    }

    return binaryValue;

}


// binary to decimal conversion

int binaryTODecimal(int x){

        int binaryNumber = x;
        int decimalValue = 0;
        int mul = 1;

        while( binaryNumber > 0 ){

             if( binaryNumber % 10 == 1 ){
                decimalValue += mul;
                mul = mul * 2;
             }else{
                mul = mul * 2;
             }

             binaryNumber /= 10;
        }

        return decimalValue;
}
