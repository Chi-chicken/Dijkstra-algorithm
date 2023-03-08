#include<bits/stdc++.h>
using namespace std ;

#define INF 999 //infinity=999

int V, src, cost[100][100]; 

/*
src： source
V: number of node
*/

int dist[100];
bool visited[100] = {0};
int parent[100];


//initialize
void init(){
    for(int i = 0; i < V; i++){
        parent[i] = i;
        dist[i] = INF;
    }
    dist[src] = 0; //source node distance = 0
}

int getNearst(){
    int minvalue = INF;
    int minnode = 0;
    for(int i = 0; i < V; i++){
        //!visted->not visited
        if(!visited[i] && dist[i] < minvalue){
            minvalue = dist[i]; //update minvalue
            minnode = i;
        }  
    }
    return minnode;

}


void dijkstra(){
    for(int i = 0; i < V; i++){
        int nearst = getNearst();
        visited[nearst] = true;

        for(int adj = 0; adj < V; adj++){
            if(cost[nearst][adj] != INF && 
            dist[adj] > dist[nearst] + cost[nearst][adj]){
                dist[adj] = dist[nearst] + cost[nearst][adj]; //update dist[adj]
                parent[adj] = nearst;
            }

        }
    }
}

void display(){
    cout << "Node:\t\tCost\t\tPath" << endl;

    for(int i = 0; i < V; i++){
        cout << i << "\t\t" << dist[i] << "\t\t" << " ";
        cout << i << " ";
        int parnode = parent[i];

        while(parnode != src){
            cout << "<-" << parnode << " ";
            parnode = parent[parnode];

        }
        cout << "<-" << 1 << endl;
    }
}

int main(void) { 
    //input: node, matrix, start node
    cout<< "Enter the number of node : " ; 
    cin >> V ; 
    cout << "Enter cost matrix : \n" ; 
    for(int i = 0 ;i < V ; i++){
        for(int j = 0 ; j< V ; j++){
            cin >> cost[i][j] ; 
        }
    }
 
    cout << "\nEnter source node: ";
    cin >> src ;
    init();
    dijkstra() ; 
    display();
    system("pause");
}


/*
0       4       999     999     999     999     999     8       999
4       0       8       999     999     999     999     8       999
999     8       0       7       999     4       999     999     2
999     999     7       0       9       14      999     999     999
999     999     999     9       0       10      999     999     999
999     999     4       14      10      0       2       999     999
999     999     999     999     999     2       0       1       6
8       11      999     999     999     999     1       0       7
999     999     2       999     999     999     6       7       0
*/