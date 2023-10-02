#include <graph.hpp>
#include <search.hpp>

void artdfs(Graph &G, int curr, int d, std::vector<int> &low, std::vector<int> &depth, std::vector<int> &parent, std::vector<int> &articulationPoints, std::vector<std::pair<int, int>> &bridges)
{
        low[curr] = d;
        depth[curr] = d;
        d++;
        int children = 0;
        int numberOfAdjacencyNodes = G.e[curr].size();
        LinkedListNode<int> *p = G.e[curr].getRoot();
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next)
        {
                int v = p->value;
                parent[v] = curr;
                depth[v]=d;
                if (depth[v] == -1)
                {
                        children++;
                        artdfs(G, v, d, low, depth, parent, articulationPoints, bridges);
                        low[curr]  = std::min(low[curr], low[v]);
                        if (depth[curr] < low[v])
                        {
                                articulationPoints.push_back(curr);
                        }
                }
                else
                {
                        low[curr] = std::min(low[curr], depth[v]);
                }

                if (depth[curr] < low[v])
                {
                        std::pair<int, int> bride(curr, v);
                        bridges.push_back(bride);
                }
                else
                {
                        low[curr] = std::min(low[curr], depth[v]);
                }
        }
}

void findArticulationPointsAndBridges(Graph &G, std::vector<int> &articulationPoints, std::vector<std::pair<int, int>> &bridges)
{
        int n = G.n; // Number of Nodes
        int curr = 0;
        int d = 0;
        std::vector<int> low(n, -1);
        std::vector<int> depth(n, -1);
        std::vector<int> parent(n, -1);
        artdfs(G, curr, d, low, depth, parent, articulationPoints, bridges);
}
