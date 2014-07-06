//
//  main.cpp
//  Unique Paths
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

class Solution {
public:
	long long gcd(long long a, long long b) {
		while (b) {
			long long c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
	
	long long c(int m, int n) {
		if (n > m - n) n = m - n;
		long long result = 1;
		for (int i = 1; i <= n; ++i) {
			long long mul = m, div = i, g = gcd(mul, div);
			mul /= g; div /= g;
			result = result * mul / div;
			m--;
		}
		return result;
	}
	
    int uniquePaths(int m, int n) {
		if (m < 1 || n < 1) return 0;
        return (int)c(m + n - 2, n - 1);
    }
};

int main(int argc, const char * argv[])
{
	cout
    return 0;
}

