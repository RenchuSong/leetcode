//
//  main.cpp
//  Sudoku Solver
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
	int inBox(int x, int y) {
		return (x / 3) * 3 + y / 3;
	}
	
	int ones(int num) {
		int ans = 0;
		for (int i = 1; i < 10; ++i) ans += (num & (1 << i)) > 0;
		return ans;
	}
	
	bool dfs(vector<vector<char> > &board, int* rows, int* cols, int* boxs, int remain) {
		if (remain == 0) return true;
		int small = 1 << 30;
		int x = 0, y = 0, num = 0;
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j) if (board[i][j] == '.') {
				int tmp = rows[i] & cols[j] & boxs[inBox(i, j)];
				int o = ones(tmp);
				if (o < small) {
					num = tmp;
					small = o;
					x = i; y = j;
				}
			}
		for (int i = 1; i < 10; ++i) if ((num & (1 << i)) > 0) {
			board[x][y] = i + '0';
			rows[x] -= 1 << i;
			cols[y] -= 1 << i;
			boxs[inBox(x, y)] -= 1 << i;
			if (dfs(board, rows, cols, boxs, remain - 1)) return true;
			rows[x] += 1 << i;
			cols[y] += 1 << i;
			boxs[inBox(x, y)] += 1 << i;
		}
		board[x][y] = '.';
		return false;
	}
	
    void solveSudoku(vector<vector<char> > &board) {
		int rows[9], cols[9], boxs[9];
		memset(rows, 255, sizeof(rows));
		memset(cols, 255, sizeof(cols));
		memset(boxs, 255, sizeof(boxs));
		
		int remain = 0;
		
        for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') ++remain; else {
					int num = board[i][j] - '0';
					rows[i] -= 1 << num;
					cols[j] -= 1 << num;
					boxs[inBox(i, j)] -= 1 << num;
				}
			}
		dfs(board, rows, cols, boxs, remain);
    }
};

int main(int argc, const char * argv[])
{
	vector<vector<char> > matrix {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	
	(new Solution())->solveSudoku(matrix);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) cout << matrix[i][j] << " ";
		cout << endl;
	}
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

