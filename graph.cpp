#include<graph.h>

Edge::Edge(int a, int s1, int s2)
{
    weight = a;
    src = s1;
    dst = s2;
}

bool operator==( Edge const &e1, Edge const & e2)
{
    if(e1.weight==e2.weight && e1.src ==e2.src && e1.dst == e2.dst)
        return true;
    return false;
}


Graph::Graph()
{
    memset(adj, 0, sizeof(int)*MAXSIZE*MAXSIZE);
}

bool Graph::addVertex(int v)
{
    vertices.insert(v);    
}
bool Graph::addEdge(Edge e)
{
    edges.insert(e);
}
bool Graph::deleteVertex(int v)
{
    vertices.erase(v);
}
void Graph::print()
{
}
int main()
{
    Graph g;
    return 0;
}
