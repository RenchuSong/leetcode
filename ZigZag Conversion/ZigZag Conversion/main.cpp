//
//  main.cpp
//  ZigZag Conversion
//
//  Created by Renchu Song on 13/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        int len = (int) s.length();
		int period = 2 * nRows - 2;
		if (period < 1) period = 1;
		int base = len / period, mod = len % period;
		int rowSize[nRows];
		rowSize[0] = rowSize[nRows - 1] = base;
		for (int i = 1; i < nRows - 1; ++i) rowSize[i] = 2 * base;
		for (int i = 0; i < mod; ++i) if (i < nRows) ++rowSize[i]; else ++rowSize[nRows - (i - nRows + 2)];
		for (int i = 1; i < nRows; ++i) rowSize[i] += rowSize[i - 1];
		for (int i = nRows - 1; i > 0; --i) rowSize[i] = rowSize[i - 1];
		rowSize[0] = 0;
		char str[len + 1];
		int now = 0, d = nRows > 1 ? 1 : 0;
		for (int i = 0; i < len; ++i) {
			str[rowSize[now]++] = s[i];
			if (now + d < 0 || now + d > nRows - 1) d = -d;
			now += d;
		}
		str[len] = 0;
		string result = str;
		return result;
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->convert("PAYPA", 1) << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

