//
//  main.cpp
//  Maximal Rectangle
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int n = (int)matrix.size(); if (n == 0) return 0;
		int m = (int)matrix[0].size(); if (m == 0) return 0;
		int top[n][m], left[n][m], right[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				top[i][j] = i == 0 ? matrix[i][j] - '0' : (matrix[i][j] - '0' ? top[i - 1][j] + 1 : 0);
				left[i][j] = j == 0 ? matrix[i][j] - '0' : (matrix[i][j] - '0' ? left[i][j - 1] + 1 : 0);
			}
			for (int j = m - 1; j >= 0; --j) {
				right[i][j] = j == m - 1 ? matrix[i][j] - '0' : (matrix[i][j] - '0' ? right[i][j + 1] + 1 : 0);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i > 0 && top[i][j] > 1) {
					left[i][j] = min(left[i][j], left[i - 1][j]);
					right[i][j] = min(right[i][j], right[i - 1][j]);
				}
				ans = max(ans, top[i][j] * (right[i][j] + left[i][j] - 1));
			}
		}
		return ans;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

