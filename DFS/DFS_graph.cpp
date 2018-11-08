#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <limits>
#include <queue>

int time = 0;
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
        int *stateOf;
        int *parentOf;
        int *startTime;
        int *endTime;
        int *node;

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

        //DFS here
        void DFS(Graph graph){

            int n  = 0, temp;
            int counter = graph.getVertexCounter();
            stateOf = new int[counter];
            startTime = new int[counter];
            endTime = new int[counter];
            parentOf = new int[counter];
            node = new int[counter];

            for( int i = 0; i < counter; i++)
                node[i] = n++;

            for( int i = 0; i < counter; i++)
                stateOf[i] = 0;

            for( int i = 0; i < counter; i++)
                runDFS(i,stateOf, graph);

               //  showtime(node,startTime,endTime , counter);

                // sorting the array of node
                sorting(endTime, node, counter);

                //show time
                showtime(node,startTime,endTime , counter);


            delete[] stateOf;


        }
   // runDFS method is implement

   void runDFS(int u, int state[], Graph gr){

        state[u] = -1;
        time++;
        startTime[u] = time;

        for( int v = 0; v < gr.getVertexCounter(); v++ ){

            if( (gr.isEdge(u,v)) && state[v] == 0 ){
                parentOf[v] = u;
                runDFS(v,state,gr);
            }
        }

        state[u] = 1;
        time++;
        endTime[u] = time;

        cout << u <<",";
   }

  //sorting
  void sorting(int endTime[], int node[] , int counter ){
               int temp, v;
           for( int i = 0; i < counter; i++){

                        int hi = endTime[i];
                        int index = i;
                        int v;

                        for( int j = i+1; j < counter; j++){

                            if(  endTime[j] > hi){
                                hi = endTime[j];
                                index = j;
                                temp = j;
                            }
                        }
                    v = endTime[i];
                    endTime[i] = endTime[index];
                    endTime[index] = v;

                    v = node[i];
                    node[i] = node[index];
                    node[index] = v;

                }

  }


  // showTIme

  void showtime(int node[] , int startTime[] , int endTime[] , int counter){

        cout << endl;
        for( int i = 0; i < counter; i++){
                cout <<  (char)(node[i]+65) << " ,  ";
              //  cout << "Staring time: " << startTime[i] << endl;
             //   cout << "End time: " << endTime[i] << endl << endl;
            }
  }


};

int main()
{
    Graph graph("graph.txt",8);

    graph.showMatrix();

    cout << "\n\nBFS of the graph " << endl;
   // graph.BFS(graph, 4);

    cout << "DFS: ";
    graph.DFS(graph);





    return 0;
}


