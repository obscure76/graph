#include<graph.h>

Vertex::Vertex(int v)
{
}
bool Vertex::addAdjVertex(int v) 
{
}

list<int> order;
bool operator==(Vertex const &v1, Vertex const &v2)
{
    return true;
}
bool operator<(Vertex const &v1, Vertex const &v2)
{
    return true;
}

bool operator>(Vertex const &v1, Vertex const &v2)
{
    return true;
}

Edge::Edge(int a, int s1, int s2)
{
    weight = a;
    src = s1;
    dst = s2;
}

int Edge::getWeight(){return weight;}
int Edge::getSource(){return src;}
int Edge::getDest(){return dst;}

bool operator==( Edge const &e1, Edge const & e2)
{
    if(e1.weight==e2.weight && e1.src==e2.src && e1.dst == e2.dst)
        return true;
    return false;
}


Graph::Graph(){}

bool Graph::addVertex(int v)
{
    list<int> adjList;
    vertices.insert(pair<int, list<int> >(v, adjList));    
}
bool Graph::addEdge(int wt, int s, int d)
{
    edges.push_back(Edge(wt, s, d));
    map<int, list<int> >::iterator sit = vertices.find(s);
    if(sit!=vertices.end())
        sit->second.push_back(d);
    else
    {
        list<int> adjList;
        adjList.push_back(d);
        vertices.insert(pair<int, list<int> >(s, adjList));
    }
    sit = vertices.find(d);
    if(sit == vertices.end())
    {
        list<int> adjList1;
        vertices.insert(pair<int, list<int> >(d, adjList1));
    }
}
bool Graph::deleteVertex(int v)
{
}
void Graph::print()
{
    map<int, list<int> >::iterator it;
    for(it = vertices.begin();it!=vertices.end();it++)
    {	
        cout<<"Node "<<it->first<<'-';
        for(list<int>::iterator lit = it->second.begin();lit!=it->second.end();lit++)
            cout<<*lit<<',';
        cout<<endl;
    }
}
void Graph::bfs()
{
    queue<int> q;
    visited.clear();
    q.push(vertices.begin()->first);
    visited.insert(vertices.begin()->first);
    cout<<"\n BFS Traversal :";
    while(q.size() > 0)
    {
        int v = q.front();
        q.pop();
        list<int> adjList = vertices.find(v)->second;
        list<int>::iterator it;
        set<int>::iterator sit;
        for(it = adjList.begin();it!=adjList.end();it++)
        {
            sit = visited.find(*it);
            if(sit!=visited.end())
                continue;
            visited.insert(*it);
            q.push(*it);
        }
        cout<<v<<" ";
    }
}

void Graph::dfstraversal()
{
    visited.clear();
    cout<<"\nDFS Traversal :";
    map<int, list<int> >::iterator it;
    for(it = vertices.begin();it!=vertices.end();it++)
    {
        if(visited.find(it->first) != visited.end())
            continue;
        visited.insert(it->first);
        dfs(it->first, it->second);
    }
    cout<<endl;
}

void Graph::dfs(int v, list<int> adj)
{
    list<int>::iterator lit;
    for(lit = adj.begin();lit!=adj.end();lit++)
    {
        if(visited.find(*lit) != visited.end())
            continue;
        visited.insert(*lit);
        dfs(*lit, vertices.find(*lit)->second);
    }
    cout<<v<<' ';
    order.push_front(v);
}

void Graph::pathSum(int sum)
{
    char *str;
    str = (char *)malloc(100);
    memset(str, 0, 100);
    visited.clear();
    map<int, list<int> >::iterator it;
    it = vertices.begin();
    findpath(sum, 0, str, 0, it->first);
}

void Graph::findpath(int sum, int cval, char *str, int in, int curr)
{
    if(curr+cval > sum)
        return;
    if(cval+curr == sum)
    {
        str[in] = '0' + curr;
        str[in+1] = '\0';
        cout<<str<<endl;
        visited.insert(curr);
        if(visited.find(curr)==visited.end())
            findpath(sum, 0, str, 0, curr);
    } else {
        cval += curr;
        //cout<<"Cval now"<<cval<<'\t';
        str[in] = '0'+curr;
        map<int, list<int> >::iterator it;
        it = vertices.find(curr);
        if(it==vertices.end())
            return;
        list<int> adj = it->second;
        for(list<int>::iterator lit = adj.begin();lit!=adj.end();lit++)
            findpath(sum, cval, str, in+1, *lit);
        for(list<int>::iterator lit = adj.begin();lit!=adj.end();lit++)
        {
            if(visited.find(*lit)==visited.end())
            {
                visited.insert(*lit);
                findpath(sum, 0, str, 0, *lit);
            }
        }
    }
}

void Graph::bellman()
{
    order.clear();
    dfstraversal();
    map<int, int> vd;
    map<int, list<int> >::iterator it;
    int vlen = vertices.size();
    for(it = vertices.begin();it!=vertices.end();it++)
        vd.insert(pair<int, int>(it->first, INT_MAX));
    vd.find(vertices.begin()->first)->second = 0;
    list<int>::iterator lit;
    for(lit=order.begin();lit!=order.end();lit++)
    {
        list<Edge>::iterator it;
        for(it = edges.begin();it!=edges.end();it++)
        {
            int src = it->getSource();
            int dst = it->getDest();
            int wt = it->getWeight();
            if(src!=*lit)
                continue;
            if(vd.find(dst)->second > vd.find(src)->second+wt)
                vd.find(dst)->second = vd.find(src)->second+wt;
        }
    }
    map<int, int>::iterator mit;
    for(mit = vd.begin();mit!=vd.end();mit++)
        cout<<mit->first<<" at dist "<<mit->second<<endl;
}

list<int> Graph::topologicalSort()
{
    order.clear();
    dfstraversal();
    for(list<int>::iterator it = order.begin();it!=order.end();it++)
        cout<<*it;
    return order;
}

void Graph::topo()
{
    order.push_back(4);
}

int main()
{
    Graph g;
    g.addEdge(1,1,2);
    g.addEdge(1,1,3);
    g.addEdge(1,2,4);
    g.addEdge(1,2,5);
    g.addEdge(1,3,6);
    g.addEdge(1,3,8);
    g.print();
    g.bfs();
    g.dfstraversal();
    g.pathSum(8);
    cout<<endl;
    g.topologicalSort();
    cout<<endl;
    g.bellman();
    return 0;
}
