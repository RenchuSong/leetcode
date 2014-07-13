//
//  main.cpp
//  Insert Interval
//
//  Created by Renchu Song on 13/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace::std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> result;
		if (intervals.size() == 0) {
			result.push_back(newInterval);
			return result;
		}
		
		int l = 0, r = 0;
		for (; l < intervals.size(); ++l) {
			if (intervals[l].end < newInterval.start) result.push_back(intervals[l]);
			else break;
		}
		for (r = l; r < intervals.size(); ++r) {
			if (intervals[r].start > newInterval.end) break; else {
				if (intervals[r].start < newInterval.start) newInterval.start = intervals[r].start;
				if (intervals[r].end > newInterval.end) newInterval.end = intervals[r].end;
			}
		}
		result.push_back(newInterval);
		for (; r < intervals.size(); ++r)
			result.push_back(intervals[r]);
		return result;
    }
};

int main(int argc, const char * argv[])
{
	Interval a(1, 2);
	Interval b(3, 5);
	Interval c(6, 7);
	Interval d(8, 10);
	Interval e(12, 16);
	
	vector<Interval> ins;
	ins.push_back(a);
	ins.push_back(b);
	ins.push_back(c);
	ins.push_back(d);
	ins.push_back(e);
	
	Interval x(4, 9);
	
	vector<Interval> result = (new Solution())->insert(ins, x);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i].start << " " << result[i].end << endl;
	}
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

