//
//  main.cpp
//  Container With Most Water
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int l = 0, r = (int)height.size() - 1;
		int area = 0;
		while (l < r) {
			int tmp = min(height[l], height[r]) * (r - l);
			area = max(area, tmp);
			if (height[l] < height[r]) l++; else r--;
		}
		return area;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

