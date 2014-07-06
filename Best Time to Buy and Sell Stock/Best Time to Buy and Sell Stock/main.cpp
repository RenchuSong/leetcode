//
//  main.cpp
//  Best Time to Buy and Sell Stock
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if (prices.size() < 2) return 0;
        int mi = prices[0], prof = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] - mi > prof) prof = prices[i] - mi;
			if (prices[i] < mi) mi = prices[i];
		}
		return prof;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

