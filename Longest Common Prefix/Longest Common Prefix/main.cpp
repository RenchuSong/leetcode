//
//  main.cpp
//  Longest Common Prefix
//
//  Created by Renchu Song on 7/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonStr(vector<string> &strs) {
		string s("");
		if (strs.size() > 0) {
			int len = 1 << 30;
			for (int i = 0; i < strs.size(); ++i) {
				if (strs[i].length() < len) len = (int)strs[i].length();
			}
			for (int i = 0; i < len; ++i) {
				bool flag = true;
				for (int j = 1; j < strs.size(); ++j)
					if (strs[j][i] != strs[0][i]) {
						flag = false; break;
					}
				if (flag) s += strs[0][i]; else break;
			}
		}
		return s;
	}
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

