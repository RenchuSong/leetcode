//
//  main.cpp
//  Largest Rectangle in Histogram
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace::std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int len = (int)height.size();
		int left[len], right[len];
		left[0] = 1; right[len - 1] = 1;
		stack<int> stk;
		stk.push(0);
		for (int i = 1; i < len; ++i) {
			while (!stk.empty() && height[stk.top()] >= height[i]) stk.pop();
			if (!stk.empty()) left[i] = i - stk.top(); else left[i] = i + 1;
			stk.push(i);
		}
		while (!stk.empty()) stk.pop();
		stk.push(len - 1);
		for (int i = len - 2; i >= 0; --i) {
			while (!stk.empty() && height[stk.top()] >= height[i]) stk.pop();
			if (!stk.empty()) right[i] = stk.top() - i; else right[i] = len - i;
			stk.push(i);
		}
		int ans = 0;
		for (int i = 0; i < len; ++i)
			if ((left[i] + right[i] - 1) * height[i] > ans)
				ans = (left[i] + right[i] - 1) * height[i];
		return ans;
    }
};

int main(int argc, const char * argv[])
{
	vector<int> h {2, 1};
	cout << (new Solution())->largestRectangleArea(h) << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

