#include<graph.h>

Vertex::Vertex(int v)
{
}
bool Vertex::addAdjVertex(int v) 
{
}

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
}

void Graph::pathSum(int sum)
{
	char *str;
	str = malloc(100);
	memset(str, 0, 100);
	visited.clear();
	map<int, list<int> >::iterator it;
	it = vertices.begin();
	visited.insert(it->first);
	str[0] = '0' + it->first;
	findpath(sum, it->first, str, 1, it->second);
}

void Graph::findpath(int sum, int curr, char *str, int in, list<int> adj)
{
	if(sum==curr)
	{
		str[i] = '\0';
		cout<<str;
	} else {
		list<int>::iterator lit;
		for(lit = adj.begin();lit!=adj.end();lit++)
		{
			if(curr+*lit > sum)
				continue;
			str[in] = '0'+*lit;
			findpath(sum, curr+*lit, str, in+1, vertices.find(*lit)->second);
		}
	}
}

int main()
{
    Graph g;
    g.addVertex(4);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(1);
    g.addVertex(5);
    g.addEdge(1,1,2);
    g.addEdge(1,1,3);
    g.addEdge(1,2,3);
    g.addEdge(1,2,4);
    g.addEdge(1,4,5);
    g.print();
	g.bfs();
	g.dfstraversal();
    return 0;
}
