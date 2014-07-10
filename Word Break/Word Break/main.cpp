//
//  main.cpp
//  Word Break
//
//  Created by Renchu Song on 9/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = (int)s.length();
        bool a[n];
        for (int i = 0; i < n; ++i) a[i] = false;
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
        	if (s.compare(0, (int)(*it).length(), (*it)) == 0) a[(int)(*it).length() - 1] = true;
        }
        for (int i = 1; i < n; ++i) if (a[i - 1]) {
        	for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
		    	if (s.compare(i, (int)(*it).length(), (*it)) == 0) a[i + (int)(*it).length() - 1] = true;
		    }
        }
        return a[n - 1];
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

