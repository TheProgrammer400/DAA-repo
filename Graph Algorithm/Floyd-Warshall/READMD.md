# Floyd-Warshall Algorithm

This file contains a simple C++ implementation of the Floyd-Warshall algorithm, which finds the shortest paths between all pairs of vertices in a weighted graph.

---

## About Floyd-Warshall

- Computes shortest distances between every pair of vertices.
- Supports graphs with negative weight edges.
- Cannot be used if the graph contains a negative weight cycle.
- Based on Dynamic Programming.
- Time Complexity: **O(V³)**, where V is the number of vertices.

---

## How It Works

- Initialize a distance matrix using the input graph.
- For each node `k`, update every pair `(i, j)` by checking if the path `i -> k -> j` is shorter than the direct path `i -> j`.
- Repeat this process for all vertices as intermediate nodes.

**Update Rule:**

```cpp
if (dist[i][k] + dist[k][j] < dist[i][j]) {
    dist[i][j] = dist[i][k] + dist[k][j];
}
```

---

## Example Graph

The example graph used in the code:

| From/To | 0   | 1   | 2   | 3   |
|:-------:|:---:|:---:|:---:|:---:|
| 0       | 0   | 5   | INF | 10  |
| 1       | INF | 0   | 3   | INF |
| 2       | INF | INF | 0   | 1   |
| 3       | INF | INF | INF | 0   |

Here, `INF` represents a very large value (used to represent no direct path).

---

## Sample Output

```
Shortest distances between every pair:
0 5 8 9
INF 0 3 4
INF INF 0 1
INF INF INF 0
```

---

## Important Notes

- `INF` is defined as `1000000000` in the code.
- Avoid using `1e9` directly without converting it to an integer type.
- The algorithm assumes there are no negative weight cycles in the input graph.
