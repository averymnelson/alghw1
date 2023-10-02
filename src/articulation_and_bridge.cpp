#include <graph.hpp>
#include <search.hpp>

// To create a pair of node u and v, you can use the following template
// std::pair<int, int> bride(u, v);
 
// void DFS(std::vector<int> &disc, std::vector<int> &low, std::vector<int> &visited, std::vector<int> parent, int vertex){
//         visited[vertex] = true;
//         int temp = time + 1;
//         disc[vertex] = temp;
//         low[vertex] = temp;
//         int child = 0;
//         int nAdjnodes = G.e[vertex].size();
//         LinkedListNode<int> *p = G.e[vertex].getRoot();
//         for (int i = 0; i < nAdjnodes; i++, p = p->next)
//         {
//             int v = p->value;
//                         if (!visited[i]){
//                                 child = child + 1;
//                                 parent[i] = vertex;
//                                 DFS(disc, low, visited, parent, i, time+1);
//                                 low[vertex] = min(low[vertex], low[i]);
//                                 if (low[i] > disc[vertex]){
//                                         std::cout<<vertex<<" "<<i<<std::endl;
//                                         //print vertex, i //bridge
//                                 }
//                         }
//                         else if (parent[vertex] != i){
//                                 low[vertex] = minimum(low[vertex], disc[i])
//                         }
//         }
// }

void findArticulationPointsAndBridges(Graph &G, std::vector<int> &articulationPoints, std::vector<std::pair<int, int> > &bridges)
{
//     int n = G.n; // Number of Nodes
//     int time = 0;
//     DFS(time, time, visited, parent, vertex)
}
