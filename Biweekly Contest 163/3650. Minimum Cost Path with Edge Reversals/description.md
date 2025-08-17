## 🎯 Catch of the Question

The graph is **not a standard undirected weighted graph**.  

Instead, the edges are **directional with different costs**:

- Going from **u → v** costs `wt`.  
- But going **backward (v → u)** costs `2 * wt`.  

This **asymmetry** is the catch.  
Normally, in undirected graphs, both directions have the same weight.  
Here, the backward direction is intentionally penalized with a doubled cost.  

That’s why during graph construction:

```cpp
adj[u].push_back({v, wt});      // forward with normal weight
adj[v].push_back({u, 2 * wt});  // backward with doubled weight
```
And that’s why you need Dijkstra’s algorithm (not BFS), because edge weights are not uniform.

## ✅ So the catch is:

You must correctly model the graph with different costs depending on the direction of traversal, otherwise the shortest path result will be wrong.
