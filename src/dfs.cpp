#include <search.hpp>
#include <vector>

int dfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path)
{
    int N = G.n; // Number of nodes in the graph
    bool sltn = false;
    std::vector<bool> visit(N, false);
    Stack<int> s;
    s.push(start);
    visit[start] = true;
    while (!s.empty())
    {
        int st = s.pop();
        if (st == destination)
        {
            sltn = true;
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
                if (v == destination){
                    path.push_back(v);
                }
            }
        }
    }
    std::reverse(path.begin(),path.end());
    if(!sltn){
        std::cout<<"These buildings do not appear to be connected."<<std::endl;
        return -1;
    }else if(numberOfBuilding>=path.size()){
        return numberOfBuilding;
    }else{
        return path.size();
    }
}
