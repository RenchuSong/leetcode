//
//  main.cpp
//  Valid Parentheses
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
		for (int i = 0; i < s.length(); ++i) {
			switch (s[i]) {
				case '(': {stk.push(s[i]); break;}
				case '[': {stk.push(s[i]); break;}
				case '{': {stk.push(s[i]); break;}
				case ')': {if (stk.empty() || stk.top() != '(') return false; stk.pop(); break;}
				case ']': {if (stk.empty() || stk.top() != '[') return false; stk.pop(); break;}
				case '}': {if (stk.empty() || stk.top() != '{') return false; stk.pop(); break;}
			}
		}
		return stk.empty();
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

