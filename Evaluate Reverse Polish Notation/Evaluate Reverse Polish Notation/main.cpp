//
//  main.cpp
//  Evaluate Reverse Polish Notation
//
//  Created by Renchu Song on 9/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
		for (int i = 0; i < tokens.size(); ++i) {
			string s = tokens[i];
			if (s.compare("+") == 0) {
				int a = stk.top();
				stk.pop();
				int b = stk.top();
				stk.pop();
				stk.push(a + b);
			} else if (s.compare("-") == 0) {
				int a = stk.top();
				stk.pop();
				int b = stk.top();
				stk.pop();
				stk.push(b - a);
			} else if (s.compare("*") == 0) {
				int a = stk.top();
				stk.pop();
				int b = stk.top();
				stk.pop();
				stk.push(a * b);
			} else if (s.compare("/") == 0) {
				int a = stk.top();
				stk.pop();
				int b = stk.top();
				stk.pop();
				stk.push(b / a);
			} else {
				stk.push(atoi(s.c_str()));
			}
		}
		return stk.top();
    }
};

int main(int argc, const char * argv[])
{
	vector<string> a {"4", "13", "5", "/", "+"};
	cout << (new Solution())->evalRPN(a) << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

