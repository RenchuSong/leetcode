//
//  main.cpp
//  Restore IP Addresses
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		int len = (int)s.length();
		vector<string> result;
		if (len > 12) return result;
        bool dp[len][len];
		int ten[3] = {0, 10, 100};
		memset(dp, false, sizeof(dp));
		for (int i = 0; i < len; ++i)
			for (int j = i; j < len; ++j) if (j - i < 3){
				long long num = atol(s.substr(i, j - i + 1).c_str());
				if (num < 256 && num >= ten[j - i]) {
					dp[i][j] = true;
				}
			}
		for (int i = 0; i < len - 3; ++i)
			for (int j = i + 1; j < len - 2; ++j)
				for (int k = j + 1; k < len - 1; ++k) {
					if (dp[0][i] && dp[i + 1][j] && dp[j + 1][k] && dp[k + 1][len - 1]) {
						result.push_back(s.substr(0, i + 1) + "." + s.substr(i + 1, j - i) + "." + s.substr(j + 1, k - j) + "." + s.substr(k + 1, len - 1 - k));
					}
				}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<string> result = (new Solution())->restoreIpAddresses("10101010");
	for (int i = 0; i < result.size(); ++i) cout << result[i] << endl;
    return 0;
}

