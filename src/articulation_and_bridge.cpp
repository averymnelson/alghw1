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
                if (depth[v] == -1)
                {
                        children++;
                        parent[v] = curr;
                        artdfs(G, v, d, low, depth, parent, articulationPoints, bridges);
                        if (low[curr] >= low[v])
                        {
                                low[curr] = low[v];
                        }
                        //add to articulation points list
                        if ((parent[v] != -1)&&(low[v] >= depth[curr]))
                        {
                                articulationPoints.push_back(curr);
                        }

                }
                else if (parent[v] != curr)
                {
                        if (depth[v] <= low[curr])
                        {
                                low[curr] = depth[v];
                        }
                }
                //add to bridges
                if (low[v] > depth[curr])
                {
                        std::pair<int, int> bride(curr, v);
                        bridges.push_back(bride);
                }
        }
        if ((parent[curr]== -1)&&children>1){
             articulationPoints.push_back(curr);   
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
