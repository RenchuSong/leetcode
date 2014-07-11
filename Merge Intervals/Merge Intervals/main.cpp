//
//  main.cpp
//  Merge Intervals
//
//  Created by Renchu Song on 10/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	struct less_than {
		inline bool operator() (const Interval& i1, const Interval& i2) {
			return i1.start < i2.start;
		}
	};
	
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), less_than());
		vector<Interval> result;
		if (intervals.size() > 0) {
			int st = intervals[0].start, en = intervals[0].end;
			for (int i = 1; i < intervals.size(); ++i)
				if (intervals[i].start > en) {
					Interval it(st, en);
					result.push_back(it);
					st = intervals[i].start;
					en = intervals[i].end;
				} else {
					en = max(en, intervals[i].end);
				}
			Interval it(st, en);
			result.push_back(it);
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

