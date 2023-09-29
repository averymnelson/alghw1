#include <search.hpp>
#include <vector>

int bfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path) {
    path.clear();
    int N = G.n;
    bool sltn = false;
    //std::vector<int> stpath;
    int u = 0; 

    std::vector<bool> visit(N, false);
    std::vector<int> dist(N, N);
    std::vector<int> paths(N, 0);
    
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
            int v = p->value;
            if(!visit[v]){
                visit[v] = true;
                q.push(v);
            }
            if(dist[v]>(dist[u]+1)){
                dist[v] = dist[u]+1;
                paths[v]=paths[u];
            }else if(dist[v] == (dist[u]+1)){
                paths[v] = (paths[u]+path[v]);
            }
        }
    }
    if (!sltn){
        std::cout<<"These buildings do not appear to be connected."<<std::endl;
        return -1;
    }else{
    // path.push_back(u);
    // while(prev[u] != -1){
    //     path.push_back(prev[u]);
    //     u = prev[u];
    // }

    // std::reverse(path.begin(),path.end());

    return paths[destination]; 
    }
}
