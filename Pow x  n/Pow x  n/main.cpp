//
//  main.cpp
//  Pow x  n
//
//  Created by Renchu Song on 8/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

class Solution {
public:
    double powHelper(double x, long long n) {
        if (n < 0) return 1 / powHelper(x, -n);
        if (n == 0) {
            if (x == 0) return 0; else return 1;
        }
        if (n == 1) return x;
        double tmp = powHelper(x, n / 2);
        return tmp * tmp * powHelper (x, n % 2);
    }
	
    double pow(double x, int n) {
        return powHelper(x, n);
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

