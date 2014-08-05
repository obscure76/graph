#include<iostream>
#include<cstring>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<climits>
#define MAXSIZE 100
using namespace std;


class Vertex
{
    private:
        pair<int, list<Vertex> > V;
    public:
        Vertex(){};
        Vertex(int);
        bool addAdjVertex(int);
        friend bool operator==(Vertex const &, Vertex const &);
        friend bool operator<(Vertex const &,  Vertex const &);
        friend bool operator>(Vertex const &,  Vertex const &);
};

class Edge
{
    private:
        int weight;
        int src;
        int dst;
    public:
        Edge(){};
        Edge(int, int, int);
        ~Edge(){};
        friend bool operator==(Edge const &,  Edge const &);
        //friend bool operator<(Edge const &,  Edge const &);
        //friend bool operator>(Edge const &,  Edge const &);
        int getWeight();
        int getSource();
        int getDest();
};

class Graph
{
    private:
        map<int, list<int> > vertices;
        list<Edge> edges;
        set<int> visited;
    public:
        Graph();
        bool addVertex(int);
        bool addEdge(int, int, int);
        bool deleteVertex(int);
        void print();
        void bfs();
        void dfstraversal();
        void dfs(int, list<int>);
        void pathSum(int);
        void findpath(int, int, char *, int, int);
        void bellman();
        list<int> topologicalSort();
        void topo();
};


