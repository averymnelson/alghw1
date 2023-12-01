#include <graph.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<int> searchShortestPath(Graph &G, int start, int destination) {
    
    // std::priority_queue< Edge, std::vector<Edge>, EdgeKeyComparison > heap;
    // If you want to use heap to optimize the minimum searching, you can use heap defined as above
    //      Insert: heap.push(Edge(u, -1, distance));
    //      Get Minimum: top = heap.top(); u = top.u; distance = top.w;
    //      Remove top: heap.pop(); (this function usually goes after the get minimum method)
    
    // YOUR CODE HERE
    int numVertices = G.getN();
    std::vector<int> distance(numVertices, std::numeric_limits<int>::max());
    std::vector<int> parent(numVertices, -1);
    std::vector<bool> visited(numVertices, false);

    distance[start] = 0;
    parent[start] = -1;
    std::priority_queue< Edge, std::vector<Edge>, EdgeKeyComparison > heap;
    heap.push({start, -1, 0});

    while(!heap.empty()){
        Edge top = heap.top();
        heap.pop();
        int u = top.u;
        int dist = top.w;
        if(visited[u]){
            continue;
        }
        visited[u] = true;
        if(u == destination){
            break;
        }
        std::vector<std::pair<int, int>> neighbors = G.getAdjacencyList(u);
        for(const auto& neighbor: neighbors){
            int v = neighbor.first;
            int weight = neighbor.second;

            if(distance[u] + weight < distance[v]){
                distance[v] = distance[u] + weight;
                parent[v] = u;
                heap.push({v, -1, distance[v]});
            }
        }
    }

    std::vector<int> path;
    int u = destination;
    while(u != -1){
        path.insert(path.begin(), u);
        u = parent[u];
    }
    return path;
}

// int numVertices = G.getN();
//     std::vector<int> distance(numVertices, std::numeric_limits<int>::max());
//     std::vector<int> parent(numVertices, -1);
//     std::vector<bool> visited(numVertices, false);

//     distance[start] = 0;
//     parent[start] = -1;
//     std::priority_queue< Edge, std::vector<Edge>, EdgeKeyComparison > heap;
//     heap.push({start, -1, 0});

//     while(!heap.empty()){
//         Edge top = heap.top();
//         heap.pop();
//         int u = top.u;
//         int dist = top.w;
//         if(visited[u]){
//             continue;
//         }
//         visited[u] = true;
//         if(u == destination){
//             break;
//         }
//         std::vector<std::pair<int, int>> neighbors = G.getAdjacencyList(u);
//         for(const auto& neighbor: neighbors){
//             int v = neighbor.first;
//             int weight = neighbor.second;

//             if(distance[u] + weight < distance[v]){
//                 distance[v] = distance[u] + weight;
//                 parent[v] = u;
//                 heap.push({v, -1, distance[v]});
//             }
//         }
//     }

//     std::vector<int> path;
//     int u = destination;
//     while(u != -1){
//         path.insert(path.begin(), u);
//         u = parent[u];
//     }
//     return path;
// }
// #include <graph.hpp>
// #include <queue>

// struct EdgeKeyComparison {
//     constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
//         return a.w > b.w;
//     }
// };

// // std::vector<int> searchShortestPath(Graph &G, int start, int destination) {
// //     int N = G.getN();
// //     std::vector<int> vertex (N, INT_MAX);
// //     std::vector<int> dist (N, INT_MAX);
// //     std::vector<int> parent(N, -1);
// //     std::vector<bool> inMST(N, false);

    
// //     // std::priority_queue< Edge, std::vector<Edge>, EdgeKeyComparison > heap;
// //     // If you want to use heap to optimize the minimum searching, you can use heap defined as above
// //     //      Insert: heap.push(Edge(u, -1, distance));
// //     //      Get Minimum: top = heap.top(); u = top.u; distance = top.w;
// //     //      Remove top: heap.pop(); (this function usually goes after the get minimum method)

// //     Stack<int> s;
// //     s.push(start);
// //     std::vector<int> distance(N, 1000000);
// //     std::vector<int> trace(N, -1);
// //     distance[start] = 1;
// //     while (!s.empty())
// //     {
// //         int st = s.pop();
// //         if (st == destination && distance[st] <= N)
// //         {
// //             break;
// //         }
// //         int nAdjnodes = G.e[st].size();
// //         LinkedListNode<int> *p = G.e[st].getRoot();
// //         for (int i = 0; i < nAdjnodes; i++, p = p->next)
// //         {
// //             int v = p->value;
// //             if (distance[st] + 1 < distance[v])
// //             {
// //                 s.push(v);
// //                 distance[v] = distance[st] + 1;
// //                 trace[v] = st;
// //             }
// //         }
// //     }
// //     int u = destination;
// //     while (u != -1) {
// //         path.push_back(u);
// //         u = trace[u];
// //     }

// //     std::reverse(path.begin(),path.end());
    
// //     return 0;

// // }
