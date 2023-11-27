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
    int size = G.getN();
    
    // If you want to use heap to optimize the minimum searching, you can use heap defined as above
    //     
    //      Get Minimum: top = heap.top(); u = top.u; distance = top.w;
    //      Remove top: heap.pop(); (this function usually goes after the get minimum method)
    
    // YOUR CODE HERE
    std::vector<int> key(size, INT_MAX);
    std::vector<int> parent(size, -1);
    std::vector<bool> inMST(size, false);
    std::priority_queue< Edge, std::vector<Edge>, EdgeKeyComparison > heap;
    key[0] = 0;
    heap.push(Edge(0, -1, key[0]));
    while(!heap.isEmpty()){
        auto u = heap.poll(); //find node w minimum
        int uVertex = u.dest;
        inMST[uVertex]= true;
        for 

    }

    heap.push(Edge(u, -1, distance));

}

