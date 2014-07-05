//
//  main.cpp
//  N-Queens II
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
	// For 13 queens. More solution at: http://www.songrenchu.com/Old/OI/blog.php?a=3
	int dfs(int n, int d, int col, int left, int right) {
		if (d > n) return 1;
		int result = 0;
		for (int i = 1; i <= n; ++i) {
			if ((col & (1 << i)) &&
				(left & (1 << (d + i))) &&
				(right & (1 << (d - i + n)))) {
				result += dfs(n, d + 1, col - (1 << i), left - (1 << (d + i)), right - (1 << (d - i + n)));
			}
		}
		return result;
	}
    int totalNQueens(int n) {
        return dfs(n, 1, -1, -1, -1);
    }
};

int main(int argc, const char * argv[])
{
	for (int i = 1; i < 14; ++i)
		cout << (new Solution())->totalNQueens(i) << endl;
    return 0;
}

