#include <iostream>
#include <vector>

using namespace std;
vector<int> vec[500];
int edge[500][500] = {-100000};
int flag  = 0;
vector<int> path;
void negitive_cycle(int source, int max,int long_n){
	vector<int>:: iterator now;
	vector<int>:: iterator check;
	int flag = 0;
	for(int i = source; i < max ; ++i){
		now = vec[i].begin();
		path.push_back(i);
		while(now != vec[i].end()){
			check = path.begin();
			while(check != path.end()){
				if(*now = *check){
					flag = 1;
				}
			}
			if(flag = 0){
			long_n += edge[i][*now]
			negitive_cycle(*now,max,long_n);
			}
			else{
				if(long_n < 0 ){
					cout<<"There is a negative cycle!";
					break;
				}
			}
			if(flag = 1){
				break;
			}
		}
		if(flag = 1){
			break;
		}
	}

return;
}





void shorest_path(int source, int max){
	vector<int> can_use;
	vector<int> ready;
	for (int i = source ; i < max ; ++i){
		ready.push_back(i);
	}
	for (int i = source ; i < max ; ++i){
		can_use.push_pack(i);
		vector<int>:: iterator it = can_use.begin();
		while(it != can_use.end()){
			for(int j = source ; j < max ;++j){
			if(edge[i][j] > edge[i][*it]+edge[*it][j] ){
				edge[i][j] = edge[i][*it]+edge[*it][j];
			}
		}
			it++;
		}
	}
return;
}

int main(){

	int source;
	int u,v,e,max = 0;
	while(cin>>u){
		cin>>v>>e;
		if(v > max){
			max = v;
		}
		edge[u][v] = e;
	}


negitive_cycle(source,max,0)
if(flag==1){
shorest_path(source,max);
}
return 0;
} 