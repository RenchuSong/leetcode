//
//  main.cpp
//  Valid Sudoku
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool validRow(vector<vector<char> > &board, int x) {
		for (int i = 0; i < 9; ++i) if (board[x][i] != '.')
			for (int j = i + 1; j < 9; ++j) if (board[x][j] != '.')
				if (board[x][i] == board[x][j]) return false;
		return true;
	}
	
	
	bool validCol(vector<vector<char> > &board, int x) {
		for (int i = 0; i < 9; ++i) if (board[i][x] != '.')
			for (int j = i + 1; j < 9; ++j) if (board[j][x] != '.')
				if (board[i][x] == board[j][x]) return false;
		return true;
	}
	
	bool validBox(vector<vector<char> > &board, int x, int y) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j) if (board[x + i][y + j] != '.')
				for (int s = 0; s < 3; ++s)
					for (int t = 0; t < 3; ++t) if ((s != i || t != j) && board[x + s][y + t] != '.')
						if (board[x + i][y + j] == board[x + s][y + t]) return false;
		return true;
	}
	
	bool isValidSudoku(vector<vector<char> > &board) {
		if (board.size() != 9) return false;
		for (int i = 0; i < 9; ++i) if (board[i].size() != 9) return false;
		for (int i = 0; i < 9; ++i) {
			if (!validRow(board, i)) return false;
			if (!validCol(board, i)) return false;
		}
		for (int i = 0; i < 9; i += 3)
			for (int j = 0; j < 9; j += 3)
				if (!validBox(board, i, j)) return false;
		return true;
	}
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

