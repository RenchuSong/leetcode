//
//  main.cpp
//  Edit Distance
//
//  Created by Renchu Song on 8/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
		int n = (int)word1.length(), m = (int) word2.length();
        int dp[n + 1][m + 1];
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i) dp[i][0] = i;
		for (int i = 1; i <= m; ++i) dp[0][i] = i;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1]; else {
					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				}
			}
		}
		return dp[n][m];
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

