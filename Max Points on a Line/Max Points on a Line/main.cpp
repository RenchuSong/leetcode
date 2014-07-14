//
//  main.cpp
//  Max Points on a Line
//
//  Created by Renchu Song on 13/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};


class Solution {
public:
    int maxPoints(vector<Point> &points) {
		int n = (int)points.size();
        unordered_map<double, int> slope;
		int v = 0, h = 0, ans = 0;
		for (int i = 0; i < n; ++i) {
			slope.clear();
			v = 0; h = 0;
			int c = 0;
			for (int j = 0; j < n; ++j) {
				if (points[j].x == points[i].x && points[j].y == points[i].y) {
					++c;
				} else if (points[j].x == points[i].x) ++v;
				else if (points[j].y == points[i].y) ++h;
				else {
					double s = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
					slope[s]++;
				}
			}
			if (v + c > ans) ans = v + c;
			if (h + c > ans) ans = h + c;
			for (unordered_map<double, int>::iterator it = slope.begin(); it != slope.end(); ++it) {
				if ((*it).second + c > ans) ans = (*it).second + c;
			}
		}
		return ans;
    }
};

int main(int argc, const char * argv[])
{
	vector<Point> points;
	Point p1(84,250);
	Point p2(0,0);
	Point p3(1,0);
	Point p4(0,-70);
	Point p5(0,-70);
	Point p6(1,-1);
	Point p7(21,10);
	Point p8(42,90);
	Point p9(-42,-230);
	
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);
	points.push_back(p5);
	points.push_back(p6);
	points.push_back(p7);
	points.push_back(p8);
	points.push_back(p9);
	
	
	cout << (new Solution())->maxPoints(points) << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

