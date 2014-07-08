//
//  main.cpp
//  Count and Say
//
//  Created by Renchu Song on 7/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<int> a[2];
		a[0].clear(); a[1].clear();
		a[0].push_back(1);
		for (int i = 1; i < n; ++i) {
			int now = i % 2, pre = 1 - now;
			a[now].clear();
			int dig = a[pre][0], c = 1;
			for (int j = 1; j < a[pre].size(); ++j) {
				if (a[pre][j] == dig) ++c;
				else {
					a[now].push_back(c);
					a[now].push_back(dig);
					dig = a[pre][j];
					c = 1;
				}
			}
			a[now].push_back(c);
			a[now].push_back(dig);
		}
		string s("");
		int p = (n - 1) % 2;
		for (int i = 0; i < a[p].size(); ++i) s += a[p][i] + '0';
		return s;
    }
};

int main(int argc, const char * argv[])
{
	for (int i = 1; i <= 10; ++i) cout << (new Solution())->countAndSay(i) << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

