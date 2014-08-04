#include<iostream>
#include<cstring>
#include<algorithm>
#include<list>
#include<set>
#define MAXSIZE 100
using namespace std;

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
};

class Graph
{
    private:
        set<int> vertices;
        list<Edge> edges;
        int adj[MAXSIZE][MAXSIZE];
    public:
        Graph();
        bool addVertex(int);
        bool addEdge(Edge);
        bool deleteVertex(int);
        void print();
};


