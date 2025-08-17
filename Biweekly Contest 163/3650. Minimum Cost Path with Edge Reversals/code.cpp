class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Create adjacency list: each node stores pairs of (neighbor, weight)
        vector<vector<pair<int, int>>> adj(n);

        // Build the graph
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt}); // Normal edge u -> v with weight wt
            adj[v].push_back(
                {u, 2 * wt}); // Reverse edge v -> u with **double weight**
        }

        // Min-heap (priority queue) for Dijkstra: (currentDist, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        // Distance array: initialize all distances to infinity
        vector<int> dist(n, INT_MAX);

        // Start from node 0
        pq.push({0, 0});
        dist[0] = 0;

        // Standard Dijkstra’s algorithm
        while (!pq.empty()) {
            int node = pq.top().second; // Current node
            int wt = pq.top().first;    // Distance so far
            pq.pop();

            // Skip if we already have a better distance
            if (dist[node] < wt)
                continue;

            // If we reached the target node (n-1), return its distance
            if (node == n - 1)
                return wt;

            // Relax all neighbors
            for (auto it : adj[node]) {
                int edgeNode = it.first; // Neighbor node
                int edgeWt = it.second;  // Weight of the edge

                // Relaxation check
                if (dist[edgeNode] > edgeWt + wt) {
                    dist[edgeNode] = edgeWt + wt;
                    pq.push({dist[edgeNode], edgeNode});
                }
            }
        }

        // If node (n-1) is unreachable, return -1
        return -1;
    }
};
