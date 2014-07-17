//
//  main.cpp
//  Clone Graph
//
//  Created by Renchu Song on 16/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	unordered_map<int, int> visit;
	
	void dfs(UndirectedGraphNode* node) {
		if (visit[node->label] > 0) return;
		visit[node->label] = 1;
		for (UndirectedGraphNode* tmp: node->neighbors) dfs(tmp);
		node->neighbors.push_back(new UndirectedGraphNode(node->label));
	}
	
	void dfs2(UndirectedGraphNode* node) {
		if (visit[node->label] > 0) return;
		visit[node->label] = 1;
		int n = (int)node->neighbors.size() - 1;
		for (int i = 0; i < n; ++i) dfs2(node->neighbors[i]);
		if (n > 0) {
			UndirectedGraphNode* tmp = node->neighbors[n];
			for (int i = 0; i < n; ++i) {
				UndirectedGraphNode* mm = node->neighbors[i];
				tmp->neighbors.push_back(mm->neighbors[(int)mm->neighbors.size() - 1]);
			}
		}
	}
	
	void dfs3(UndirectedGraphNode* node) {
		if (visit[node->label] > 0) return;
		visit[node->label] = 1;
		int n = (int)node->neighbors.size() - 1;
		for (int i = 0; i < n; ++i) dfs3(node->neighbors[i]);
		node->neighbors.pop_back();
	}
	
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
        dfs(node);
		visit.clear();
		dfs2(node);
		visit.clear();
		UndirectedGraphNode * result = node->neighbors[(int)node->neighbors.size() - 1];
		dfs3(node);
		return result;
    }
};

unordered_map<int, int> visit;
void dfs(UndirectedGraphNode* node) {
	if (visit[node->label] > 0) return;
	visit[node->label] = 1;
	cout << node->label << ":";
	for (UndirectedGraphNode* tmp: node->neighbors) {
		cout << tmp->label << " ";
	}
	cout << endl;
	for (UndirectedGraphNode* tmp: node->neighbors) {
		dfs(tmp);
	}
}

int main(int argc, const char * argv[])
{
	UndirectedGraphNode* p1 = new UndirectedGraphNode(1);
	UndirectedGraphNode* p2 = new UndirectedGraphNode(0);
	UndirectedGraphNode* p3 = new UndirectedGraphNode(2);
	
	p1->neighbors.push_back(p2);
	p1->neighbors.push_back(p3);
	
	p2->neighbors.push_back(p1);
	p2->neighbors.push_back(p3);
	
	p3->neighbors.push_back(p1);
	p3->neighbors.push_back(p2);
	p3->neighbors.push_back(p3);
	
	
	UndirectedGraphNode* c = (new Solution())->cloneGraph(p1);
	dfs(c);
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

