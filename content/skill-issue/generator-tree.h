/**
 * Author: BogoSort
 * Description: Generate a connected graph of $n$ vertices and $m$ edges.
 */
#pragma once
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count()); // seed

vector<pair<int, int>> generateDeepSpanningTree(int n) {
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
        double r = uniform_real_distribution<double>(0, 1)(gen);
        int offset = int(r * r * i);
        if(offset >= i) offset = i - 1;
        int j = i - 1 - offset;
        edges.push_back({i, j});
    }
    return edges;
}