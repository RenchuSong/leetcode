//
//  main.cpp
//  Two Sum
//
//  Created by Renchu Song on 10/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	// Time Complexity: O(NlogN)
	vector<int> twoSumNlogN(vector<int> &numbers, int target) {
		vector<int> tmp = numbers;
		sort(tmp.begin(), tmp.end());
		int l = 0, r = (int) tmp.size() - 1;
		while (l < r) {
			int mid = tmp[l] + tmp[r];
			if (mid == target) break;
			if (mid < target) ++l; else --r;
		}
		
		int index1 = 0, index2 = 0;
		for (int i = 0; i < tmp.size(); ++i) {
			if (numbers[i] == tmp[l]) { index1 = i; break; }
		}
		for (int i = (int)tmp.size() - 1; i >= 0; --i) {
			if (numbers[i] == tmp[r]) { index2 = i; break; }
		}
		
		if (index1 > index2) { index1 ^= index2; index2 ^= index1; index1 ^= index2;  }
		vector<int> result {index1 + 1, index2 + 1};
		return result;
	}
	
	// Time Complexity: O(N)
	vector<int> twoSum(vector<int> &numbers, int target) {
		int index1 = 0, index2 = 0;
		// Special Case: target = a + a, cannot be solved by map
		for (int i = 0; i < numbers.size(); ++i) {
			if (numbers[i] == target / 2) {
				if (index1 == 0) index1 = i + 1; else index2 = i + 1;
			}
		}
		
		if (index1 > 0 && index2 > 0) {
			vector<int> result { index1, index2 };
			return result;
		}
		
		unordered_map<int, int> m;
		for (int i = 0; i < numbers.size(); ++i) m[numbers[i]] = i + 1;
		for (int i = 0; i < numbers.size(); ++i) {
			if (m[target - numbers[i]] && m[target - numbers[i]] != i + 1) {
				index1 = m[numbers[i]];
				index2 = m[target - numbers[i]];
				break;
			}
		}
		
		if (index1 > index2) { index1 ^= index2; index2 ^= index1; index1 ^= index2;  }
		
		vector<int> result { index1, index2 };
		return result;
	}
};

int main(int argc, const char * argv[])
{
	vector<int> a {3, 2, 4};
	cout << (new Solution())->twoSum(a, 6)[0] << " "  << (new Solution())->twoSum(a, 6)[1]<< endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

