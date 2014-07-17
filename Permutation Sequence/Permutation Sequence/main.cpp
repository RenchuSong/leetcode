//
//  main.cpp
//  Permutation Sequence
//
//  Created by Renchu Song on 16/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string result = "";
		if (n < 2) {
			result += (n + '0');
			return result;
		}
		int mul[n + 1];
		mul[0] = mul[1] = 1;
		for (int i = 2; i <= n; ++i) mul[i] = mul[i - 1] * i;
		k = (k - 1) % mul[n] + 1;
		k--;
		int ans[n + 1];
		memset(ans, 0, sizeof(ans));
		for (int i = n; i > 0; --i) {
			int p = k / mul[i - 1];
			k %= mul[i - 1];
			int j, c = 0;
			for (j = 1; j <= n; ++j) {
				bool flag = true;
				for (int k = i + 1; k <= n; ++k) {
					if (ans[k] == j) {
						flag = false; break;
					}
				}
				if (flag) ++c;
				if (c == p + 1) break;
			}
			ans[i] = j;
		}
		for (int i = n; i > 0; --i) result += (ans[i] + '0');
		return result;
    }
};

int main(int argc, const char * argv[])
{
	for (int i = 1; i < 100; ++i)
	cout << (new Solution())->getPermutation(5, i) << endl;
	cout << (new Solution())->getPermutation(5, 120) << endl;
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

