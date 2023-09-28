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
    std::vector<int> trace(N, -1);
    
    //Loop through all nodes in the vectors. Set visited to false & trace to -1
    for(int i = 0; i < N - 1; i++)
    {
        visit[i] = false;
        trace[i] = -1;
    }
    //declare a queue object and push start, set visited to true for start
    Queue<int> q;
    q.push(start);
    visit[start] = true;
    
    while(!q.empty()){
        int top = q.pop();
        if(top == destination)
            break;

        int numberOfAdjacencyNodes = G.e[top].size();
        LinkedListNode<int> *p = G.e[top].getRoot();
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) 
        { // iterate over each node
            int v = p->value; // v is the adjvancy node of u
             // YOUR CODE HERE
             if(!visit[v]){
                visit[v] = true;
                trace[v] = top;
                q.push(v);
             }
        }
    }

    u = destination;

    while(u != -1){
        path.push_back(u);
        u = trace[u];
    }
    
    // Finally return the number of shorest paths
    return u; // Modify this return value to the correct one 
}
