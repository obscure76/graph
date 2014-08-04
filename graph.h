#include<iostream>
#include<cstring>
#include<algorithm>
#include<list>
#include<set>
#define MAXSIZE 100
using namespace std;


class Vertex
{
    private:
        int val;
        list<Vertex> adjList;
    public:
        Vertex(){};
        Vertex(int);
        addAdjVertex(int);
        friend bool operator==(Vertex const &, Vertex const &);
        friend bool operator<(Edge const &,  Edge const &);
        friend bool operator>(Edge const &,  Edge const &);
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
        set<Vertex> vertices;
        list<Edge> edges;
        int adj[MAXSIZE][MAXSIZE];
    public:
        Graph();
        bool addVertex(int);
        bool addEdge(Edge);
        bool deleteVertex(int);
        void print();
};


