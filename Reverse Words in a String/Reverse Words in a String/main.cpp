//
//  main.cpp
//  Reverse Words in a String
//
//  Created by Renchu Song on 9/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    void reverseSubStr(string &s, int l, int r) {
		if (l >= r) return;
		int m = (r - l + 1) / 2;
		for (int i = 0; i < m; ++i) {
			char c = s[l + i];
			s[l + i] = s[r - i];
			s[r - i] = c;
		}
	}
    void reverseWords(string &s) {
    	int len = (int)s.length();
    	int i;
        for (i = 0; i < len; ++i) {
        	if (s[i] != ' ') break;
        }
        s.erase(0, i);
        len = (int)s.length();
        for (i = len - 1; i >= 0; --i) {
        	if (s[i] != ' ') break;
        }
        ++i;
        if (len - i > 0)
        	s.erase(i, len - i);
        len = (int)s.length();
        for (int i = 1; i < len;) {
        	if (s[i] == ' ' && s[i - 1] == ' ') {
        		s.erase(i, 1);
        		--len;
        	} else ++i;
        }
        reverseSubStr(s, 0, len - 1);
        int l = 0;
        for (int i = 1; i < len; ++i)
        	if (s[i] == ' ') {
        		reverseSubStr(s, l, i - 1);
        		l = i + 1;
        	}
        reverseSubStr(s, l, len - 1);
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

