#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <limits>
#include <queue>


using namespace std;

struct Status{


    int state = 0;
    int distance = numeric_limits<int>::max();
    int parent = -1;

};

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

         // Destructor

        ~Graph(){

            for( int i = 0; i < vertexCounter; i++)
                delete[] adjacencyMatrix[i];
            delete[] adjacencyMatrix;

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


        // get total vertex
        int getVertexCounter(){
            return vertexCounter;
        }



        // BFS
        void BFS(Graph graph , int vertex){

          int vCounter = graph.getVertexCounter();
          Status *st = new Status[vCounter];
          int u;

          st[vertex].state = 1;
          st[vertex].distance = 0;
          st[vertex].parent = -1;

          queue<int> myQueue;

          myQueue.push(vertex);

          while( !myQueue.empty() ){

            u = myQueue.front();
            myQueue.pop();

            cout << "vertex: " << (char)(65+u) << " parent: " << (char)(65+st[u].parent) << " distance: " << st[u].distance << endl;

            for( int i = 0; i < vCounter; i++ ){

                    if( graph.isEdge(u,i)){

                        if( st[i].state == 0){
                           st[i].state = 1;
                           st[i].distance = st[u].distance + 1;
                           st[i].parent = u;
                           myQueue.push(i);

                        }
                    }
            }

          }
        } // end of BFS


};

int main()
{
    Graph graph("graph.txt",5);

    graph.showMatrix();

//     for(int i = 0; i < 5; i++)
//        graph.findAdjacencyVertices(i);

    cout << "\n\nBFS of the graph " << endl;

    graph.BFS(graph, 4);




    return 0;
}

