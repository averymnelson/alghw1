#include <search.hpp>

int rdfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path)
{
    int N = G.n; // Number of nodes in the graph
    std::vector<bool> visit(N, false);
    std::vector<int> trace(N, -1);
    Stack<int> stk;
    stk.push(start);
    visit[start] = true;
    while (!stk.empty())
    {
        int u = stk.pop();
        if (u == destination)
        {
            return 1;
            break;
        }
        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<int> *p = G.e[u].getRoot();
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next)
        {
            int v = p->value;
            if (!visit[v])
            {
                int flag = rdfs(G, v, destination, numberOfBuilding, path);
                if (flag == 1)
                {
                    return 1;
                }
            }
        }
        path.pop_back();
    }
        return 0; // You do not need to count the number of paths in this question, therefore, just simply return 0
}