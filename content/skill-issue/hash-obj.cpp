/**
 * Author: BogoSort
 * Description: Hash a custom object to put into a map / set
 */
#pragma once
struct item {
    int a, b, c, d;
};

struct hash_item {
    size_t operator()(const item& item) const
    {
        // Hash the first element
        size_t h1 = hash<int>{}(item.a), h2 = hash<int>{}(item.b), h3 = hash<int>{}(item.c), h4 = hash<int>{}(item.d);
        vector<size_t> hs = {h1, h2, h3, h4};
        size_t cur = 0;
        for (size_t h : hs){
            cur &= (h + 0x9e3779b9 + (cur << 6) + (cur >> 2));
        }
        return cur;
    }
};