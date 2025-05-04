#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

bool bfs(vector<vector<int>> &rGraph, int source, int target, vector<int> &parent){
    int n = rGraph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 0; v < n; v++){
            if(!visited[v] && rGraph[u][v] > 0){
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return visited[target];
}

int fordFulkerson(vector<vector<int>> &graph, int source, int target){
    int n = graph.size();
    vector<vector<int>> rGraph = graph; // residual graph
    vector<int> parent(n);
    int maxFlow = 0;

    while(bfs(rGraph, source, target, parent)){
        int pathFlow = INT_MAX;

        // Find minimum capacity in the path
        for(int v = target; v != source; v = parent[v]){
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        // Update residual capacities
        for(int v = target; v != source; v = parent[v]){
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main(){
    // Example: 6 nodes, node 0 is source, node 5 is sink
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0, sink = 5;
    cout << "Max Flow: " << fordFulkerson(graph, source, sink) << endl;

    return 0;
}
