#include <iostream>
using namespace std;

// Counting Sort

void countingSort(int *arr,int len){

    int big;

    big = arr[0];

    int *a = new int[len];

    for(int i = 1; i < len; i++){
            if( arr[i] > big){
                big = arr[i];
            }
    }

    int *newArray = new int[++big];

    for(int i = 0; i < big; i++ ){

        newArray[i] = 0;
    }

    for(int i = 0; i < len; i++){

        newArray[ arr[i] ]++;
    }



    for(int i = 1; i < big; i++){

        newArray[i] = newArray[i-1] + newArray[i];
    }




    for(int i = 0; i < len; i++){

        a[ newArray[ arr[i] ] - 1 ] = arr[i];
        newArray[ arr[i] ]--;
    }

    for(int i = 0; i < len; i++){
        arr[i] = a[i];
    }



}

// Binary Search

int binarySearch(int *arr, int beg, int ending, int item){

  int mid = (beg+ending)/2;

  while(beg <= ending && arr[mid] != item){

       if( arr[mid] < item ){
            beg = mid +1;
       }else{
          ending = mid -1;
       }

       mid = (beg+ending)/2;
  }

  if(arr[mid] == item){
    return mid;
  }else{
     return -1;
  }

}

// print array

void printArray(int *a, int len){

    for(int i =0; i< len; i++){

        cout << a[i] << " ";
    }

    cout << endl;
}

 // This is main function

int main()
{

    int arr[] = {5,10,7,9,6,5,13,4,1,17,0,8};
   // int arr[]={8,12,13,14,15};
    int len = sizeof(arr) / sizeof(int);

   // cout << binarySearch(arr,0,len-1,18);

   int item = 13;

   printArray(arr,len);

   countingSort(arr,len);

    cout << "\nSorted Array: ";
    printArray(arr,len);

    int newArray[len];

    for(int i = 0; i < len; i++){
        newArray[i] = item - arr[i];
    }

    cout << "\nSubtracted Array: ";
    printArray(newArray,len);



    int pos,j=0,counter, k =0;
    int *a = new int[len];
    int *b = new int[len];

    cout << endl << item << " --> ";

    for(int i = 0; i < len; i++){

        pos = binarySearch(arr,0,len-1,newArray[i]);


       counter = binarySearch(a,0,j-1,pos);


        if( pos >= 0 && pos != i && counter == -1 ){

            a[j++] = i;
            a[j++] = pos;



       cout << "( "<< arr[ i ] << " , " << arr [ pos ] << " )";

       countingSort(a,j);

        }

     counter  = 0;
    }



    cout << endl;

    return 0;
}
