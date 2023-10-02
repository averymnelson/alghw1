#include <graph.hpp>
#include <search.hpp>

// TAComent int d --> int &d. Since d is the varialble represents for the time of visiting, it should be a global varialble. Thus, we should declare it as a reference. Otherwise, it will be reset after exits the DFS which mean return the incorrect time of visit.
// void
// This function should return the number of childrens since we will use the number of childrens to determine the articulation point of the root
int artdfs(Graph &G, int curr, int &d, std::vector<int> &low, std::vector<int> &depth, std::vector<int> &parent, std::vector<int> &articulationPoints, std::vector<std::pair<int, int>> &bridges)
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
                // parent[v] = curr; // TA Code: Do not set parents here. We only set parent if this vertex has been not visited yet.
                // depth[v]=d; Do not set depth[v] here, we set it the begining of DFS when we visit a node
                if (v == parent[curr]) // We do not travel back to parent
                        continue;
                if (depth[v] == -1)
                {
                        parent[v] = curr; // Set parent v = curr
                        children++;
                        artdfs(G, v, d, low, depth, parent, articulationPoints, bridges);
                        low[curr] = std::min(low[curr], low[v]);
                        if (depth[curr] <= low[v]) // TA Code: it should be depth[curr] <= low[v] since we consider v cannot visit ancesstor of curr without visiting curr
                        {
                                // TA Comment: if curr already inserted in to articluationPoints, we do not need to add it again
                                if (std::find(articulationPoints.begin(), articulationPoints.end(), curr) == articulationPoints.end()) // Check if curr is not availble in the array
                                        articulationPoints.push_back(curr);
                        }

                        if (depth[curr] < low[v])
                        {
                                std::pair<int, int> bride(curr, v);
                                bridges.push_back(bride);
                        }
                }
                else
                {
                        low[curr] = std::min(low[curr], depth[v]); // TA Comment: Line (A)
                }

                /*if (depth[curr] < low[v]) // TA Comment: This one only need to be consider for the vertex v that has not been visited yet
                {
                        std::pair<int, int> bride(curr, v);
                        bridges.push_back(bride);
                }
                else // TA Comment: You do not need to consider this case since it is the same with Line (A)
                {
                        low[curr] = std::min(low[curr], depth[v]);
                }*/
        }
        return children;
}

void findArticulationPointsAndBridges(Graph &G, std::vector<int> &articulationPoints, std::vector<std::pair<int, int>> &bridges)
{
        int n = G.n; // Number of Nodes
        int curr = 0;
        int d = 0;
        std::vector<int> low(n, -1);
        std::vector<int> depth(n, -1);
        std::vector<int> parent(n, -1);
        int children = artdfs(G, curr, d, low, depth, parent, articulationPoints, bridges);

        // if the root has only one children, it cannot be a articulation point since it remove this node, it will not affect to the current connect graph
        if (children <= 1)
        {
                auto lie = std::find(articulationPoints.begin(), articulationPoints.end(), 0); // 0 is the root of DFS
                if (lie != articulationPoints.end())                                           // we found 0 in the articulationPoints, then we have to remove it
                        articulationPoints.erase(lie, lie + 1);
        }
        else
        {                                                                                                           // if the root has more than 1 chilren, absolutely, it is an articulation point since if we remove it, these chilrens will be disconnected
                if (std::find(articulationPoints.begin(), articulationPoints.end(), 0) == articulationPoints.end()) // Check if curr is not availble in the array
                        articulationPoints.push_back(0);
        }
}
