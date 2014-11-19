/*
1. Random Graph Generation. Write subroutines that generate two kinds of “ran-
dom” graphs of 5000 vertices.
• In the first graph G 1 , every vertex has degree exactly 6;
• In the second graph G 2 , each vertex has edges going to about 20% of the other
vertices;
• Randomly assign positive weights to edges in the graphs.*/
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

#define MAXVERTICES 5000

class vertex
{
    friend class Graph;
    private:
        int val;
        int degree;
    public:
        vertex(){}
        vertex(int v, int d) 
        {
            val = v;
            degree = d;
        }
        int getVal()
        {
            return val;
        }
        void setAttr(int v, int d)
        {
            val = v;
            degree = d;
        }
        int getDegree()
        {
            return degree;
        }
};


class Graph
{
    private:
        vector<vertex> vertices;
        //bool adj[MAXVERTICES][MAXVERTICES]={{0}};
    public:
        Graph()
        {
            for(int i=0;i<MAXVERTICES;i++)
            {
                vertices.push_back(vertex(i,0));
                cout<<vertices[i].val;
            }
        }
        void generateWithDegree(int degree);
        void bfstraversal();
};
