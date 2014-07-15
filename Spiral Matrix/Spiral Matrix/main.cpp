//
//  main.cpp
//  Spiral Matrix
//
//  Created by Renchu Song on 14/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
		int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int n = (int)matrix.size(); if (n == 0) return result;
		int m = (int)matrix[0].size(); if (m == 0) return result;

		int sq = n * m, x = 0, y = 0, d = 0;
		bool visited[n][m];
		memset(visited, false, sizeof(visited));
		
		for (int i = 1; i <= sq; ++i) {
			result.push_back(matrix[x][y]);
			visited[x][y] = true;
			int nx = x + direction[d][0], ny = y + direction[d][1];
			
			if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || visited[nx][ny]) {
				d = (d + 1) % 4;
			}
			x += direction[d][0];
			y += direction[d][1];
		}

		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<vector<int>> m {
		{1, 2, 3},

	};
	
	vector<int> result = (new Solution())->spiralOrder(m);
	for (int i : result) cout << i << " ";cout << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}