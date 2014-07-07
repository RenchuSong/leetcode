//
//  main.cpp
//  Palindrome Number
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
		int b = 0, ten = 1, one = 1;
		int y = x;
		while (y > 0) {
			y /= 10;
			if (b > 0) ten *= 10;
			b++;
		}
		b /= 2;
		for (int i = 0; i <= b; ++i) {
			int b1 = (x / ten) % 10, b2 = (x / one) % 10;
			if (b1 != b2) return false;
			ten /= 10; one *= 10;
		}
		return true;
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->isPalindrome(10000021) << endl;
    return 0;
}

