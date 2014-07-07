//
//  main.cpp
//  Length of Last Word
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = (int)strlen(s);
		int result = 0,acc = 0;
		for (int i = 0; i < len; ++i) {
			if (s[i] != ' ') ++acc;
			else {
				if (acc > 0) result = acc;
				acc = 0;
			}
		}
		if (acc > 0) result = acc;
		return result;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

