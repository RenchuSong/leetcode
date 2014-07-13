//
//  main.cpp
//  Longest Valid Parentheses
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
		
        int nowLevel = 0, pos = -1, ans = 0;
		for (int i = 0; i < s.length(); ++i) {
			nowLevel += s[i] == '(' ? 1 : -1;
			if (nowLevel == 0) ans = max(ans, i - pos);
			if (nowLevel < 0) {
				pos = i; nowLevel = 0;
			}
		}
		
		nowLevel = 0, pos = -1;
		for (int i = 0; i < s.length(); ++i) {
			nowLevel += s[s.length() - i - 1] == ')' ? 1 : -1;
			if (nowLevel == 0) ans = max(ans, i - pos);
			if (nowLevel < 0) {
				pos = i; nowLevel = 0;
			}
		}
		
		return ans;
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->longestValidParentheses("(()") << endl;
	cout << (new Solution())->longestValidParentheses(")()())") << endl;
	cout << (new Solution())->longestValidParentheses("(()") << endl;
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

