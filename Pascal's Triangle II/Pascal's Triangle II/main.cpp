//
//  main.cpp
//  Pascal's Triangle II
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int a[2][rowIndex + 1];
		a[0][0] = 1;
		for (int i = 1; i <= rowIndex; ++i) {
			int now = i % 2, pre = 1 - now;
			a[now][0] = 1;
			for (int j = 1; j < i; ++j) a[now][j] = a[pre][j - 1] + a[pre][j];
			a[now][i] = 1;
		}
		vector<int> result;
		int ind = rowIndex % 2;
		for (int i = 0; i <= rowIndex; ++i) result.push_back(a[ind][i]);
		return result;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

