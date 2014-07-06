//
//  main.cpp
//  Spiral Matrix II
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> result;
		int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		for (int i = 0; i < n; ++i) {
			vector<int> row;
			for (int j = 0; j < n; ++j) row.push_back(0);
			result.push_back(row);
		}
		if (n == 1) result[0][0] = 1; else {
			int sq = n * n, x = 0, y = 0, d = 0;
			for (int i = 1; i <= sq; ++i) {
				result[x][y] = i;
				int nx = x + direction[d][0], ny = y + direction[d][1];
				
				if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || result[nx][ny] > 0) {
					d = (d + 1) % 4;
				}
				x += direction[d][0];
				y += direction[d][1];
			}
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<vector<int>> result = (new Solution())->generateMatrix(4);
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j)
			cout << result[i][j] << " ";
		cout << endl;
	}
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

