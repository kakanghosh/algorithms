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
   // public:
        int *stateOf;
        int *parentOf;
        int *startTime;
        int *endTime;
        int *node;
        vector<int> vec;
        vector<list<int>> treeVec;
        list<int> li;


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

        void addUndirectedEdge(int i , int j){

            if( (i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter) ){
                addDirectedEdge(i,j);
                addDirectedEdge(j,i);
            }

        }

        // add directed edge
        void addDirectedEdge(int i , int j){
             if( (i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter) ){
                adjacencyMatrix[i][j] = true;
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
        void DFS(Graph &graph){

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

            for( int i = 0; i < counter; i++){

                if( stateOf[i] == 0 ){
                    runDFS(i,stateOf, graph);
                    treeVec.push_back(li);  // inserting every tree in the vector
                    li.clear();   // clearing the tree list after inserting in the vector for a new tree
                }

            }

          //  showtime(node,startTime,endTime,counter);
            sorting(endTime,node,counter);
            showtime(node,startTime,endTime,counter);

        }
   // runDFS method is implement

   void runDFS(int u, int state[], Graph &gr){

        state[u] = -1;
        time++;
        startTime[u] = time;

          vec.push_back(u);  // inserting vertex for checking back edge
          li.push_back(u);   // inserting vertex for making tree


        for( int v = 0; v < gr.getVertexCounter(); v++ ){

            if( (gr.isEdge(u,v)) ){

                    //vec.push_back(v);

                if(state[v] == 0){
                cout << (char)(65+u) << " -> " << (char)(65+v) << " Tree edge" << endl;
                parentOf[v] = u;


                runDFS(v,state,gr);

                }else if( backEdge(vec,v) ){
                    cout << (char)(65+u) << " -> " << (char)(65+v) << " Back edge" << endl;
                }else if( startTime[v] > 0 && !crossEdge(treeVec,v)){
                    cout << (char)(65+u) << " -> " << (char)(65+v) << " Forward edge" << endl;
                }else if( crossEdge(treeVec,v)){
                    cout << (char)(65+u) << " -> " << (char)(65+v) << " Cross edge" << endl;
                }
            }

        }

        state[u] = 1;
        time++;
        endTime[u] = time;
        vec.clear();  //  clearing the vector after detecting the back edge every possible time

     //   cout << u <<",";
   }

   // checking back edge

   bool backEdge(vector <int> &vec , int v){

        for( int i = 0; i < vec.size(); i++){
            if( vec[i] == v){
                return true;
            }
        }

        return false;
   }

   bool crossEdge(vector<list<int>> &tree, int v){

      list<int>::iterator li;

      for( int i = 0; i < tree.size(); i++){

            li = tree[i].begin();

            while( li != tree[i].end() ){
                if( *li == v ){
                    return true;
                }
                li++;
            }
      }
      return false;
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
                cout <<  (char)(node[i]+65);
                if( i < counter-1){
                  cout  << " ,  ";
                }
            }
  }


};

int main()
{
    Graph graph(9);

    graph.addDirectedEdge(0,0);
    graph.addDirectedEdge(0,1);
    graph.addDirectedEdge(0,4);
    graph.addDirectedEdge(1,2);
    graph.addDirectedEdge(2,3);
    graph.addDirectedEdge(3,1);
    graph.addDirectedEdge(3,4);
    graph.addDirectedEdge(5,1);
    graph.addDirectedEdge(5,6);
    graph.addDirectedEdge(6,2);
    graph.addDirectedEdge(7,5);
    graph.addDirectedEdge(6,7);
    graph.addDirectedEdge(7,8);
    graph.addDirectedEdge(8,3);
    graph.addDirectedEdge(8,8);




    graph.showMatrix();

    cout << "DFS: " << endl;
    graph.DFS(graph);





    return 0;
}


