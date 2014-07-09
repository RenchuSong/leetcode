//
//  main.cpp
//  N-Queens
//
//  Created by Renchu Song on 8/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// For 13 queens. More solution at: http://www.songrenchu.com/Old/OI/blog.php?a=3
	void dfs(int n, int d, int col, int left, int right, vector<vector<string>> &result, vector<int> &tmp) {
		if (d > n) {
			vector<string> item;
			for (int i = 0; i < n; ++i) {
				string s(n, '.');
				s[tmp[i] - 1] = 'Q';
				item.push_back(s);
			}
			result.push_back(item);
		}
		for (int i = 1; i <= n; ++i) {
			if ((col & (1 << i)) &&
				(left & (1 << (d + i))) &&
				(right & (1 << (d - i + n)))) {
				tmp.push_back(i);
				dfs(n, d + 1, col - (1 << i), left - (1 << (d + i)), right - (1 << (d - i + n)), result, tmp);
				tmp.pop_back();
			}
		}
	}
	
	
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > result;
		vector<int> tmp;
        dfs(n, 1, -1, -1, -1, result, tmp);
		return result;
    }
};

int main(int argc, const char * argv[])
{
    return 0;
}
