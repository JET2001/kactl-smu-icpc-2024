/**
 * Author: BogoSort
 * Description:Generate a connected graph of $n$ vertices and $m$ edges.
 */
#pragma once

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count()); // seed

vector<pair<int, int>> generateConnectedGraph(int n, int m) {
    vector<pair<int, int>> edges = generateDeepSpanningTree(n);
    set<pair<int, int>> used;
    for (auto &e : edges) {
        int u = min(e.first, e.second);
        int v = max(e.first, e.second);
        used.insert({u, v});
    }
    
    int extra = m - (n - 1);
    while (extra > 0) {
        int u = uniform_int_distribution<int>(0, n - 1)(gen);
        int v = uniform_int_distribution<int>(0, n - 1)(gen);
        if(u == v) continue; // Avoid self-loop
        
        int a = min(u, v), b = max(u, v);
        if (used.count({a, b}) == 0) { // Avoid duplicate edge
            used.insert({a, b});
            edges.push_back({u, v});
            extra--;
        }
    }
    return edges;
}
