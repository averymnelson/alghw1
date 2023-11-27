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

    std::priority_queue< Edge, std::vector<Edge>, EdgeKeyComparison > heap;
    // If you want to use heap to optimize the minimum searching, you can use heap defined as above
    //      Insert: heap.push(Edge(u, -1, distance));
    //      Get Minimum: top = heap.top(); u = top.u; distance = top.w;
    //      Remove top: heap.pop(); (this function usually goes after the get minimum method)
    
    // YOUR CODE HERE
    int src =0;
    std::vector<int> key(G.getN(), INT_MAX);
 
    // To store parent array which in turn store MST
    std::vector<Edge> parent(G.getN(), -1);
 
    // To keep track of vertices included in MST
    std::vector<bool> inMST(G.getN(), false);
 
    // Insert source itself in priority queue and initialize
    // its key as 0.
    heap.push(Edge(0, src, 0));
    key[src] = 0;
    while (!heap.empty()){
        auto u = heap.top();
        heap.pop();

        if(inMST[u] == true){
            continue;
        }



    }
}

