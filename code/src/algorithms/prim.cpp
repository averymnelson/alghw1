#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

int minKey(std::vector<int> key, std::vector<bool> inMST){
    int min=INT_MAX;
    int minIND=0;
    for(int v=0; v<inMST.size(); v++){
        if(inMST[v] == false && key[v] <min){
            min = key[v];
            minIND = v;
        }
    }
    return minIND;
}

std::vector<Edge> constructMSTPrim(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges
    int sum =0;
    // std::priority_queue< Edge, std::vector<Edge>, EdgeKeyComparison > heap;
    // If you want to use heap to optimize the minimum searching, you can use heap defined as above
    //      Insert: heap.push(Edge(u, -1, distance));
    //      Get Minimum: top = heap.top(); u = top.u; distance = top.w;
    //      Remove top: heap.pop(); (this function usually goes after the get minimum method)
    int size = G.getN();
    
    // YOUR CODE HERE
    //initialize
    std::vector<int> key(size, INT_MAX);
    std::vector<int> parent(size, -1);
    std::vector<bool> inMST(size, false);
    std::vector<Edge> results;
    std::priority_queue<Edge, std::vector<Edge>, EdgeKeyComparison > heap;
    //create first
    key[0] = 0;
    parent[0]=-1;
    //insert
    for (int ct=0; ct<size-1; ct++){
        int u = minKey(key, inMST);
        inMST[u] = true;
        auto top = heap.top(); 
        int u = top.u;
        int wt = top.w;
        heap.pop();
        for (int v =0; v<size; v++){
            if(inMST[v]==false && key[v]>wt){
                parent[v] = u;
                key[v]=wt;
            }
        }
    }
    for (int i=1; i<size; i++){
        std::cout<<"edge: "<<parent[i]<<std::endl;
    }
    return edges;
}

