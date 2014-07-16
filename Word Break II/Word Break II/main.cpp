//
//  main.cpp
//  Word Break II
//
//  Created by Renchu Song on 15/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

class Solution {
public:
	string tp;
	bool flag = false;
	int ans = 0;
	
	void dfs(vector<string> &result, string tmp, int pos, int n, map<int, vector<int>> &a) {
		if (pos == n) {
			result.push_back(tmp);
			if (result.size() == ans) flag = true;
			return;
		}
		if (pos > n) return;
		for (int w: a[pos]) {
			if (flag) return;
			dfs(result, tmp + (tmp.length() > 0 ? " " : "") + tp.substr(pos, w), pos + w, n, a);
		}
	}
	
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
		tp = s;
		
        int n = (int)s.length();
		map<int, vector<int>> a;
		for (string str: dict) {
			int w = (int)str.length();
			int pch = (int)s.find(str);
			while (pch != string::npos) {
				a[pch].push_back(w);
				pch = (int)s.find(str, pch + 1);
			}
		}
		int dp[n + 1];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j: a[i]) if (i + j <= n) dp[i + j] += dp[i];
		}
		ans = dp[n];
		vector<string> result;
		string tmp = "";
		if (ans > 0) dfs(result, tmp, 0, n, a);
		return result;
    }
};

int main(int argc, const char * argv[])
{
//	unordered_set<string> d = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
//	vector<string> r = (new Solution())->wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", d);
//	
	unordered_set<string> d = {"cat", "cats", "and", "sand", "dog"};
	vector<string> r = (new Solution())->wordBreak("catsanddog", d);
	
	for (string str: r) cout << str << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

