//
//  main.cpp
//  Divide Two Integers
//
//  Created by Renchu Song on 13/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
		long long x = dividend, y = divisor;
		
		int sig = 1;
		if (dividend < 0) {
			sig = -sig; x = -x;
		}
		if (divisor < 0) {
			sig = -sig; y = -y;
		}
        long long tmp[40];
		tmp[0] = y;
		for (int i = 1; i < 32; ++i) {
			tmp[i] = tmp[i - 1] + tmp[i - 1];
		}
		long long ans = 0;
		
		for (int i = 31; i >= 0; --i) {
			if (x >= tmp[i]) {
				ans += (1 << i);
				x -= tmp[i];
			}
		}
		return sig > 0 ? (int)ans : -(int)ans;
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->divide(-2147482648, 1) << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

