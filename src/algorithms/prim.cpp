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
    int u = 0; 
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges
    std::vector<Edge> mst;
    int size = G.getN();
    std::priority_queue< Edge, std::vector<Edge>, EdgeKeyComparison > heap;
    // If you want to use heap to optimize the minimum searching, you can use heap defined as above
    //      Insert: heap.push(Edge(u, -1, distance));
    //      Get Minimum: top = heap.top(); u = top.u; distance = top.w;
    //      Remove top: heap.pop(); (this function usually goes after the get minimum method)
    
    std::vector<bool> visit(N, false);
    std::vector<int> parent(N, -1);
    std::vector<int> key(N, INT_MAX);
    heap.push(0, -1, distance);
    key[0]=0;

    while (!heap.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
        auto top = heap.top();
        u = top.u; 
        auto distance = top.w;
        heap.pop();
         
          //Different key values for same vertex may exist in the priority queue.
          //The one with the least key value is always processed first.
          //Therefore, ignore the rest.
          if(inMST[u] == true){
            continue;
        }
       
        inMST[u] = true;  // Include vertex in MST
 
        // 'i' is used to get all adjacent vertices of a vertex
        for (auto i : e[u])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = e[u][i].v;
            int weight = e[u][i].w;
 
            //  If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                heap.push(u, v, weight);
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
    return mst;
}