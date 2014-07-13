//
//  main.cpp
//  Word Search
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool** visit;
	int n, m;
	
	bool dfs(vector<vector<char> > &board, string &word, int start, int len, int x, int y) {
		if (start == len - 1) return true;
		visit[x][y] = true;
		bool flag;
		if (x > 0 && !visit[x - 1][y] && word[start + 1] == board[x - 1][y]) {
			flag = dfs(board, word, start + 1, len, x - 1, y);
			if (flag) return true;
		}
		if (x < n - 1 && !visit[x + 1][y] && word[start + 1] == board[x + 1][y]) {
			flag = dfs(board, word, start + 1, len, x + 1, y);
			if (flag) return true;
		}
		if (y > 0 && !visit[x][y - 1] && word[start + 1] == board[x][y - 1]) {
			flag = dfs(board, word, start + 1, len, x, y - 1);
			if (flag) return true;
		}
		if (y < m - 1 && !visit[x][y + 1] && word[start + 1] == board[x][y + 1]) {
			flag = dfs(board, word, start + 1, len, x, y + 1);
			if (flag) return true;
		}
		visit[x][y] = false;
		return false;
	}
	
    bool exist(vector<vector<char> > &board, string word) {
        int len = (int)word.length();
		if (len  == 0) return false;
		
		n = (int)board.size(); if (n == 0) return false;
		m = (int)board[0].size(); if (m == 0) return false;
		if (n * m < len) return false;
		
		
		visit = new bool*[n];
		for (int i = 0; i < n; ++i) {
			visit[i] = new bool[m];
			for (int j = 0; j < m; ++j) visit[i][j] = false;
		}
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) if (board[i][j] == word[0]) {
				if (dfs(board, word, 0, len, i, j)) return true;
			}
		return false;
    }
};

int main(int argc, const char * argv[])
{
	vector<vector<char>> board {
		{'A','B','C','E'},
			{'S','F','C','S'},
				{'A','D','E','E'}
	};
	
	cout << (new Solution())->exist(board, "ABCCED") << endl;
	cout << (new Solution())->exist(board, "SEE") << endl;
	cout << (new Solution())->exist(board, "ABCB") << endl;
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

