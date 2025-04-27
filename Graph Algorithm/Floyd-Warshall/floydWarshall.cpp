#include<iostream>
#include<vector>
using namespace std;

# define INF 1000000000

// Floyd-Warshall function
void floydWarshall(vector<vector<int>> &graph) {
    int V = graph.size();
    
    // Distance matrix starts same as graph
    vector<vector<int>> dist = graph;

    // Trying every node as an intermediate node
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                // If path through k is shorter, update it
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Printing shortest distance matrix
    cout << "Shortest distances between every pair:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }

        cout << endl;
    }
}

int main() {
    // Example graph (4 nodes)
    vector<vector<int>> graph = {
    {0, 5, INF, 10},
    {INF, 0, 3, INF},
    {INF, INF, 0, 1},
    {INF, INF, INF, 0}
    };

    floydWarshall(graph);
    return 0;
}