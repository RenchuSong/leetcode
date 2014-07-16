//
//  main.cpp
//  Anagrams
//
//  Created by Renchu Song on 15/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		vector<string> result;
        map<string, vector<string>> count;
		for (int i = 0; i < strs.size(); ++i) {
			string s = strs[i];
			sort(s.begin(), s.end());
			count[s].push_back(strs[i]);
		}
		for (map<string, vector<string>>::iterator it = count.begin(); it != count.end(); ++it) {
			int l = (int)(*it).second.size();
			if (l > 1) {
				for (int i = 0; i < l; ++i)
					result.push_back((*it).second[i]);
			}
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<string> s {"dog","cat","god","tac"};
	vector<string> str = (new Solution())->anagrams(s);
	for (string s: str) cout << s << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

