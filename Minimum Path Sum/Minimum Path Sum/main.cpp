//
//  main.cpp
//  Minimum Path Sum
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0) return 0;
		int n = (int)grid.size(), m = (int)grid[0].size();
		int a[n][m];
		a[0][0] = grid[0][0];
		for (int i = 1; i < n; ++i) a[i][0] = a[i - 1][0] + grid[i][0];
		for (int i = 1; i < m; ++i) a[0][i] = a[0][i - 1] + grid[0][i];
		for (int i = 1; i < n; ++i)
			for (int j = 1; j < m; ++j) {
				a[i][j] = (a[i - 1][j] < a[i][j - 1] ? a[i - 1][j] : a[i][j - 1]) + grid[i][j];
			}
		return a[n - 1][m - 1];
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

