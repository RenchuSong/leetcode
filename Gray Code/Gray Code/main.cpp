//
//  main.cpp
//  Gray Code
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
		n = 1 << n;
		vector<int> result;
		if (n > 0) {
			result.push_back(0);
			int size = 1, mask = 1;
			while (size < n) {
				for (int i = size; i > 0; --i) {
					result.push_back(mask + result[i - 1]);
					++size;
				}
				mask *= 2;
			}
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<int> result = (new Solution())->grayCode(2);
	for (int i = 0; i < result.size(); ++i) cout << result[i] << endl;
    return 0;
}

