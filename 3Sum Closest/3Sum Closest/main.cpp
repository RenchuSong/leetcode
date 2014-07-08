//
//  main.cpp
//  3Sum Closest
//
//  Created by Renchu Song on 7/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
		int result = num[0] + num[1] + num[2], dt = abs(target - result);
		for (int i = 0; i < num.size(); ++i) {
			int l = 0, r = (int)num.size() - 1, tmp = 0;
			while (l < r) {
				if (l == i) ++l;
				if (r == i) --r;
				if (l < r && l < num.size() && r > 0) {
					tmp = num[l] + num[r] + num[i];
					if (abs(tmp - target) < dt) {
						dt = abs(tmp - target);
						result = tmp;
					}
					if (tmp == target) break;
					if (tmp < target) ++l;
					else --r;
				}
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

