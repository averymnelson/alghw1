#include <search.hpp>


/* Template Code 
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
    
    // Finally return the number of shorest paths
    return 0; // Modify this return value to the correct one 
}
