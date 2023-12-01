#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>


std::vector<Edge> constructMSTKruskal(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges
    // DisjointSet djs(G.n); 
    // Use Disjoint Set to check wheter two vertices are on the same set
    // Usage: Check djs.isOnSameSet(u, v); Check is u and v is on the same set or not
    //              djs.join(u, v); Join sets of u and v into the same set
    
    // YOUR CODE HERE
        //Sort the edges by weight
    //For each edge e in sorted list do
        std::sort(edges.begin(), edges.end());
    
    DisjointSet d(G.getN()); //cannot access number of vertices?
    std::vector<Edge> mst;

    for(const Edge& edge : edges){
        int u = edge.u;
        int v = edge.v;
        if(!d.isOnSameSet(u, v)){
            mst.push_back(edge);
            d.join(u,v);
        }
    }
    return mst;
}
