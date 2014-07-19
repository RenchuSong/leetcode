//
//  main.cpp
//  LRU Cache
//
//  Created by Renchu Song on 16/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

class LRUCache{
	int capacity = 0;
	
	unordered_map<int, int> cache;
	list<int> keyList;
	unordered_map<int, list<int>::iterator> itrPos;
	
	void moveToEnd(int key) {
		keyList.erase(itrPos[key]);
		addKey(key);
	}
	
	void addKey(int key) {
		keyList.push_back(key);
		auto pos = keyList.end();
		--pos;
		itrPos[key] = pos;
	}
	
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.count(key) > 0) {
			moveToEnd(key);
			return cache[key];
		}
		return -1;
    }
    
    void set(int key, int value) {
        if (cache.count(key) > 0) {
			moveToEnd(key);
			cache[key] = value;
		} else if (cache.size() < capacity) {
			cache[key] = value;
			addKey(key);
		} else {
			cache.erase(keyList.front());
			keyList.pop_front();
			cache[key] = value;
			addKey(key);
		}
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

