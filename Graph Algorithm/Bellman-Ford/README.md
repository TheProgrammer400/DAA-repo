# Bellman-Ford Algorithm: Negative Cycle Detection

In the **Bellman-Ford** algorithm, we detect the presence of **negative weight cycles** by performing a special check after completing the main relaxation process. Here's how it works:

1. **Relaxation Process:**
   - The algorithm iteratively relaxes all edges in the graph for `V - 1` times, where `V` is the number of vertices. During each iteration, the algorithm attempts to update the shortest known distance to each vertex.

2. **Final Check:**
   - After `V - 1` relaxations, the algorithm performs an additional check to see if any edge can still be relaxed (i.e., its distance can be improved). This extra check is crucial because if an edge can still be relaxed, it implies the presence of a **negative weight cycle**.

3. **Why this check is necessary:**
   - A negative weight cycle is a cycle in the graph where the total weight of the cycle is negative, and repeatedly traveling through this cycle would keep decreasing the total path weight. After performing `V - 1` relaxations, if an edge can still be relaxed, it means there's a negative cycle that affects the shortest path.

4. **The Code Logic:**
   - The code looks like this:

     ```cpp
     for(int j = 0; j < edges; j++) {
         int u = edgesList[j].source;
         int v = edgesList[j].destination;
         int w = edgesList[j].weight;
         
         // Check if this edge can still be relaxed
         if(distance[u] != INF && distance[u] + w < distance[v]) {
             cout << "Negative weight cycle detected!" << endl;
             return;
         }
     }
     ```

   - **Key points in the code:**
     - `distance[u] + w < distance[v]`: Checks if traveling from `u` to `v` through the edge `(u, v, w)` can reduce the current known shortest distance to `v`. If yes, it indicates a negative cycle.
     - `distance[u] != INF`: Ensures that the source node `u` is reachable (i.e., not at an infinite distance).
     
5. **Conclusion:**
   - If the check finds any edge that can still be relaxed, it signals the existence of a negative weight cycle in the graph, and the algorithm terminates early with a message indicating the detection.

### Why it matters:
Negative weight cycles can cause algorithms that compute shortest paths to fail or produce incorrect results, which is why detecting them early is critical.




## Difference Between Bellman-Ford and Dijkstra’s Algorithm

Both **Bellman-Ford** and **Dijkstra’s** algorithms are used to find the **shortest path** from a source node to all other nodes in a weighted graph. However, there are some important differences between the two algorithms. Here's a breakdown:

---

#### 1. **Handling of Negative Weight Edges**
   - **Bellman-Ford**: 
     - Can handle **negative weight edges**.
     - It checks for negative weight cycles and can report their presence.
   - **Dijkstra’s**: 
     - Does **not work correctly** with negative weight edges. 
     - If there are negative edges in the graph, it may give incorrect results.

---

#### 2. **Time Complexity**
   - **Bellman-Ford**:
     - Time complexity: **O(V * E)**, where `V` is the number of vertices and `E` is the number of edges.
     - It is slower compared to Dijkstra’s for graphs with many edges.
   - **Dijkstra’s**:
     - Time complexity with a priority queue: **O((V + E) * log(V))** (using a binary heap).
     - It is faster than Bellman-Ford when there are fewer edges and no negative weights.

---

#### 3. **Algorithm Approach**
   - **Bellman-Ford**:
     - Uses **relaxation** of all edges `V-1` times (where `V` is the number of vertices).
     - It systematically checks every edge multiple times, ensuring the shortest path is found, even in graphs with negative weight edges.
   - **Dijkstra’s**:
     - Uses a **greedy approach** with a priority queue (min-heap) to explore the nearest node at each step.
     - It selects the node with the smallest tentative distance, works on it, and then updates the distance of its neighbors.

---

#### 4. **Negative Weight Cycle Detection**
   - **Bellman-Ford**:
     - Can detect **negative weight cycles** in the graph.
     - After `V-1` iterations, if any edge can still be relaxed, it indicates a negative cycle.
   - **Dijkstra’s**:
     - Does **not detect negative weight cycles**.
     - Since it doesn’t handle negative edges, cycles with negative weights can lead to incorrect results.

---

#### 5. **Graph Types**
   - **Bellman-Ford**:
     - Can work on graphs with **directed** or **undirected** edges, and handles **negative weight edges**.
   - **Dijkstra’s**:
     - Works on **directed** and **undirected** graphs, but assumes that all edge weights are **non-negative**.

---

#### 6. **Applications**
   - **Bellman-Ford**:
     - Useful in cases where the graph has **negative edges** or you need to detect **negative weight cycles**.
     - Commonly used in scenarios like finding shortest paths in graphs with possible negative weights (e.g., currency exchange, routing protocols).
   - **Dijkstra’s**:
     - Typically used when the graph has **non-negative edges** and speed is a priority.
     - Common in applications like road network shortest path finding or routing in communication networks.

---

### Summary of Key Differences:

| Feature                       | **Bellman-Ford**                           | **Dijkstra’s**                           |
|-------------------------------|--------------------------------------------|------------------------------------------|
| **Negative Weight Edges**      | Handles negative weight edges              | Does not handle negative weight edges    |
| **Time Complexity**            | O(V * E)                                   | O((V + E) * log(V))                      |
| **Cycle Detection**            | Can detect negative weight cycles          | Cannot detect negative weight cycles     |
| **Algorithm Type**             | Dynamic programming (relaxation)           | Greedy approach with a priority queue    |
| **Graph Types**                | Works with negative weight edges           | Only works with non-negative weights     |

---

### Conclusion:
- **Bellman-Ford** is more versatile, but slower and used for graphs with negative weights or to detect negative weight cycles.
- **Dijkstra’s** is faster for graphs with only non-negative weights, but it can fail with negative edges.


