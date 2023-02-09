/*
 * graph.cpp
 *
 * Method definitions for the graph class.
 *
 * Author: William Warner
 */

#include "graph.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool threeChars(string one, string two) {
    int count = 0;
    for (int a = 0; a < 4; a++) {
        if (one[a] == two[a]) {
            count++;
        }
    }
    if (count == 3) {
        return true;
    }
    return false;
}

void graph::add_edge(int from, int to) {
    list.at(from).edges.push_back(to);
}

void graph::weaverEdges() {
    int size = list.size();
    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; b++) {
            if (threeChars(list.at(a).value(), list.at(b).value())) {
                add_edge(a, b);
            }
        }
    }
}

graph::graph() {
    ifstream file("dictionary.txt");

    vector<string> data;

    while(!file.eof()) {
        string s;
        file >> s;
        string str;
        for (int a = 0; a < s.size(); a++) {
            str.push_back(tolower(s[a]));
        }
        data.push_back(str);
    }

    int size = data.size();
    list = vector<word>(size);
    for (int a = 0; a < size; a++) {
        list.at(a).s = data.at(a);
    }
}

vector<word> graph::find_shortest_path(string from, string to) {
    int fromIndex;
    for (int a = 0; a < list.size(); a++) {
        if (list.at(a).value() == from) {
            fromIndex = a;
            break;
        }
    }
    int toIndex;
    for (int a = 0; a < list.size(); a++) {
        if (list.at(a).value() == to) {
            toIndex = a;
            break;
        }
    }
    vector<bool> visited = vector<bool>(list.size(), false);
    queue<int> q;
    graph p = graph();
    visited.at(fromIndex) = true;
    q.push(fromIndex);
    while (!q.empty() && !visited.at(toIndex)) {
        int u = q.front();
        q.pop();
        for (int a = 0; a < list.at(u).edges.size(); a++) {
            int w = list.at(u).edges.at(a);
            if (!visited.at(w)) {
                q.push(w);
                visited.at(w) = true;
                p.add_edge(w, u);
            }
        }
    }
    vector<word> vec;
    if (visited.at(toIndex)) {
        vec.push_back(list.at(toIndex));
        while(toIndex != fromIndex) {
            toIndex = p.list.at(toIndex).edges.at(0);
            vec.push_back(list.at(toIndex));
        }
    }
    reverse(vec.begin(), vec.end());
    return vec;
}