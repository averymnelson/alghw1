#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};



std::vector<Edge> constructMSTPrim(Graph G) {
std::vector<Edge> edges = G.exportEdges(); // Graph's edges
    int numVertices = G.getN();
    std::vector<bool> visited(numVertices, false);
    std::vector<Edge> mst;
    
    // Start Prim's algorithm from vertex 0 (or any other starting vertex)
    visited[0] = true;
    std::priority_queue<Edge, std::vector<Edge>, EdgeKeyComparison> heap;
    for (const Edge &e : edges) {
        if (e.u == 0) {
            heap.push(e);
        }
    }
    
    while (!heap.empty()) {
        Edge minEdge = heap.top();
        heap.pop();
        
        if (visited[minEdge.v]) {
            continue;
        }
        
        // Add the minimum edge to the MST
        mst.push_back(minEdge);
        visited[minEdge.v] = true;
        
        // Explore neighbors of the newly added vertex
        for (const Edge &e : edges) {
            if (e.u == minEdge.v && !visited[e.v]) {
                heap.push(e);
            }
        }
    }
    
    return mst;
}