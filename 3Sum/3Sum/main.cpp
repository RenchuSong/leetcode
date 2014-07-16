//
//  main.cpp
//  3Sum
//
//  Created by Renchu Song on 15/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;
		int n = (int)num.size();
		if (n > 2) {
			sort(num.begin(), num.end());
			
			for (int i = 1; i < n - 1; ++i) {
				if (i > 2 && num[i] == num[i - 2]) continue;
				int l = 0, r = n - 1;
				while (l < i && r > i) {
					if (l > 1 && num[l] == num[l - 1]) {
						++l; continue;
					}
					if (r < n - 1 && num[r] == num[r + 1]) {
						--r; continue;
					}
					int sum = num[l] + num[i] + num[r];
					if (sum == 0) {
						vector<int> item { num[l], num[i], num[r] };
						bool flag = false;
						for (int j = 0; j < result.size(); ++j) {
							if (result[j][0] == num[l] && result[j][1] == num[i]) {
								flag = true; break;
							}
						}
						if (!flag) result.push_back(item);
						++l; --r;
					} else if (sum < 0) ++l; else --r;
				}
			}
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	clock_t t = clock();
	vector<int> n {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<vector<int> > result = (new Solution())->threeSum(n);
	for (vector<int> item : result) {
		for (int i: item) cout << i <<  " ";cout << endl;
	}
	cout << clock() - t << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

