//
//  main.cpp
//  Letter Combinations of a Phone Number
//
//  Created by Renchu Song on 8/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, vector<string> > dict;
        vector<string> zero; zero.push_back(" "); dict['0'] = zero;
        vector<string> two; two.push_back("a"); two.push_back("b");two.push_back("c"); dict['2'] = two;
        vector<string> three; three.push_back("d"); three.push_back("e");three.push_back("f"); dict['3'] = three;
        vector<string> four; four.push_back("g");four.push_back("h");four.push_back("i"); dict['4'] = four;
        vector<string> five; five.push_back("j");five.push_back("k");five.push_back("l"); dict['5'] = five;
        vector<string> six; six.push_back("m"); six.push_back("n"); six.push_back("o");  dict['6'] = six;
        vector<string> seven; seven.push_back("p"); seven.push_back("q");seven.push_back("r");seven.push_back("s"); dict['7'] = seven;
        vector<string> eight; eight.push_back("t"); eight.push_back("u"); eight.push_back("v"); dict['8'] = eight;
        vector<string> nine; nine.push_back("w"); nine.push_back("x"); nine.push_back("y"); nine.push_back("z"); dict['9'] = nine;
        
        stack<pair<char, int> > stk;
        stack<string> tmp;
        
        vector<string> result;
        if (digits.length() == 0) {
        	result.push_back("");
        	return result;
        }
        pair<char, int> first(digits[0], 0);
        string str = dict[digits[0]][0];
        stk.push(first);
        tmp.push(str);
        while (!stk.empty()) {
        	int depth = (int)stk.size();
        	if (depth == digits.length()) {
        		result.push_back(tmp.top());
        	}
        	if (depth < digits.length()) {
        		pair<char, int> second(digits[depth], 0);
        		string str2 = tmp.top() + dict[digits[depth]][0];
        		stk.push(second);
        		tmp.push(str2);
        		continue;
        	}
        	pair<char, int> mid = stk.top();
        	while (mid.second == dict[mid.first].size() - 1) {
        		stk.pop();
        		tmp.pop();
        		if (stk.empty()) break;
        		mid = stk.top();
        	}
        	if (stk.empty()) break;
        	mid.second++;
    		stk.pop();
    		stk.push(mid);
    		string str3 = tmp.top();
    		str3[str3.length() - 1] = dict[mid.first][mid.second][0];
    		tmp.pop();
    		tmp.push(str3);
        }
        return result;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

