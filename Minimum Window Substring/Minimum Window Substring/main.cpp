//
//  main.cpp
//  Minimum Window Substring
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
		int ans = 1 << 30, l = 0, r = 0;
        int count[256];
		int has[256];
		memset(count, 0, sizeof(count));
		memset(has, 0, sizeof(has));
		int n = (int) S.length();
		int m = (int) T.length();
		if (m == 0) return "";
		for (int i = 0; i < m; ++i) ++has[T[i]];
		int left = 0, remain = 0;
		for (int i = 0; i < 256; ++i) if (has[i] > 0) ++remain;
		for (int i = 0; i < n; ++i) {
			++count[S[i]];
			if (has[S[i]] > 0 && count[S[i]] == has[S[i]]) --remain;
			while ((has[S[left]] && count[S[left]] > has[S[left]]) || !has[S[left]]) {
				if (left >= i) break;
				--count[S[left]];
				++left;
			}
			if (remain == 0 && i - left + 1 < ans) {
				ans = i - left + 1;
				l = left; r = i;
			}
		}
		if (ans > n) return "";
		return S.substr(l, r - l + 1);
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->minWindow("ADOBECODEBANC", "ABC") << endl;
	cout << (new Solution())->minWindow("aabbabbb", "") << endl;
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

