//
//  main.cpp
//  Gas Station
//
//  Created by Renchu Song on 8/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int n = (int)gas.size();
		if (n < 1) return n;
		if (n == 1) return gas[0] >= cost[0] ? 0 : -1;
        int mid = 0, index = 0, tmp = 0;
		for (int i = 1; i <= n; ++i) {
			tmp = tmp + gas[(i - 1) % n] - cost[(i - 1) % n];
			if (tmp < mid) {
				mid = tmp;
				index = i;
			}
		}
		if (index == 0) return 0;
		for (int i = n + 1; i < 2 * n; ++i) {
			tmp = tmp + gas[(i - 1) % n] - cost[(i - 1) % n];
			if (tmp < mid) {
				mid = tmp;
				index = i;
			}
			if (index == i - n) return i - n;
		}
		return -1;
    }
};

int main(int argc, const char * argv[])
{
	vector<int> gas {1, 2};
	vector<int> cost {2, 1};
	cout << (new Solution())->canCompleteCircuit(gas, cost) << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

