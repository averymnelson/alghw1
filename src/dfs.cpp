#include <search.hpp>
#include <vector>

int dfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path)
{
    int N = G.n; // Number of nodes in the graph
    int p = 0;
    std::string pw = "";
    std::vector<bool> visit(N, false);
    std::vector<int> trace(N, -1);
    Stack<int> s;
    s.push(start);
    visit[start] = true;
    while (!s.empty())
    {
        int st = s.pop();
        if (st == destination)
        {
            break;
        }
        visit[st] = true;
        int nAdjnodes = G.e[st].size();
        LinkedListNode<int> *p = G.e[st].getRoot();
        for (int i = 0; i < nAdjnodes; i++, p = p->next)
        {
            int v = p->value;
            if (!visit[v])
            {
                visit[v] = true;
                s.push(v);
            }
        }
    }
    int u = destination;
    while (u != -1) {
        path.push_back(u);
        u = trace[u];
    }

    return 0; // You do not need to count the number of paths in this question, therefore, just simply return 0
}
