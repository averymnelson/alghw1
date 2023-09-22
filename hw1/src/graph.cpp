#include <graph.hpp>

Graph::Graph(int n) {
    this->n = n;
    this->e = std::vector<LinkedList<int> >(n, LinkedList<int>());
}

Graph::~Graph() {
    this->e.clear();
}

void Graph::insertEdge(int u, int v, bool directed) {
    this->e[u].insert(v);
    if (!directed)
        this->e[v].insert(u);
}

std::vector<int> Graph::search(int start, int destination) {
    Stack<int> stack;
    std::vector<int> mask(this->n, 0);
    std::vector<int> trace(this->n, -1);
    stack.push(start);
    mask[start] = 1;
    while (!stack.empty()) {
        int u = stack.pop();
        if (u == destination)
            break;
        int numberOfAdjacencyNodes = this->e[u].size();
        LinkedListNode<int> *p = this->e[u].root;
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1) {
            int v = p->value;
            if (mask[v] == 0) {
                stack.push(v);
                trace[v] = u;
                mask[v] = 1;
            }
            p = p->next;
        }
    }

    std::vector<int> path;
    int u = destination;
    while (u != -1) {
        path.push_back(u);
        u = trace[u];
    }

    std::reverse(path.begin(), path.end());

    return path;
}
