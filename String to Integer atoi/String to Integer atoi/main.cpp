//
//  main.cpp
//  String to Integer atoi
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        long long ans = 0, sig = 1;
		int state = 0;	// 0: init; 1: signature; 2: number; 3: termimal
		for (int i = 0; i < strlen(str); ++i) {
			char cond = str[i];
			if (state == 0) {
				if (cond == ' ') continue;
				else if (cond == '+') { sig = 1; state = 1; }
				else if (cond == '-') { sig = -1; state = 1; }
				else if (cond >= '0' && cond <= '9') { state = 2; ans = ans * 10 + cond - '0'; }
				else break;
			} else if (state == 1) {
				if (cond >= '0' && cond <= '9') { state = 2; ans = ans * 10 + cond - '0'; }
				else break;
			} else if (state == 2) {
				if (cond >= '0' && cond <= '9') { state = 2; ans = ans * 10 + cond - '0'; }
				else break;
			}
		}
		
		ans *= sig;
		
		return ans > INT_MAX ? INT_MAX : (ans < INT_MIN ? INT_MIN : (int)ans);
    }
};

int main(int argc, const char * argv[])
{

	const char *str1 = "42";
    const char *str2 = "3.14159";
    const char *str3 = "31337 with words";
    const char *str4 = "words and 2";
	const char *str5 = " -1e5";
    const char *str6 = "3.94159";
    const char *str7 = "-20147483648";
    const char *str8 = "   ";
	
	long long a = -2147483649;
	cout << (int)a << endl;
	
	
    int num1 = (new Solution())->atoi(str1);
    int num2 = (new Solution())->atoi(str2);
    int num3 = (new Solution())->atoi(str3);
    int num4 = (new Solution())->atoi(str4);
	int num5 = (new Solution())->atoi(str5);
    int num6 = (new Solution())->atoi(str6);
    int num7 = (new Solution())->atoi(str7);
    int num8 = (new Solution())->atoi(str8);
	
	
    std::cout << "std::atoi(\"" << str1 << "\") is " << num1 << '\n';
    std::cout << "std::atoi(\"" << str2 << "\") is " << num2 << '\n';
    std::cout << "std::atoi(\"" << str3 << "\") is " << num3 << '\n';
    std::cout << "std::atoi(\"" << str4 << "\") is " << num4 << '\n';
	std::cout << "std::atoi(\"" << str5 << "\") is " << num5 << '\n';
    std::cout << "std::atoi(\"" << str6 << "\") is " << num6 << '\n';
    std::cout << "std::atoi(\"" << str7 << "\") is " << num7 << '\n';
    std::cout << "std::atoi(\"" << str8 << "\") is " << num8 << '\n';
	

    return 0;
}

