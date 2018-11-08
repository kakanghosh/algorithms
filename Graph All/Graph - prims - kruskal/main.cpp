#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>
#include <set>
using namespace std;


struct Status{

    int state = 0;
    int distance = numeric_limits<int>::max();
    int parent = -1;

};

struct VertexStatus{

  int vertexNumber;
  bool visite;
  long key;
  int parent;

};


struct Vertex{

   int ver ;
   int weight;

};

//edge list structure
struct Edge{

    int startingEdge;
    int endingEdge;
    int key;
};

class Graph{

private:
    vector< list<Vertex> > adjacencyList;
    int vertexCounter;

    vector<Edge> edgeList;

    vector< set<int> > setList ; // keeping the vertex as individual tree forest

    vector<Edge> finalTree;

public:
    // Constructor
    Graph(int v){
      vertexCounter = v;
      list<Vertex> li;

      set<int> setData;

     for( int i = 0; i < vertexCounter; i++){
        adjacencyList.push_back(li);

        setData.insert(i);

        setList.push_back(setData);

        setData.clear();
     }

    }

    // Destructor
    ~Graph(){}


      // add edge
       void addEdge( int i , int j, int weight){

            Vertex vertex;  //= new Vertex;

            vertex.ver = j;
            vertex.weight = weight;

           if( (i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter) )
             adjacencyList[i].push_back(vertex);


      }


      //show all the edges with weight

      void printSortedEdge(  ){

         for(int  i = 0; i < edgeList.size(); i++ ){

            cout << edgeList[i].startingEdge << " -> " << edgeList[i].endingEdge << "  ==  " << edgeList[i].key << endl;
         }
      }


      //show all the tree forest
      void printTree(){

         set<int>::iterator pointer;

         for( int i = 0; i < setList.size(); i++){

            pointer = setList[i].begin();

            while( pointer != setList[i].end() ){

                cout << *pointer << " ";

                pointer++;
            }

            cout << endl;

         }


      }



      //add Undirected edge
      void addUndirectedEdge(int i , int j, int weight){

          if( (i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter) ){
            addEdge(i,j,weight);
            addEdge(j,i, weight);

           Edge edge;

           edge.startingEdge = i;
           edge.endingEdge = j;
           edge.key = weight;

           edgeList.push_back(edge);

           sortTheEdge();

          }
      }


      //sort the edge

      void sortTheEdge(){

          Edge edge , temp;
          int a=0,b=0;

          for( int i = 0; i < edgeList.size(); i++){

               edge = edgeList[i];
               a = i;


               for( int j = i+1; j < edgeList.size(); j++ ){

                   if( edgeList[j].key < edge.key ){

                      edge = edgeList[j];
                      a = j;
                   }
               }

                   temp = edgeList[i];
                   edgeList[i] = edge;
                   edgeList[a] = temp;


          }


      }

      // isEdge

      bool isEdge(int i , int j){

            if( (i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter) ){

                list<Vertex>::iterator point = adjacencyList[i].begin();

                while( point != adjacencyList[i].end() ){

                    if( point->ver == j ){
                        return true;
                    }

                    point++;
                }

                return false;
        }

      }

      //get weight

      int getWeight( int i , int j){

          if( (i >= 0 && i < vertexCounter) && ( j >= 0 && j < vertexCounter) ){

                list<Vertex>::iterator point = adjacencyList[i].begin();

                while( point != adjacencyList[i].end() ){

                    if( point->ver == j ){
                        return point->weight;
                    }
                    point++;
                }

                return 0;
          }

      }


    //Show matrix method
     void showMatrix(){

        list<Vertex>:: iterator point;

        for( int i = 0; i < adjacencyList.size(); i++){

            point = adjacencyList[i].begin();

            cout  << "Adjacency list of  "<< (char)(65+i) << " : " ;

            while( point != adjacencyList[i].end() ){

                cout << (char) (65 +(point->ver) ) << " ";
                point++;
            }

            cout << endl;
        }

     }

     //get vertex counter method
     int getVertexCounter(){
       return vertexCounter;
     }

     // prims algorithm

      // implementing minimum spanning tree using Prim's Algorithm
  /*
  *
  *
  */

  void MSTPrims(Graph &graph , int s){

       int vertex = graph.getVertexCounter();
       int u;

       vector<VertexStatus> myVec;

      // cout << vertex << endl;

       VertexStatus *status = new VertexStatus[vertex];

        for( int i = 0; i < vertex; i++){

             status[i].vertexNumber = i;
             status[i].visite = false;
             status[i].parent = -1;
             status[i].key = numeric_limits<long>::max();
        }

        status[s].key = 0;
        status[s].visite = true;


        for( int i = 0; i < vertex; i++){
            myVec.push_back(status[i]);
        }


        cout << "\n\nMinimum spanning tree is: (Prims)" << endl;

        int n = 0;


        while( !myVec.empty() ){

            u = extractMin(myVec).vertexNumber;

            status[u].visite = true;



           if( n != 0 )
            cout << (char)(65+status[u].parent) << " -> " << (char)(65+u) << endl;

            n++;


            for( int v = 0; v < vertex; v++){

                if( isEdge(u,v)){

                    if( isIn(myVec,v) && ( getWeight(u,v) ) < status[v].key ){

                   //     cout << " " << (char)(65+v) << " key: " << getWeight(u,v) << endl;

                        status[v].key = getWeight(u,v);
                        status[v].parent = u;
                        modifyKey(myVec,v,status[v].key);
                    }

                }
            }

        }



  }

   // is? vertex in the list
    bool isIn(vector<VertexStatus> &myVec, int n){

          for( int i = 0; i < myVec.size(); i++){

              if( myVec[i].vertexNumber == n ){
                return true;
              }
          }

          return false;
    }

  // get vertex status

   VertexStatus extractMin(vector<VertexStatus> &myVec){

        int verKey;
        VertexStatus st;
        int n;

            verKey = myVec[0].key;
            st = myVec[0];
            n = 0;

           // cout << "Initialize: vertex = " << (char)(65+n) <<" key = " << verKey << endl;


        for( int i = 1; i < myVec.size(); i++){

            if( myVec[i].key < verKey ){

                verKey = myVec[i].key;
                st = myVec[i];
                n = i;
            }


        }

        //cout << "Min: vertex = " << (char)(65+n)  <<" key = " << verKey << endl << endl;


        vector<VertexStatus>::iterator point;

        point = myVec.begin();

        for( int i = 0; i < n; i++)
            point++;

        myVec.erase(point);

        return st;
    }

   //modify key


  void modifyKey(vector<VertexStatus> &myVec, int vertex, int key){

      for( int i = 0; i < myVec.size(); i++){

         if( myVec[i].vertexNumber == vertex ){

             myVec[i].key = key;
             break;
         }
      }

  }


   //Kruskal algorithm

    void kruskalMST(){

        int starting , ending;

        set<int>::iterator pointer;


        for( int i = 0; i < edgeList.size(); i++){


            for( int j = 0; j < setList.size(); j++){

                 pointer = setList[j].begin();

                 while( pointer != setList[j].end() ){

                    if( *pointer == edgeList[i].startingEdge ){
                        starting = j;
                    }

                    if( *pointer == edgeList[i].endingEdge ){
                        ending = j;
                    }

                    pointer++;

                 }
            }

            if( starting != ending ){


                pointer = setList[ending].begin();

                while( pointer  != setList[ending].end()  ){

                    setList[starting].insert(*pointer);

                    pointer++;
                }

                setList.erase( setList.begin() + ending );

                finalTree.push_back( edgeList[i] );
            }

        }

        cout << "\n\nMinimum spanning tree is: (Kruskal)" << endl;
        for( int i = 0; i < finalTree.size(); i++){

            cout << (char)(65+finalTree[i].startingEdge) << " -> " << (char)(65+finalTree[i].endingEdge) << endl;
        }

    }


};


int main()
{
     Graph graph(6);

     graph.addUndirectedEdge(0,1,2);
     graph.addUndirectedEdge(0,2,2);
     graph.addUndirectedEdge(1,4,5);
     graph.addUndirectedEdge(2,3,3);
     graph.addUndirectedEdge(3,4,7);
     graph.addUndirectedEdge(2,5,1);
     graph.addUndirectedEdge(4,5,6);


    graph.showMatrix();

    //graph.printSortedEdge();

    graph.kruskalMST();


    //graph.printTree();

    graph.MSTPrims(graph,0);


      return 0;
}
