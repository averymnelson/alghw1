#include <search.hpp>
#include <vector>

int dfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path)
{
    int N = G.n;
    Stack<int> s;
    s.push(start);
    std::vector<int> distance(N, 0);
    std::vector<int> trace(N, -1);
    distance[start] = 1;
    while (!s.empty())
    {
        int st = s.pop();
        if (st == destination && distance[st] <= numberOfBuilding)
        {
            break;
        }
        int nAdjnodes = G.e[st].size();
        LinkedListNode<int> *p = G.e[st].getRoot();
        for (int i = 0; i < nAdjnodes; i++, p = p->next)
        {
            int v = p->value;
            if (distance[st] + 1 < distance[v])
            {
                s.push(v);
                distance[v] = distance[st] + 1;
                trace[v] = st;
            }
        }
    }
    int u = destination;
    while (u != -1) {
        path.push_back(u);
        u = trace[u];
    }

    std::reverse(path.begin(),path.end());
    
    return 0;
}
