//
//  main.cpp
//  Trapping Rain Water
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        int result = 0;
		stack<int> h;
		stack<int> ind;
		int level = 0;
		for (int i = 0; i < n; ++i) {
			while (!h.empty() && h.top() <= A[i]) {
				result += (i - 1 - ind.top()) * (h.top() - level);
				level = h.top();
				h.pop(); ind.pop();
			}
			if (!h.empty()) {
				result += (i - 1 - ind.top()) * (A[i] - level);
				level = A[i];
			} else {
				level = 0;
			}
			h.push(A[i]);
			ind.push(i);
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	int a[3] = {4, 2, 3};
	cout << (new Solution())->trap(a, 3) << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

