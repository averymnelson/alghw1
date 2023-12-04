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
    std::vector<int> dist(N, N);
    std::vector<int> paths(N, 0);
    std::vector<int> trace(N, -1);
    
    heap.push(start);
    visit[start] = true;
    paths[start]=1;
    while(!heap.empty()){
    return mst;
}
top = heap.top(); 
u = top.u; 
distance = top.w;
        int top = heap.pop();
        if(top == destination){
            sltn = true;
            break;
        }
        
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) 
        {
            u = top;
            int v = p->value;

            if(!visit[v]){
                visit[v] = true;
                heap.push(v);
                trace[v] = top;
                paths[v] = paths[top];
                dist[v] = dist[top] + 1;
            }
            else if(dist[v] == (dist[u]+1)){
                paths[v] = (paths[u]+paths[v]);
            }
        }
        u = destination;
         while (u != -1) {
        mst.push_back(u);
        u = trace[u];
            }
    std::reverse(mst.begin(),mst.end());

    return mst; 
    }

    

// int minKey(std::vector<int> key, std::vector<bool> inMST){
//     int min=INT_MAX;
//     int minIND=0;
//     for(int v=0; v<inMST.size(); v++){
//         if(inMST[v] == false && key[v] <min){
//             min = key[v];
//             minIND = v;
//         }
//     }
//     return minIND;
// }

// std::vector<Edge> constructMSTPrim(Graph G) {
//     std::vector<Edge> edges = G.exportEdges(); // Graph's edges
//     int sum =0;
//     // std::priority_queue< Edge, std::vector<Edge>, EdgeKeyComparison > heap;
//     // If you want to use heap to optimize the minimum searching, you can use heap defined as above
//     //      Insert: heap.push(Edge(u, -1, distance));
//     //      Get Minimum: top = heap.top(); u = top.u; distance = top.w;
//     //      Remove top: heap.pop(); (this function usually goes after the get minimum method)
//     int size = G.getN();
    
//     // YOUR CODE HERE
//     //initialize
//     
//     std::vector<Edge> results;
//     std::priority_queue<Edge, std::vector<Edge>, EdgeKeyComparison > heap;
//     //create first
//     key[0] = 0;
//     parent[0]=-1;
//     //insert
//     for (int ct=0; ct<size-1; ct++){
//         int u = minKey(key, inMST);
//         inMST[u] = true;
//         auto top = heap.top(); 
//         int u = top.u;
//         int wt = top.w;
//         heap.pop();
//         for (int v =0; v<size; v++){
//             if(inMST[v]==false && key[v]>wt){
//                 parent[v] = u;
//                 key[v]=wt;
//             }
//         }
//     }
//     for (int i=1; i<size; i++){
//         std::cout<<"edge: "<<parent[i]<<std::endl;
//     }
//     return edges;
// }

