//
//  main.cpp
//  Valid Number
//
//  Created by Renchu Song on 9/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool subNumber(const char *s, int st, int en) {
		if (st >= en) return false;
		bool hasNum = false;
		for (int i = st; i < en; ++i) {
			if (s[i] == ' ' || ((s[i] < '0' || s[i] > '9') && s[i] != '.' && !(i == st && (s[st] == '-' || s[st] == '+')))) return false;
			if (s[i] >= '0' && s[i] <='9') hasNum = true;
		}
		if (!hasNum) return false;
		if (st == en - 1 && s[st] == '.') return false;
		if (st == en - 1 && (s[st] == '-' || s[st] == '+')) return false;
		int d = 0;
		for (int i = st; i < en; ++i) if (s[i] == '.') ++d;
		return d < 2;
	}
	
	bool subIntNumber(const char *s, int st, int en) {
		if (st >= en) return false;
		bool hasNum = false;
		for (int i = st; i < en; ++i) {
			if (s[i] == ' ' || ((s[i] < '0' || s[i] > '9') && !(i == st && (s[st] == '-' || s[st] == '+')))) return false;
			if (s[i] >= '0' && s[i] <='9') hasNum = true;
		}
		if (!hasNum) return false;
		if (st == en - 1 && (s[st] == '-' || s[st] == '+')) return false;
		return true;
	}
	
	
    bool isNumber(const char *s) {
		int len = (int)strlen(s);
		int st = 0, en = 0;
        for (int i = 0; i < len; ++i)
			if (s[i] != ' ') {
				st = i; break;
			}
		for (int i = len; i > 0; --i)
			if (s[i - 1] != ' ') {
				en = i; break;
			}
		if (st >= en) return false;
		
		int ce = 0, pe = -1;
		for (int i = st; i < en; ++i) {
			if (s[i] == 'e' || s[i] == 'E') {
				pe = i; ++ce;
			}
		}
		
		if (ce > 1) return false;
		if (ce > 0) {
			return subNumber(s, st, pe) && subIntNumber(s, pe + 1, en);
		}
		
		return subNumber(s, st, en);
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->isNumber("te1") << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

