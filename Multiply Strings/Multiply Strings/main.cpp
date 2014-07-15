//
//  main.cpp
//  Multiply Strings
//
//  Created by Renchu Song on 14/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = (int)num1.length(), m = (int)num2.length();
		int a[n + 1], b[m + 1], c[n + m + 2];
		for (int i = 0; i < n; ++i) a[i] = num1[n - i - 1] - '0';
		for (int i = 0; i < m; ++i) b[i] = num2[m - i - 1] - '0';
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				c[i + j] += a[i] * b[j];
		for (int i = 0; i <= n + m; ++i) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
		int t = n + m + 1;
		while (t > 0 && c[t] == 0) --t;
		string str = "";
		for (int i = t; i >= 0; --i) {
			str += c[i] + '0';
		}
		return str;
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->multiply("56", "99") << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

