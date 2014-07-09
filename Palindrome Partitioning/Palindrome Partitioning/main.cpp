//
//  main.cpp
//  Palindrome Partitioning
//
//  Created by Renchu Song on 8/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void dfs(string &s, vector<vector<string>> &result, vector<string> &tmp, int pos, bool** dp) {
		int len = (int)s.length();
		if (pos == len) {
			vector<string> ans = tmp;
			result.push_back(ans);
			return;
		}
		for (int i = pos; i < len; ++i)
			if (dp[pos][i]) {
				tmp.push_back(s.substr(pos, i - pos + 1));
				dfs(s, result, tmp, i + 1, dp);
				tmp.pop_back();
			}
	}
	
    vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
        int len = (int)s.length();
		if (len < 1) {
			vector<string> init;
			init.push_back("");
			result.push_back(init);
			return result;
		}
		// Cal palindrome
		bool** dp = new bool*[len];
		for (int i = 0; i < len; ++i)
			dp[i] = new bool[len];
		for (int i = 0; i < len; ++i)
			for (int j = 0; j < len; ++j) dp[i][j] = (i == j);
		for (int i = 0; i < len - 1; ++i) if (s[i] == s[i + 1]) dp[i][i + 1] = true;
		for (int i = 1; i < len - 1; ++i) {
			for (int j = i + 1; j < len; ++j) {
				int p = 2 * i - j;
				if (p > -1 && dp[p + 1][j - 1] && s[p] == s[j]) dp[p][j] = true;
			}
			for (int j = i + 2; j < len; ++j) {
				int p = 2 * i - j + 1;
				if (p > -1 && dp[p + 1][j - 1] && s[p] == s[j]) dp[p][j] = true;
			}
		}
		vector<string> tmp;
		dfs(s, result, tmp, 0, dp);
		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<vector<string>> result = (new Solution())->partition("11221134444");
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) cout << result[i][j] << " "; cout << endl;
	}
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

