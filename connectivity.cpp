#include <iostream>
#include <vector>
using namespace std;

int g[9][9]={0};


void addGragh(vector<int> vec[],int source,int target){
	vec[source].push_back(target);
	return;
}


void bfs(int discovered[],vector<int> vec[],int start){
	vector<int> :: iterator iter = vec[start].begin();
	iter++;
	while(iter != vec[start].end() && discovered[*iter]){
		bfs()
	}
	return
}


int main(){
	int vertex,edge;
	int sv,tv;

	

	cin>>vertex>>edge;
	vector<int> vec[10];
	int discovered[10]= {0};

	for(int i = 1 ; i <= vertex ; ++i){
		vec[i].push_back(i);
	}

	for(int i = 0 ; i < edge ; ++i){
		cin>> sv >> tv;
		addGragh(vec,sv,tv);
	}
	bfs(discovered,vec,1);
	


	// for(int i = 1 ; i <= vertex ; ++i){
	// 	vector<int> :: iterator iter = vec[i].begin(); 
	// 	while(iter != vec[i].end()){
	// 		cout<<*iter<<' ';
	// 		iter++;
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}