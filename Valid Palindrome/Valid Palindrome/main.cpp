//
//  main.cpp
//  Valid Palindrome
//
//  Created by Renchu Song on 10/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = (int)s.length(), now = 0;
		for (int i = 0; i < len; ++i)
			if (s[i] >= 'A' && s[i] <= 'Z') s[now++] = s[i] + 'a' - 'A';
			else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) s[now++] = s[i];
		int div = now / 2;
		for (int i = 0; i < div; ++i) if (s[i] != s[now - i - 1]) return false;
		return true;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

