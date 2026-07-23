#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    struct Node {
        int value;
        int freq;
    };

    int cap;
    int minFreq;

    unordered_map<int, Node> keyMap;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyMap.find(key) == keyMap.end())
            return -1;

        int f = keyMap[key].freq;

        freqList[f].erase(pos[key]);

        if (freqList[f].empty()) {
            freqList.erase(f);
            if (minFreq == f)
                minFreq++;
        }

        keyMap[key].freq++;

        freqList[f + 1].push_front(key);
        pos[key] = freqList[f + 1].begin();

        return keyMap[key].value;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        if (keyMap.find(key) != keyMap.end()) {
            keyMap[key].value = value;
            get(key);          // updates frequency
            return;
        }

        if (keyMap.size() == cap) {
            int evict = freqList[minFreq].back();
            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            keyMap.erase(evict);
            pos.erase(evict);
        }

        keyMap[key] = {value, 1};
        freqList[1].push_front(key);
        pos[key] = freqList[1].begin();
        minFreq = 1;
    }
};