//
//  main.cpp
//  Plus One
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
		int	cont = 1;
		for (int i = (int)digits.size() - 1; i >= 0; i--) {
			int tmp = digits[i] + cont;
			result.push_back(tmp % 10);
			cont = tmp / 10;
		}
		if (cont > 0) result.push_back(1);
		reverse(result.begin(), result.end());
		return result;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

