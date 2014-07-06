//
//  main.cpp
//  Search a 2D Matrix
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.size() == 0) return false;
        int n = (int)matrix.size(), m = (int)matrix[0].size();
		int left = 0, right = n * m - 1;
		while (left <= right) {
			int mid = (left + right) >> 1;
			int pos = matrix[mid / m][mid % m];
			if (pos == target) return true;
			if (pos > target) right = mid - 1; else left = mid + 1;
		}
		return false;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

