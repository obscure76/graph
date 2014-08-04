#include<graph.h>

Vertex::Vertex(int v)
{
    val = v;
}
Vertex::addAdjVertex(int v)
{

}

bool operator==(Vertex const &v1, Vertex const &v2)
{
    return(v1.val==v2.val);
}
bool operator<(Vertex const &v1, Vertex const &v2)
{
    return(v1.val<v2.val);
}

bool operator>(Vertex const &v1, Vertex const &v2)
{
    return(v1.val>v2.val);
}
Edge::Edge(int a, int s1, int s2)
{
    weight = a;
    src = s1;
    dst = s2;
}

Edge::getWeight(){return weight;}
Edge::getSource(){return src;}
Edge::getDest(){return dst;}

bool operator==( Edge const &e1, Edge const & e2)
{
    if(e1.weight==e2.weight && e1.src==e2.src && e1.dst == e2.dst)
        return true;
    return false;
}


Graph::Graph()
{
    memset(adj, 0, sizeof(int)*MAXSIZE*MAXSIZE);
}

bool Graph::addVertex(int v)
{
    vertices.insert(Vertex(v));    
}
bool Graph::addEdge(Edge e)
{
    edges.insert(e);
    set<Vertex>::iterator src = vertices.find(e.getSource());
    src->addAdjVertex(vertices.find(e.getDest));
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
    g.addVertex(4);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(1);
    g.addVertex(5);
    g.addEdge(Edge(1,1,2);
    g.addEdge(Edge(1,1,2);
    g.addEdge(Edge(1,2,3);
    g.addEdge(Edge(1,2,4);
    g.addEdge(Edge(1,4,5);
    g.print();
    return 0;
}
