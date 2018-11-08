#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>
using namespace std;


struct Status{

    int state = 0;
    int distance = numeric_limits<int>::max();
    int parent = -1;

};

class Graph{

private:
    vector< list<int> > adjacencyList;
    int vertexCounter;



public:
    // Constructor
    Graph(int v){
      vertexCounter = v;
      list<int> li;

     for( int i = 0; i < vertexCounter; i++)
        adjacencyList.push_back(li);

    }

    // Destructor
    ~Graph(){}


      // add edge
       void addEdge( int i , int j){

           if( (i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter) )
             adjacencyList[i].push_back(j);
      }

      //add Undirected edge
      void addUndirectedEdge(int i , int j){

          if( (i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter) ){
            addEdge(i,j);
            addEdge(j,i);
          }
      }

      // remove edge
      void removeEdge(int vertex, int edge){

          list<int>::iterator point;

              if( vertex >=0 && vertex <= adjacencyList.size() ){
                point = adjacencyList[vertex].begin();

                while(point!= adjacencyList[vertex].end()){
                    if(edge == *point){
                        adjacencyList[vertex].erase(point);
                        break;
                    }
                    point++;
                }
              }
      }


      // adjacency list
      void showAdjacencyList(int vertex){

            if( vertex >= 0 && vertex < adjacencyList.size() ){
                list<int>::iterator point;

                point = adjacencyList[vertex].begin();

                cout << "Adjacency list of [" << (char)(vertex+65) << "] : ";

                while( point != adjacencyList[vertex].end() ){

                    cout << " " << (char)(65+*point);
                    point++;
                }
              cout << endl;


            }
      }

       //Find out degree
       int findOutDegree(int vertex){
           return findDegree(vertex);

       }

       //find InDegree
       int findInDegree(int vertex){

             int inDegree = 0;

            if( vertex >= 0 && vertex < adjacencyList.size() ){
                list<int>::iterator point;

                for( int i = 0; i < adjacencyList.size(); i++){
                point = adjacencyList[i].begin();

                while( point != adjacencyList[i].end() ){

                    if( *point == vertex ){
                        inDegree++;
                    }

                    point++;
                }

                }
                return inDegree;

            }
       }

       //get edge

       bool isEdge(int i , int j){

          if( ( i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter)){

               list<int>::iterator point = adjacencyList[i].begin();

               while(point != adjacencyList[i].end() ){

                   if(*point == j){
                    return true;
                   }
                   point++;
               }
                return false;
          }
       }


      //counting degree undirected graph
      int findDegree(int vertex){

            int counter = 0;

            if( vertex >= 0 && vertex < adjacencyList.size() ){
                list<int>::iterator point;

                point = adjacencyList[vertex].begin();


                while( point != adjacencyList[vertex].end() ){
                    counter++;
                    point++;
                }
                return counter;

            }
      }


      // Show all adjacency list
         void show(){

          list<int>:: iterator point;

         for( int i = 0; i < adjacencyList.size(); i++){

                showAdjacencyList(i);
            }
            cout << "\n";
         }



    // get nodes counter
    int getVertexNumber(){

        return adjacencyList.size();
    }

    //get vector
       vector < list<int> > getList(){
        return adjacencyList;
    }

    //BFS

    void BFS(Graph graph , int vertex){

          vector < list<int> > myVec = graph.getList();
          int vCounter = graph.getVertexNumber();
          Status *st = new Status[vCounter];
          int u;
          list<int>::iterator point;

          st[vertex].state = 1;
          st[vertex].distance = 0;
          st[vertex].parent = -1;

          queue<int> myQueue;

          myQueue.push(vertex);

          while( !myQueue.empty() ){

            u = myQueue.front();
            myQueue.pop();

            point = myVec[u].begin();  // get list pointer

            cout << "vertex: " << (char)(65+u) << " parent: " << (char)(65+st[u].parent) << " distance: " << st[u].distance << endl;

            while( point != myVec[u].end() ){

                        if( st[*point].state == 0){
                           st[*point].state = 1;
                           st[*point].distance = st[u].distance + 1;
                           st[*point].parent = u;
                           myQueue.push(*point);

                        }
                        point++;

            }

          }
        } // end of BFS







};


int main()
{
     Graph graph(5);

     graph.addUndirectedEdge(1,2);
     graph.addUndirectedEdge(1,4);
     graph.addUndirectedEdge(4,3);
     graph.addUndirectedEdge(0,3);
     graph.addUndirectedEdge(2,0);
     graph.addUndirectedEdge(2,3);
     graph.addUndirectedEdge(0,4);

     graph.show();


   cout <<"\n\nBFS: "<<endl;
   graph.BFS(graph,4);



      return 0;
}
