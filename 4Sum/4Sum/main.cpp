//
//  main.cpp
//  4Sum
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
	
	bool valid(pair<int, int> p1, pair<int, int> p2) {
		return p1.first != p2.first && p1.first != p2.second && p1.second != p2.first && p1.second!= p2.second;
	}
	
	// TLE solution
    vector<vector<int> > fourSumTLE(vector<int> &num, int target) {
		vector<vector<int> > result;
		int n = (int)num.size();
		if (n < 4) return result;
		
		sort(num.begin(), num.end());
		map<int, vector<pair<int, int> >> container;
		for (int i = 0; i < n - 1; ++i) {
			if (i > 0 && num[i - 1] == num[i]) continue;
			for (int j = i + 1; j < n; ++j) {
				if (j > i + 1 && num[j] == num[i]) continue;
				pair<int, int> p {i, j};
				container[num[i] + num[j]].push_back(p);
			}
		}

		for (map<int, vector<pair<int, int>>>::iterator it = container.begin(); it != container.end(); ++it) {
			int s1 = (*it).first;
			vector<pair<int, int>> v1 = (*it).second;
			int s2 = target - s1;
			vector<pair<int, int>> v2 = container[s2];
			for (pair<int, int> p1: v1)
				for (pair<int, int> p2: v2) if (valid(p1, p2)) {
					vector<int> item {num[p1.first], num[p1.second], num[p2.first], num[p2.second]};
					sort(item.begin(), item.end());
					bool flag = true;
					for (vector<int> a: result) {
						if (a[0] == item[0] && a[1] == item[1] && a[2] == item[2] && a[3] == item[3]) {
							flag = false; break;
						}
					}
					if (flag)
					result.push_back(item);
				}
		}
		
		return result;
    }
	
	// Okay solution
	
	struct less_than_key
	{
		inline bool operator() (const pair<int, pair<int, int> > & p1, const pair<int, pair<int, int> > & p2)
		{
			return p1.first < p2.first;
		}
	};
	
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > result;
		int n = (int)num.size();
		if (n < 4) return result;
		
		vector<pair<int, pair<int, int> > > pairs;
		for (int i = 0; i < n - 1; ++i)
			for (int j = i + 1; j < n; ++j) {
				pair<int, int> item {i, j};
				pair<int, pair<int, int> > ii { num[i] + num[j], item };
				pairs.push_back(ii);
			}
		sort(pairs.begin(), pairs.end(), less_than_key());
		int s = (int)pairs.size();
		int l = 0, r = s - 1;
		while (l < r) {
			int sum = pairs[l].first + pairs[r].first;
			if (sum == target) {
				int thisl = l, thisr = r;
				while (thisl < s - 1 && pairs[thisl + 1].first == pairs[l].first) ++thisl;
				while (thisr > 0 && pairs[thisr - 1].first == pairs[r].first) --thisr;
				
				for (int s = l; s <= thisl; ++s)
					for (int t = r; t >= thisr; --t) {
						if (valid(pairs[s].second, pairs[t].second)) {
							vector<int> item {
								num[pairs[s].second.first],
								num[pairs[s].second.second],
								num[pairs[t].second.first],
								num[pairs[t].second.second]
							};
							sort(item.begin(), item.end());
							bool flag = true;
							for (vector<int> a: result) {
								if (a[0] == item[0] && a[1] == item[1] && a[2] == item[2] && a[3] == item[3]) {
									flag = false; break;
								}
							}
							if (flag) result.push_back(item);
						}
					}
				
				l = thisl + 1; r = thisr - 1;
			} else if (sum < target) ++l; else --r;
		}
		return result;
	}
};

int main(int argc, const char * argv[])
{
	clock_t t = clock();
//	vector<int> a {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
//	vector<vector<int>> result = (new Solution())->fourSum(a, -236727523);
//
//	vector<int> a {1, 0, -1, 0, -2, 2};
//	vector<vector<int>> result = (new Solution())->fourSum(a, 0);
	
	vector<int> a {-3,-2,-1,0,0,1,2,3};
	vector<vector<int>> result = (new Solution())->fourSum(a, 0);
	
	for (vector<int> a : result) {
		for (int b: a) cout << b << " "; cout << endl;
	}
	cout << clock() - t << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

