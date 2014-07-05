//
//  main.cpp
//  Roman to Integer
//
//  Created by Renchu Song on 4/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
		map<char, int> a = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
		};
		int mask = 0, pre = -1;
		for (int i = 0; i < s.length(); ++i) {
			if (a[s[i]] == pre) {
				mask += a[s[i]];
			} else if (a[s[i]] > pre) {
				mask = a[s[i]] - mask;
			} else if (a[s[i]] < pre){
				result += mask;
				mask = a[s[i]];
			}
			pre = a[s[i]];
		}
		return result + mask;
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->romanToInt("XXXIV") << endl;
    return 0;
}

