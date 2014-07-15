//
//  main.cpp
//  Text Justification
//
//  Created by Renchu Song on 14/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string format(vector<string> &words, int l, int r, int L, int subLen) {
		if (l == r) {
			string str = words[l];
			str.append(L - subLen, ' ');
			return str;
		}
		string str = "";
		int space = L - subLen;
		int num = space / (r - l);
		int mod = space % (r - l);
		for (int i = l; i < r; ++i) {
			str += words[i];
			str.append(i - l >= mod ? num : num + 1, ' ');
		}
		str += words[r];
		return str;
	}
	
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
		int sub = 0, left = 0;
		int i;
		for (i = 0; i < words.size(); ++i) {
			if (sub + words[i].length() + i - left > L) {
				result.push_back(format(words, left, i - 1, L, sub));
				sub = (int)words[i].length();
				left = i;
			} else sub += (int)words[i].length();
		}
		if (left < words.size()) {
			string last = "";
			for (int i = left; i < words.size(); ++i) {
				last += words[i];
				if (i < words.size() - 1) last += " ";
			}
			last.append(L - last.length(), ' ');
			result.push_back(last);
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<string> words {"This", "is", "an", "example", "of", "text", "justification."};
	vector<string> result = (new Solution())->fullJustify(words, 45);
	for (string s : result) cout << s << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

