#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

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


      // add edge

       void addEdge( int i , int j){

           if( (i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter) )
             adjacencyList[i].push_back(j);
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


      //counting degree indirected graph

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

            cout << "Adj[" << (char)(65+i) << "] : ";
            point = adjacencyList[i].begin();

            while(point!= adjacencyList[i].end()){
                cout << (char)(65+*point) << " ";
                point++;
            }
            cout << "\n";
         }

      }

    // get nodes counter

    int getVertexNumber(){

        return adjacencyList.size();
    }

    // get adjacency list

    vector< list<int> > getAdjacencyList(){
        return adjacencyList;
    }


// BFS

    void BFS(Graph gr ,int starting){

         int n = gr.getVertexNumber(); //adjacencyList.size();
         int u;
         list<int>::iterator point;
         int *mark = new int[ n];
         queue<int> myQueue, que;
         vector< list<int> > myVec = gr.getAdjacencyList();

         for(int i = 0; i < n; i++)
            mark[i]= 0;

         myQueue.push(starting);
           mark[starting] = 1;


         while( !myQueue.empty() ){
                u = myQueue.front();  // front element of the queue
                myQueue.pop();        // pop the front element from the queue

                point = myVec[u].begin(); // root address of the list

                while( point != myVec[u].end()  ){

                    if( mark[*point] == 0 ){   // fresh node
                        mark[*point] = -1;     // after will be checked
                        myQueue.push(*point);

                    }
                    point++;
                }
                mark[u] = 1; // visit done
                que.push(u);

         }



            while( !que.empty() ){

                cout << (char)(65+que.front()) << " ";
                que.pop();
            }

            cout << endl;

    }



};


int main()
{
     Graph graph(5);

     graph.addEdge(0,3);

     graph.addEdge(1,3);
     graph.addEdge(1,4);

     graph.addEdge(2,4);

     graph.addEdge(3,0);
     graph.addEdge(3,1);
     graph.addEdge(3,4);

     graph.addEdge(4,1);
     graph.addEdge(4,2);
     graph.addEdge(4,3);

     graph.show();

     cout << "New Graph>>>" << endl;

     graph.removeEdge(3,1);
     graph.removeEdge(4,1);
     graph.removeEdge(4,3);

     graph.show();


   cout << endl << endl << endl << "BFS: "<<endl;

    for(int i=0; i < 5; i++)
        graph.BFS(graph,i);


      return 0;
}
