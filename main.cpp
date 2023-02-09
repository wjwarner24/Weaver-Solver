/*
 * main.cpp
 *
 * Includes the main() function for the Weaver-solver project.
 *
*/

#include <iostream>

#include "graph.h"

using namespace std;

int main() {
    string s1;
    string s2;
    graph g = graph();
    
    g.weaverEdges();

    while(true) {

    cout << endl;
    cout << "-Enter a four letter word" << endl;
    cin >> s1;
    cout << endl;

    if (s1 == "q") {
            break;
        }
    cout << "-Enter another four letter word" << endl;
    cin >> s2;
    cout << endl;

        if (s2 == "q") {
            break;
        }
    cout << "finding shortest path between '" << s1 << "' and '" << s2 << "'" << endl;

    vector<word> path = g.find_shortest_path(s1, s2);
    cout << endl;
    for (int a = 0; a < path.size(); a++) {
        cout << path.at(a).value() << endl;
    }

    }

    return 0;
}
