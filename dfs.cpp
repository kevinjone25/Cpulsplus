#include <bits/stdc++.h>
using namespace std;
#define MAX 104
#define DN 8
char martrix[MAX][MAX];
int countstar=0;
int max_row,max_col;
int dx[8]={1,1,0,-1,0,1,-1,-1};
int dy[8]={1,0,1,1,-1,-1,0,-1};
void dfs(int now_row, int now_col){
	if(martrix[now_row][now_col]=='*'){
		int flag=1;
		for(int count=0;count<DN;++count){
			if(martrix[now_row+dy[count]][now_col+dx[count]]=='*'){
				flag=0;
				break;
			}
		
	}
	countstar+=flag;
	}
	if(now_row+1<=max_row)
		dfs(now_row+1,now_col);
	else if(now_row+1>max_row&&now_col+1<=max_col)
	        	dfs(1,now_col+1);
	else
		return;
	return ;
}

int main(){
	int col,row;
	while(true){
		cin>>row>>col;
		if(row==0 && col==0){
			break;
		}	
		memset(martrix, 0, sizeof(martrix));
		max_row=row;
		max_col=col;
		for(int rowc=1;rowc<=row;++rowc){
			for(int colc=1;colc<=col;++colc){
				cin>>martrix[rowc][colc];
			}
		}
		dfs(1,1);
		cout<<countstar<<'\n';
		countstar=0;
	
	}
 return 0;
}