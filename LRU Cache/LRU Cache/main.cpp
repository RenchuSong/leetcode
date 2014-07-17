//
//  main.cpp
//  LRU Cache
//
//  Created by Renchu Song on 16/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class LRUCache{
	int t = 0;
	int cap = 0;
	
	map<int, int> cache;
	vector<pair<int, int> > index;	// the time stamp, the key in the map
	
	void up(int x) {
		while (x > 0) {
			int f = x / 2;
			if (index[x].first < index[f].first) {
				pair<int, int> tmp = index[x];
				index[x] = index[f];
				index[f] = tmp;
				x = f;
			}
		}
	}
	
	void down(int x) {
		int nowCap = (int)index.size();
		while (true) {
			int t = x;
			if (x * 2 + 1 < nowCap && index[t].first > index[x * 2 + 1].first) t = x * 2 + 1;
			if (x * 2 + 2 < nowCap && index[t].first > index[x * 2 + 1].first) t = x * 2 + 2;
			if (x == t) return;
			pair<int, int> tmp = index[x];
			index[x] = index[t];
			index[t] = tmp;
			x = t;
		}
	}
	
public:
    LRUCache(int capacity) {
        cap = 0;
    }
    
    int get(int key) {
        if (cache[key] > 0) {
			return cache[key]; else return -1;
		}
    }
    
    void set(int key, int value) {
        if (cap < 1) return;
		if (cache[key])
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

