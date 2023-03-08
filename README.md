# Dijkstra-algorithm
This project is a practice of Dijkstra algorithm with C++.

## Dijkstra (Find the shortest path between nodes in a graph)
  * Track the currently known shortest distance from each node to the source node and it updates these values if it finds a shorter path.
  * Once the algorithm has found the shortest path between the source node and another node, that node is marked as "visited" and added to the path.
  * The process continues until all the nodes in the graph have been added to the path. 
  * Limitation- No negative weight (If there is a negative weight in the graph, then the algorithm will not work properly. Once a node has been marked as "visited", the current path to that node is marked as the shortest path to reach that node. And negative weights can alter this if the total weight can be decremented after this step has occurred)
  
## Algorithm
### `Main()`
  * `Src`: sorce code
  * `V`: number of nodes
```C++
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
```

#### Initialization `Intit()`
```C++
void init(){
    for(int i = 0; i < V; i++){
        parent[i] = i;
        dist[i] = INF;
    }
    dist[src] = 0; //source node distance = 0
}
```
#### Find the nearest node `getNearst()`
```C++
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
```

#### Dijkstra `dijkstra()`
```C++
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

#### Display the shortest route `diaplay()`
```C++
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
```
