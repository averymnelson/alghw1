#include <search.hpp>

int rdfsutil(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path, std::vector<int> &distance)
{
    path.push_back(start);
    int N = G.n;
    distance[start] = path.size();
    if (path.size() > numberOfBuilding)
    {
        //std::cout << "Path length greater than number of buildings." << std::endl;
        path.pop_back();
        return 0;
    }
    if (start == destination)      
    {
        if (distance[start] <= numberOfBuilding)
            return 1;
        else {
            path.pop_back();
            return 0;
        }
    }
    
    int numberOfAdjacencyNodes = G.e[start].size();
    LinkedListNode<int> *p = G.e[start].getRoot();
    for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next)
    {
        int v = p->value;
        if ((distance[start] + 1) < distance[v])
        {
            int flag = rdfsutil(G, v, destination, numberOfBuilding, path, distance);
            if (flag == 1)
                return 1;
        }
    }
    path.pop_back();
    return 0;
}

int rdfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path)
{
    path.clear();
    int N = G.n;
    std::vector<int> distance(N, 1000000);
    rdfsutil(G, start, destination, numberOfBuilding, path, distance);
    return 0;
}
