//
//  main.cpp
//  Surrounded Regions
//
//  Created by Renchu Song on 9/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	unordered_set<int> visited;
    void solveUnsolved(vector<vector<char>> &board) {
		if (board.size() == 0 || board[0].size() == 0) return;
		//if (board.size() > 8) {cout << "Fuck 1    "; return; }
		int n = (int)board.size(), m = (int)board[0].size();
		for (int i = 0; i < n; ++i) {
			if (board[i][0] == 'O') visited.insert(i * m + 0);
			if (board[i][m - 1] == 'O') visited.insert(i * m + m - 1);
		}
		//if (board.size() > 8) {cout << "Fuck 2    "; return; }
		for (int i = 1; i < m - 1; ++i) {
			if (board[0][i] == 'O') visited.insert(0 * m + i);
			if (board[n - 1][i] == 'O') visited.insert((n - 1) * m + i);
		}
		//if (board.size() > 8) {cout << "Fuck 3    "; return; }
		int preLen = 0, len = (int)visited.size();
		while (preLen < len) {
			unordered_set<int>::iterator it = visited.begin();
			for (int i = 0; i < len; ++i, ++it) {
				int x = (*it) / m, y = (*it) % m;
				if (x > 0 && board[x - 1][y] == 'O' && visited.find((*it) - m) == visited.end()) visited.insert((*it) - m);
				if (x < n - 1 && board[x + 1][y] == 'O' && visited.find((*it) + m) == visited.end()) visited.insert((*it) + m);
				if (y > 0 && board[x][y - 1] == 'O' && visited.find((*it) - 1) == visited.end()) visited.insert((*it) - 1);
				if (y < m - 1 && board[x][y + 1] == 'O' && visited.find((*it) + 1) == visited.end()) visited.insert((*it) + 1);
			}
			preLen = len; len = (int)visited.size();
		}
		//if (board.size() > 8) {cout << "Fuck 4    "; return; }
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				unordered_set<int>::iterator f = visited.find(i * m + j);
				if (board[i][j] == 'O' && f == visited.end()) board[i][j] = 'X';
			}
		//if (board.size() > 8) {cout << "Fuck 5    "; return; }
    }
	
	queue<int> q;
	void solve(vector<vector<char>> &board) {
		if (board.size() == 0 || board[0].size() == 0) return;
		vector<vector<int>> state;	// 0: un-visited		1: wall		2: link to boundary
		int n = (int)board.size(), m = (int)board[0].size();
		for (int i = 0; i < n; ++i) {
			vector<int> init;
			for (int j = 0; j < m; ++j) init.push_back(board[i][j] == 'X' ? 1 : 0);
			state.push_back(init);
		}
		for (int i = 0; i < n; ++i) {
			if (board[i][0] == 'O') {
				state[i][0] = 2;
				q.push(i * m);
			}
			if (board[i][m - 1] == 'O') {
				state[i][m - 1] = 2;
				q.push(i * m + m - 1);
			}
		}
		for (int j = 1; j < m - 1; ++j) {
			if (board[0][j] == 'O') {
				state[0][j] = 2;
				q.push(j);
			}
			if (board[n - 1][j] == 'O') {
				state[n - 1][j] = 2;
				q.push((n - 1) * m + j);
			}
		}
		while (!q.empty()) {
			int head = q.front();
			int x = head / m, y = head % m;
			q.pop();
			if (x > 0 && board[x - 1][y] == 'O' && state[x - 1][y] == 0) {
				state[x - 1][y] = 2;
				q.push((x - 1) * m + y);
			}
			if (x < n - 1 && board[x + 1][y] == 'O' && state[x + 1][y] == 0) {
				state[x + 1][y] = 2;
				q.push((x + 1) * m + y);
			}
			if (y > 0 && board[x][y - 1] == 'O' && state[x][y - 1] == 0) {
				state[x][y - 1] = 2;
				q.push(x * m + y - 1);
			}
			if (y < m - 1 && board[x][y + 1] == 'O' && state[x][y + 1] == 0) {
				state[x][y + 1] = 2;
				q.push(x * m + y + 1);
			}
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (state[i][j] == 0)
					board[i][j] = 'X';
	}
};

int main(int argc, const char * argv[])
{
	vector<vector<char>> board
		{
			{'O','X','O','O','O','O','O','O','O'},
			{'O','O','O','X','O','O','O','O','X'},
			{'O','X','X','X','O','O','O','O','X'},
			{'O','X','O','X','X','O','O','O','O'},
			{'X','X','O','X','O','O','O','O','X'},
			{'X','X','X','O','X','O','X','O','X'},
			{'O','O','O','X','O','O','O','O','O'},
			{'O','O','O','X','O','O','O','O','O'},
			{'O','O','O','O','O','X','X','O','O'}
		};
	(new Solution())->solve(board);
	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 9; ++j)
			cout << board[i][j]; cout << endl;
	}
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

