//
//  main.cpp
//  Unique Paths II
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n = (int)obstacleGrid.size();
		if (n == 0) return 0;
		int m = (int)obstacleGrid[0].size();
		obstacleGrid[0][0] = 1 - obstacleGrid[0][0];
		for (int i = 1; i < n; ++i) obstacleGrid[i][0] = obstacleGrid[i][0] == 1 ? 0 : obstacleGrid[i - 1][0];
		for (int i = 1; i < m; ++i) obstacleGrid[0][i] = obstacleGrid[0][i] == 1 ? 0 : obstacleGrid[0][i - 1];
		for (int i = 1; i < n; ++i)
			for (int j = 1; j < m; ++j)
				obstacleGrid[i][j] = obstacleGrid[i][j] == 1 ? 0 : obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
		return obstacleGrid[n - 1][m - 1];
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

