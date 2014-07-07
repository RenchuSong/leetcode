//
//  main.cpp
//  Longest Consecutive Sequence
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> m;
		for (int i = 0; i < num.size(); ++i)
			m[num[i]] = 1;
		int result = 1;
		for (int i = 0; i < num.size(); ++i) {
			if (m[num[i]]) {
				int left = num[i], right = num[i];
				while (m[left]) {m[left] = 0; --left;}
				++right;
				while (m[right]) {m[right] = 0; ++right;}
				if (right - left - 1 > result) result = right - left - 1;
			}
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

