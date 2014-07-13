//
//  main.cpp
//  Simplify Path
//
//  Created by Renchu Song on 13/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<char*> stk;
		char* str = (char*)path.c_str();
		char * pch = strtok (str,"/");
		while (pch != NULL) {
			if (strcmp(pch, ".") == 0) { }
			else if (strcmp(pch, "..") == 0) {
				if (!stk.empty()) stk.pop();
			} else if (strcmp(pch, "") == 0) { }
			else stk.push(pch);
			
			pch = strtok (NULL, "/");
		}
		string ans = "";
		while (!stk.empty()) {
			string tmp = "/";
			tmp.append(stk.top());
			ans = tmp + ans;
			stk.pop();
		}
		if (ans.compare("") == 0) ans = "/";
		return ans;
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->simplifyPath("/home//foo/") << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

