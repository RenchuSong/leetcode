//
//  main.cpp
//  Longest Palindromic Substring
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = (int)s.length();
		int ans = 1, pos = 0;
		for (int i = 1; i < len; ++i) {
			int j;
			for (j = i + 1; j < len; ++j) {
				if (2 * i - j < 0 || s[2 * i - j] != s[j]) break;
			}
			if ((j - i - 1) * 2 + 1 > ans) {
				ans = (j - i - 1) * 2 + 1;
				pos = j - 1;
			}
			if (s[i] == s[i - 1]) {
				if (ans < 2) {
					ans = 2; pos = i;
				}
				for (j = i + 1; j < len; ++j) {
					if (2 * i - j - 1 < 0 || s[2 * i - j - 1] != s[j]) break;
				}
				if ((j - i) * 2 > ans) {
					ans = (j - i) * 2;
					pos = j - 1;
				}
			}
		}
		return s.substr(pos - ans + 1, ans);
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->longestPalindrome("sbbs") << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

