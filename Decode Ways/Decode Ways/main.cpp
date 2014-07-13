//
//  main.cpp
//  Decode Ways
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
		if (s.length() == 0) return 0;
        int pre1 = 0, pre2 = 0, ans = 1;
		for (int i = 0; i < s.length(); ++i) {
			pre1 = pre2; pre2 = ans; ans = 0;
			if (s[i] > '0') ans += pre2;
			if (i > 0 && s[i - 1] > '0' && (s[i - 1] - '0') * 10 + s[i] - '0' < 27) ans += pre1;
		}
		return ans;
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->numDecodings("0") << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

