#include<iostream>
#include<vector>
using namespace std;

# define INF 999999

class Edge {
    public:
        int source, destination, weight;
        
        Edge(int source, int destination, int weight){
            this->source = source;
            this->destination = destination;
            this->weight = weight;
    }
};

void bellmanFord(int nodes, int edges, vector<Edge> &edgesList, int source){
    vector<int> distance(nodes, INF); // Start with "infinity"
    distance[source] = 0; // Source has 0 distance

    // Relax all edges nodes-1 times
    for(int i = 0; i < nodes - 1; i++){
        for(int j = 0; j < edges; j++){
            int u = edgesList[j].source;
            int v = edgesList[j].destination;
            int w = edgesList[j].weight;
            
            if(distance[u] != INF && distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for(int j = 0; j < edges; j++){
        int u = edgesList[j].source;
        int v = edgesList[j].destination;
        int w = edgesList[j].weight;

        if(distance[u] != INF && distance[u] + w < distance[v]){
            cout<<"Negative weight cycle detected!"<<endl;
            return;
        }
    }

    // Print shortest distances
    cout<<"Shortest distances from source "<<source<<":"<<endl;

    for(int i = 0; i < nodes; i++){
        cout<<"Node "<<i<<": "<<distance[i]<<endl;
    }
}

int main(){
    int nodes = 5; // Number of nodes
    int edges = 8; // Number of edges
    vector<Edge> edgesList;

    // Example graph with a negative cycle
    edgesList.push_back(Edge(0, 1, -1));
    edgesList.push_back(Edge(0, 2, 4));
    edgesList.push_back(Edge(1, 2, 3));
    edgesList.push_back(Edge(1, 3, 2));
    edgesList.push_back(Edge(1, 4, 2));
    edgesList.push_back(Edge(3, 2, 5));
    edgesList.push_back(Edge(3, 1, 1));
    edgesList.push_back(Edge(4, 3, -3));

    // Running Bellman-Ford algorithm with source node 0
    bellmanFord(nodes, edges, edgesList, 0);
    return 0;
}
