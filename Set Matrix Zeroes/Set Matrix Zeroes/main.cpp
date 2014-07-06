//
//  main.cpp
//  Set Matrix Zeroes
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		if (matrix.size() < 1) return;
        int n = (int)matrix.size(), m = (int)matrix[0].size();
		bool c = false, r = false;
		for (int i = 0; i < n; ++i) if (matrix[i][0] == 0) r = true;
		for (int i = 0; i < m; ++i) if (matrix[0][i] == 0) c = true;
		
		for (int i = 1; i < n; ++i)
			for (int j = 1; j < m; ++j)
				if (matrix[i][j] == 0) {
					matrix[i][0]=matrix[0][j] = 0;
				}
		for (int i = 1; i < n; ++i)
			for (int j = 1; j < m; ++j)
				if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
		if (r) for (int i = 0; i < n; ++i) matrix[i][0] = 0;
		if (c) for (int i = 0; i < m; ++i) matrix[0][i] = 0;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

