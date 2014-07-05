//
//  main.cpp
//  Integer to Roman
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRomanNaive(int num) {
        string result = "";
		map<int, char> a = {
			{1, 'I'},
			{5, 'V'},
			{10, 'X'},
			{50, 'L'},
			{100, 'C'},
			{500, 'D'},
			{1000, 'M'}
		};
		int thousand = num / 1000, hundred = (num % 1000) / 100, ten = (num % 100) / 10;
		num %= 10;
		result.append(thousand, a[1000]);
		
		if (hundred == 9) {
			result += a[100];
			result += a[1000];
		} else if (hundred > 5) {
			result += a[500];
			result.append(hundred - 5, a[100]);
		} else if (hundred > 3) {
			result.append(5 - hundred, a[100]);
			result += a[500];
		} else result.append(hundred, a[100]);
		
		if (ten == 9) {
			result += a[10];
			result += a[100];
		} else if (ten > 5) {
			result += a[50];
			result.append(ten - 5, a[10]);
		} else if (ten > 3) {
			result.append(5 - ten, a[10]);
			result += a[50];
		} else result.append(ten, a[10]);
		
		if (num == 9) {
			result += a[1];
			result += a[10];
		} else if (num > 5) {
			result += a[5];
			result.append(num - 5, a[1]);
		} else if (num > 3) {
			result.append(5 - num, a[1]);
			result += a[5];
		} else result.append(num, a[1]);
		
		return result;
    }
	
	vector<int> interval = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	vector<string> dict = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	
	string intToRoman(int num) {
		for (int i = 0; i < dict.size(); ++i) {
			if (interval[i] <= num) return dict[i] + intToRoman(num - interval[i]);
		}
		return "";
	}
};

int main(int argc, const char * argv[])
{
	for (int i = 1; i < 100; ++i)
		cout << (new Solution())->intToRoman(i) << endl;
    return 0;
}

