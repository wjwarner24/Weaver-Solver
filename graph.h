/*
 * graph.h
 *
 * Declaration of the graph class.
 * 
 * Author: William Warner
 */

#ifndef _GRAPH_BFS_H
#define _GRAPH_BFS_H

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;


class word {
    public:
    string s;
    
    vector<int> edges;
    string value() {
        return s;
    }

};

class graph {
public:
    graph();
    void add_edge(int from, int to);
    vector<word> find_shortest_path(string from, string to);
    void weaverEdges();

private:
    vector<word> list;
    
};

#endif
