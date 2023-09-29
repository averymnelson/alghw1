#include <search.hpp>
#include <vector>

int bfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path) {
    path.clear();
    int N = G.n;
    bool sltn = false;
    int u = 0; 

    std::vector<bool> visit(N, false);
    std::vector<int> dist(N, N);
    std::vector<int> paths(N, 0);
    std::vector<int> trace(N, -1);
    
    Queue<int> q;
    q.push(start);
    visit[start] = true;
    paths[start]=1;
    while(!q.empty()){
        int top = q.pop();
        if(top == destination){
            sltn = true;
            break;
        }
        
        int numberOfAdjacencyNodes = G.e[top].size();
        LinkedListNode<int> *p = G.e[top].getRoot();
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) 
        {
            u = top;
            int v = p->value;

            if(!visit[v]){
                visit[v] = true;
                q.push(v);
                trace[v] = top;
                paths[v] = paths[top];
                dist[v] = dist[top] + 1;
            }
            else if(dist[v] == (dist[u]+1)){
                paths[v] = (paths[u]+paths[v]);
            }
        }
    }

    if (!sltn){
        std::cout<<"These buildings do not appear to be connected."<<std::endl;
        return -1;
    }else{
    u = destination;
    while (u != -1) {
        path.push_back(u);
        u = trace[u];
    }
    std::reverse(path.begin(),path.end());

    return paths[destination]; 
    }
}
