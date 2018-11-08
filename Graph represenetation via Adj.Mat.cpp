#include <iostream>
#include <fstream>
#include <list>
#include <vector>


using namespace std;

class Graph{

    private:
        bool **adjacencyMatrix;
        int vertexCounter;

    public:
        // Constructor
        Graph(int vertexCounter){

            this->vertexCounter = vertexCounter;
            adjacencyMatrix = new bool *[this->vertexCounter];

            for( int i = 0; i < this->vertexCounter; i++){
                adjacencyMatrix[i] = new bool[this->vertexCounter];

                for(int j = 0; j < this->vertexCounter; j++)
                    adjacencyMatrix[i][j] = false;
            }

        }

        //Another Constructor read from file

        Graph(char *fileName, int vertexCounter){

            this->vertexCounter = vertexCounter;
            adjacencyMatrix = new bool *[this->vertexCounter];

            ifstream file;
            file.open(fileName, ios::in);

            if(!file){
                cout << " Error: " << fileName << " not found!" << endl;
                return;
            }

            if(file.is_open()){
                    for(int i = 0; i < this->vertexCounter; i++){
                            adjacencyMatrix[i] = new bool[vertexCounter];
                        for( int j = 0; j < this->vertexCounter; j++)
                            file>> adjacencyMatrix[i][j];
                    }
            }


        }

        // Add edge

        void addEdge(int i , int j){

            if( (i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter) ){
                adjacencyMatrix[i][j] = true;
                adjacencyMatrix[j][i] = true;
            }

        }

        // Remove Edge

         void removeEdge(int i , int j)
         {

            if( (i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter) ){
                adjacencyMatrix[i][j] = false;
                adjacencyMatrix[j][i] = false;
            }

        }

        // void print adjacency vertices

        void findAdjacencyVertices(int vertex){


            if( vertex >= 0 && vertex < vertexCounter ){

                cout << "\nAdj[" << (char)(vertex+65) << "] : ";
                for( int i = 0; i < vertexCounter; i++){

                    if( adjacencyMatrix[vertex][i] )

                        cout << " " << (char)(i+65) ;
                }

                cout << "\nDegree of vertex [" << (char)(65+vertex) << "] : " << degree(vertex) << endl;
            }



        }

        // get adjacentList

        vector< list<int> > getAdjacentList(){

             vector< list<int> > myVec;
             list<int> myList;
             int n = 0;

             for( int i = 0; i < vertexCounter; i++){

                  for( int j = 0; j < vertexCounter; j++){

                      if( adjacencyMatrix[i][j]  ){
                         myList.push_back(n);
                      }
                      n++;
                  }

                  myVec.push_back(myList); // inserting the list into vector
                  n = 0;   // counting from the first
                  myList.clear(); // clearing the list
             }

             return myVec;
        }



        // find the degree

        int degree(int vertex){
            int counter =0;

            if( vertex >= 0 && vertex < vertexCounter ){

                for( int i = 0; i < vertexCounter; i++){
                    if( adjacencyMatrix[vertex][i] )
                        counter++;
                }
                return counter;
            }else return 0;
        }

        // Print all matrix

        void showMatrix(){

            for( int i = 0; i < vertexCounter; i++){

               cout << "Adj[" << (char)(i+65) << "] : ";
                for(int j = 0; j < vertexCounter; j++){

                    cout << " " << adjacencyMatrix[i][j];
                }
                cout << endl;
            }
        }

        // finding existing of edge

        bool isEdge(int i , int j){

             if( (i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter) ){
                return adjacencyMatrix[i][j];
             }
        }

        // Destructor

        ~Graph(){

            for( int i = 0; i < vertexCounter; i++)
                delete[] adjacencyMatrix[i];
            delete[] adjacencyMatrix;

        }


};

int main()
{
    Graph graph("graph.txt",5);

    graph.showMatrix();

     for(int i = 0; i < 5; i++)
        graph.findAdjacencyVertices(i);




    return 0;
}

