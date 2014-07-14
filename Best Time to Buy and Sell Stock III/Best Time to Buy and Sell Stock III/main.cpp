//
//  main.cpp
//  Best Time to Buy and Sell Stock III
//
//  Created by Renchu Song on 13/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = (int)prices.size();
		if (n < 2) return 0;
		int p1[n], p2[n];
		p1[0] = 0;
		int mm = prices[0];
		for (int i = 1; i < n; ++i) {
			mm = min(mm, prices[i]);
			p1[i] = prices[i] - mm;
		}
		for (int i = 1; i < n; ++i) p1[i] = max(p1[i], p1[i - 1]);
		
		p2[n - 1] = 0;
		mm = prices[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			mm = max(mm, prices[i]);
			p2[i] = mm - prices[i];
		}
		for (int i = n - 2; i >= 0; --i) p2[i] = max(p2[i], p2[i + 1]);
		
		int ans = 0;
		for (int i = 0; i < n - 1; ++i) ans = max(p2[i], max(p1[i], max(ans, p1[i] + p2[i])));
		
		return ans;
    }
};

int main(int argc, const char * argv[])
{
	vector<int> p {6,1,3,2,4,7};
	
	cout << (new Solution())->maxProfit(p) << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

