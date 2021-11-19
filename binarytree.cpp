#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int, vector<int> > tree;
	map<int, bool> visit;
	queue<pair<int, int> > q;
	int parent, left, right, h = 0, flag = 0, leaf = 0, root = 0, rootFlag = 0;
	
	while(cin >> parent >> left >> right){
		if(left != 0){
			tree[parent].push_back(left);
			visit[left] = false;
		}	
		if(right != 0){
			tree[parent].push_back(right);
			visit[right] = false;
		}
		visit[parent] = false;
		if(!rootFlag){
			rootFlag = 1;
			root = parent;
		}
	}
	if(tree.size() != 0){
		q.push(make_pair(root, 1));
		while(!q.empty()){
			h = q.front().second;
			visit[q.front().first] = true;
			for(int i = 0; i < tree[q.front().first].size(); i++){
				if(tree[q.front().first][i] != 0)	q.push(make_pair(tree[q.front().first][i], q.front().second + 1));
			}
			if(tree[q.front().first].size() == 0)
				leaf++;
			q.pop();
		}
		
		map<int, bool> ::iterator v_iter;
		for(v_iter = visit.begin(); v_iter != visit.end(); v_iter++){
			if(v_iter -> first != 0 && v_iter -> second == false){
				flag = 1;
				break;
			}
		}
		
		if(flag)	cout << "Invalid tree\n";	
		else	cout << h << "\n" << leaf << "\n";
	}else	cout << "Tree is empty\n";
	
}