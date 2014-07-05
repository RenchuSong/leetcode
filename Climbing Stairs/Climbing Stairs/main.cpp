//
//  main.cpp
//  Climbing Stairs
//
//  Created by Renchu Song on 4/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a[3] = {0, 1, 2};
		for (int i = 3; i <= n; ++i) {
			a[i % 3] = a[(i + 1) % 3] + a[(i + 2) % 3];
		}
		return a[n % 3];
    }
};

int main(int argc, const char * argv[])
{
	for (int i = 1; i <= 10; ++i)
		cout << (new Solution())->climbStairs(i) << endl;
    return 0;
}

