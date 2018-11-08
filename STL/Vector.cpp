#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Car{

private:
    float oil;
    float path;

public:
    Car(){
      oil = 0;
      path = 0;
    }

    Car(float oil, float path){
        this->oil = oil;
        this->path = path;
    }

    float calculateDriving(){
        return oil*5;
    }

    void refillOil(float oil){
        this->oil+= oil;
    }

    float getOil(){
        return oil;
    }
};


int main()
{
    vector<Car> myCars(2,Car(20.3,30));
    vector<Car>::iterator point;



    myCars.push_back(Car(10,50));
    myCars.push_back(Car(29.2,65.8));

    point = myCars.begin();
  //  cout << point->calculateDriving()<<endl;

    myCars.insert(point+1, Car(2,10));

    point = myCars.begin();

   // cout << point->calculateDriving()<<endl;

    cout << "Size: "<< myCars.size() << endl;



    cout << "Iterate item using iterator: " << endl;



    for( vector<Car>::iterator car = myCars.begin(); car!= myCars.end(); car++)
        cout << car->calculateDriving() << endl;

       // cout << myCars.empty();

    cout << "Iterate item using index: " << endl;


    for( int car = 0; car < myCars.size(); car++)
        cout << myCars[car].calculateDriving() << endl;

    /*

    vector<int> myVector;

    cout << "size of the vector: " << myVector.size() << endl;


    for(int i = 0; i < 5; i++)
        myVector.push_back(i+5);

    for(int i = 0; i < myVector.size(); i++){
        cout << myVector[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < 5; i++)
        myVector.push_back(i+2);

    for(int i = 0; i < myVector.size(); i++){
        cout << myVector[i] << " ";
    }

    cout << endl;

    vector <int>:: iterator p;

    p = myVector.begin();

    int i = 0;

   // myVector.insert((p+myVector.size()/2),0);
    myVector.erase(p,p+4);

    while( p != myVector.end()){
        cout << myVector[i] << " ";
        i++;
        p++;
    }
    */


    return 0;
}

