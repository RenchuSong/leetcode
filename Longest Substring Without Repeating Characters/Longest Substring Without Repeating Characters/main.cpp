//
//  main.cpp
//  Longest Substring Without Repeating Characters
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int has[256];
		memset(has, 0, sizeof(has));
		int ans = 0, pos = 0;
		for (int i = 0; i < s.length(); ++i) {
			while (has[s[i]] > 0) {
				--has[s[pos]];
				++pos;
			}
			has[s[i]] = 1;
			if (i - pos + 1 > ans) ans = i - pos + 1;
		}
		return ans;
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->lengthOfLongestSubstring("abcabcbb") << endl;
	cout << (new Solution())->lengthOfLongestSubstring("bbbbbb") << endl;
	cout << (new Solution())->lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") << endl;
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

