#include <search.hpp>
#include <vector>

/* Template Code 
Five steps: 
create a queue Q
mark v as visited and put v into Q
while Q is non-empty
    remove the head u of Q
    mark and enqueue all (unvisited) neighbors of u

To iterate over the adjancy nodes of u, you can use the following template code 
int numberOfAdjacencyNodes = G.e[u].size(); // Get number of adjancy nodes of u 
LinkedListNode<int> *p = G.e[u].getRoot(); // Get the head point of the linked list
for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) { // iterate over each node
    int v = p->value; // v is the adjvancy node of u
    // YOUR CODE HERE
}

 
*/

int bfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path) {
    // Please ignore the parameter of numberOfBuilding, this parameter is only used in DFS and Recursive DFS
    // Return the number of shortest path

    int N = G.n; // Number of nodes in the graph
    //YOUR CODE HERE 
    int u = 0;

    std::vector<bool> visit(N, false);
    std::vector<int> trace(N, false);
    Queue<int> q;
    int numberOfAdjacencyNodes = G.e[u].size();
    LinkedListNode<int> *p = G.e[u].getRoot();

    for(int u = 0; u < N-1; u++){
        visit[u] = false;
        trace[u] = -1;
    }
    q.push(start);
    visit[start] = true;
    
    while(!q.empty()){
        u = q.pop();
        if(u == destination){
            return u;
            //break;
        }

        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) { // iterate over each node
            int v = p->value; // v is the adjvancy node of u
             // YOUR CODE HERE
             if(!visit[v]){
                visit[v] = true;
                trace[v] = u;
                q.push(v);
             }
        }
    }
    u = destination;

    while( u != -1){
        u = trace[u];
    }
    
    // Finally return the number of shorest paths
    return 0; // Modify this return value to the correct one 
}
