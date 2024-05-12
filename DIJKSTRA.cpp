#include<iostream>
#include<climits>
using namespace std;

#define V 9

// Function to find the vertex with the minimum distance value
// from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], bool sptSet[]) 
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[]) 
{
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t " << dist[i] << endl;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src, int dest) 
{
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in the shortest path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) 
    {
        int u = minDistance(dist, sptSet); // Pick the minimum distance vertex from the set of vertices not yet processed
        sptSet[u] = true; // Mark the picked vertex as processed

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from u to v,
            // and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    cout << "Shortest distance from source to destination: " << dist[dest] << endl;
}

int main() 
{
    int graph[V][V] = 
    {
        {0, 10, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 15, 0, 0, 0, 0, 30, 0},
        {0, 15, 0, 20, 0, 20, 0, 0, 10},
        {0, 0, 20, 0, 15, 10, 0, 0, 0},
        {0, 0, 0, 15, 0, 25, 0, 0, 0},
        {0, 0, 20, 10, 25, 0, 15, 0, 0},
        {0, 0, 0, 0, 0, 15, 0, 15, 10},
        {0, 30, 0, 0, 0, 0, 10, 0, 15},
        {0, 0, 10, 0, 0, 0, 10, 15, 0}
    };

    int source, destination;
    cout << "Enter source vertex: ";
    cin >> source;
    cout << "Enter destination vertex: ";
    cin >> destination;

    dijkstra(graph, source, destination);
    return 0;
}


/*

    0   1   2   3   4   5   6   7   8
0   0   10  0   0   0   0   0   0   0
1   10  0   15  0   0   0   0   30  0
2   0   15  0   20  0   20  0   0   10
3   0   0   20  0   15  10  0   0   0
4   0   0   0   15  0   25  0   0   0   
5   0   0   20  10  25  0   15  0   0
6   0   0   0   0   0   15  0   15  10
7   0   30  0   0   0   0   10  0   15
8   0   0   10  0   0   0   10  15  0

*/































// #include <iostream>
// #include <climits>
// #include <vector>
// using namespace std;

// #define V 9

// // Function to find the vertex with the minimum distance value
// // from the set of vertices not yet included in the shortest path tree
// int minDistance(int dist[], bool sptSet[]) {
//     int min = INT_MAX, min_index;

//     for (int v = 0; v < V; v++)
//         if (sptSet[v] == false && dist[v] <= min)
//             min = dist[v], min_index = v;

//     return min_index;
// }

// // Function to print the shortest path from source to destination
// void printPath(vector<int>& parent, int j) {
//     // Base Case : If j is source
//     if (parent[j] == -1)
//         return;

//     printPath(parent, parent[j]);
//     cout << j << " ";
// }

// // Function to print the constructed distance array
// void printSolution(int dist[], vector<int>& parent, int src, int dest) {
//     cout << "Vertex \t Distance from Source \t Path\n";
//     for (int i = 0; i < V; i++) {
//         cout << i << " \t " << dist[i] << " \t\t\t ";
//         printPath(parent, i);
//         cout << src << endl;
//     }
// }

// // Function that implements Dijkstra's single source shortest path algorithm
// // for a graph represented using adjacency matrix representation
// void dijkstra(int graph[V][V], int src, int dest) {
//     int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i

//     bool sptSet[V]; // sptSet[i] will be true if vertex i is included in the shortest path tree or shortest distance from src to i is finalized

//     vector<int> parent(V, -1); // Parent array to store the shortest path tree

//     // Initialize all distances as INFINITE and sptSet[] as false
//     for (int i = 0; i < V; i++)
//         dist[i] = INT_MAX, sptSet[i] = false;

//     // Distance of source vertex from itself is always 0
//     dist[src] = 0;

//     // Find shortest path for all vertices
//     for (int count = 0; count < V - 1; count++) {
//         int u = minDistance(dist, sptSet); // Pick the minimum distance vertex from the set of vertices not yet processed
//         sptSet[u] = true; // Mark the picked vertex as processed

//         // Update dist value of the adjacent vertices of the picked vertex
//         for (int v = 0; v < V; v++) {
//             if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
//                 dist[v] = dist[u] + graph[u][v];
//                 parent[v] = u;
//             }
//         }
//     }

//     // Print the shortest path from source to destination and their distances
//     printSolution(dist, parent, src, dest);
// }

// int main() {
//     int graph[V][V] = {
//         {0, 10, 0, 0, 0, 0, 0, 0, 0},
//         {10, 0, 15, 0, 0, 0, 0, 30, 0},
//         {0, 15, 0, 20, 0, 20, 0, 0, 10},
//         {0, 0, 20, 0, 15, 10, 0, 0, 0},
//         {0, 0, 0, 15, 0, 25, 0, 0, 0},
//         {0, 0, 20, 10, 25, 0, 15, 0, 0},
//         {0, 0, 0, 0, 0, 15, 0, 15, 10},
//         {0, 30, 0, 0, 0, 0, 10, 0, 15},
//         {0, 0, 10, 0, 0, 0, 10, 15, 0}
//     };

//     int source, destination;
//     cout << "Enter source vertex: ";
//     cin >> source;
//     cout << "Enter destination vertex: ";
//     cin >> destination;

//     dijkstra(graph, source, destination);
//     return 0;
// }