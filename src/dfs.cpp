#include <search.hpp>
#include <vector>

/*
To iterate over the adjancy nodes of u, you can use the following template code
int numberOfAdjacencyNodes = G.e[u].size(); // Get number of adjancy nodes of u
LinkedListNode<int> *p = G.e[u].getRoot(); // Get the head point of the linked list
for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) { // iterate over each node
    int v = p->value; // v is the adjvancy node of u
    // YOUR CODE HERE
}
*/

int dfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path)
{
//  int dfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path) {
//  int N = G.n; // Number of nodes in the graph
//  for u = 0 to N – 1 do
//  visited[u] = false
//  trace[u] = -1
//  end for
//  Push start to stack
//  visited[start]= true
//  while stack is not empty do
//  u = pop the top value of the stack
//  if u is destination then
//  stop while loop
//  end if
//  for v in the list of neighbor vertices of u do
//  if visited[v] is false then
//  visited[v] = true
//  trace[v] = u
//  Push v into stack
//  end if
//  end for
//  end while
//  u = destination
//  while u != -1 do
//  Insert u into the front of path
//  u = trace[u]
//  end while
//  // How to limit the number of building in Recursive DFS and DFS?
// }

    int N = G.n; // Number of nodes in the graph
    int p = 0;
    std::string pw = "";
    std::vector<bool> visit(N, false);
    Stack<int> s;
    s.push(start);
    while (!s.empty())
    {
        int st = s.pop();
        if (!visit[st])
        {
            visit[st] = true;
            int nAdjnodes = G.e[st].size();
            LinkedListNode<int> *p = G.e[st].getRoot();
            for (int i = 0; i < nAdjnodes; i++, p = p->next)
            {
                int v = p->value;
                if (!visit[v])
                    visit[v]=true;
                    s.push(v);

            }
        }
    }

    //     DFS(G,v) ( v is the vertex where the search starts )
    // Stack S := {}; ( start with an empty stack )
    // for each vertex u, set visited[u] := false;
    // push S, v;
    // while (S is not empty) do
    // u := pop S;
    // if (not visited[u]) then
    //  visited[u] := true;
    //  for each unvisited neighbor w of u
    // push S, w;
    // end if
    // end while
    // END DFS()

    return 0; // You do not need to count the number of paths in this question, therefore, just simply return 0
}
