//
//  main.cpp
//  Triangle
//
//  Created by Renchu Song on 7/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.size() < 1) return 0;
        vector<int> tmp[2];
		for (int i = 0; i < triangle.size(); ++i) {
			tmp[0].push_back(0);
			tmp[1].push_back(0);
		}
		tmp[0][0] = triangle[0][0];
		for (int i = 1; i < triangle.size(); ++i) {
			int now = i % 2, pre = 1 - now;
			tmp[now][0] = tmp[pre][0] + triangle[i][0];
			for (int j = 1; j < i; ++j)
				tmp[now][j] = min(tmp[pre][j - 1], tmp[pre][j]) + triangle[i][j];
			tmp[now][i] = tmp[pre][i - 1] + triangle[i][i];
		}
		int now = (int)(triangle.size() - 1) % 2;
		int result = tmp[now][0];
		for (int i = 1; i < triangle.size(); ++i) result = min(result, tmp[now][i]);
		return result;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

