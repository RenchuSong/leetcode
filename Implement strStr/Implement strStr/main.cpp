//
//  main.cpp
//  Implement strStr
//
//  Created by Renchu Song on 13/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int n = (int)strlen(haystack), m = (int)strlen(needle);
		if (m == 0) return haystack;
		int pre[m + 1];
		pre[0] = -1;
		int l = -1;
		for (int i = 1; i < m; ++i) {
			while (l > -1 && needle[l + 1] != needle[i]) l = pre[l];
			if (needle[i] == needle[l + 1]) ++l;
			pre[i] = l;
		}
		l = -1;
		for (int i = 0; i < n; ++i) {
			while (l > -1 && needle[l + 1] != haystack[i]) l = pre[l];
			if (needle[l + 1] == haystack[i]) ++l;
			if (l == m - 1) return &haystack[i - m + 1];
		}
		
		return NULL;
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->strStr("dfdsfds", "sfds") << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

