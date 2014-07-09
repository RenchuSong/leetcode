//
//  main.cpp
//  Add Binary
//
//  Created by Renchu Song on 8/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		int lenA = (int)a.length(), lenB = (int)b.length(), len = max(lenA, lenB);
		string s = "";
		int bit = 0;
		for (int i = 0; i < len; ++i) {
			int p = lenA - i - 1, q = lenB - i - 1;
			int b1 = p < 0 ? 0 : a[p] - '0';
			int b2 = q < 0 ? 0 : b[q] - '0';
			int sum = bit + b1 + b2;
			s = (char)((sum % 2) + '0') + s;
			bit = sum / 2;
		}
		if (bit > 0) s = '1' + s;
		return s;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

