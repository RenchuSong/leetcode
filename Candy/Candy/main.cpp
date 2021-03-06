//
//  main.cpp
//  Candy
//
//  Created by Renchu Song on 9/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
		if (ratings.size() == 0) return 0;
        int ans = 1, ind = 0, preGiven = 1, peak = 1;
		for (int i = 1; i < ratings.size(); ++i) {
			if (ratings[i] < ratings[i - 1]) {
				ans += i - ind;
				if (i - ind >= peak) ++ans;
				preGiven = 1;
			} else {
				ind = i;
				if (ratings[i] == ratings[i - 1]) {
					ans++;
					preGiven = 1;
					peak = 1;
				} else {
					ans += ++preGiven;
					peak = preGiven;
				}
			}
		}
		return ans;
    }
};

int main(int argc, const char * argv[])
{
	vector<int> a {58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89};
	//vector<int> a {3,2,1,1,4,3,3};
	cout << (new Solution())->candy(a) << endl;
    return 0;
}

