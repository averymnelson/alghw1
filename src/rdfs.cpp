#include <search.hpp>

int rdfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path)
{
    path.clear();
    int N = G.n;
    std::vector<bool> visit(N, false);
    std::vector<int> numps(N, 0);
    rdfsutil(G, start, destination, numberOfBuilding, path, visit, numps);
    return 0; // You do not need to count the number of paths in this question, therefore, just simply return 0
}
int rdfsutil(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path, std::vector<bool> &visit, std::vector<int> &numps)
{
    int N = G.n;
    visit[start] = true;
    if (path.size() > numberOfBuilding)
    {
        std::cout << "Path length greater than number of buildings." << std::endl;
        return 0;
    }
    if (start == destination)
    {
        path.push_back(start);
    }else{
    int numberOfAdjacencyNodes = G.e[start].size();
    LinkedListNode<int> *p = G.e[start].getRoot();
    for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next)
    {
        int v = p->value;
        if (!visit[v])
        {
            rdfsutil(G, v, destination, numberOfBuilding, path, visit, numps);
        }
    }
    }
    numps[path.size()]++;

    return 0;
}

// int numberOfAdjacencyNodes = G.e[u].size();
// LinkedListNode<int> *p = G.e[u].getRoot();
// for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next)
// {
//     int v = p->value;
//     if (!visit[v])
//     {
//         int flag = rdfs(G, v, destination, numberOfBuilding, path);
//         if (flag == 1)
//         {
//             return 1;
//         }
//     }
// }
// if(!sltn){
//     std::cout<<"These buildings do not appear to be connected."<<std::endl;
//     return -1;
// }else if(numberOfBuilding>=path.size()){
//     return numberOfBuilding;
// }else{
//     return path.size();
// }