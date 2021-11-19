#include <iostream>
#include <stack>
using namespace std;
int found=0;
int m,n;
int i;
int dx[8]={1,1,0,-1,0,1,-1,-1};
int dy[8]={1,0,1,1,-1,-1,0,-1};
struct pos
{
int row=0;
int col=0;
};
stack<pos> p;
bool checkAccess(int check,pos ne,pos cu)
{
	if(ne.row==m-1 &&ne.col==n-1)
	{
		found=1;
		return true;
	}
	if(check==0)
	{
	return true;
	}
	return false;
}
void dfs(int** map,pos cur)
{
	int i=0;
    while(i<=7)
    {
    
    pos next;
    next=cur;
	if(found==1)
	{
	    p.push({next.row+1,next.col+1});
		return;
	}
	next.row=cur.row+dx[i];
	next.col=cur.col+dy[i];

	if(!(next.row<0 ||next.col<0||next.row>m-1||next.col>n-1)&&checkAccess(map[next.row][next.col],next,cur))						   		//(1,1) cur=(0,0)
	{
	    map[cur.row][cur.col]=1;
		dfs(map,next);
		if(found==1)
		{
		p.push({next.row+1,next.col+1});
		return;
		}
		
	}
	next=cur;
	i+=1;
	continue;
	}
	return;
}
int main()
{
pos entry;
int row,col;
cin>>m>>n;
int maze[m][n];
int* b[n];

for(row=0;row<m;++row)
{
	for(col=0;col<n;++col)
	{
		cin>>maze[row][col];
	}
}
for(i = 0; i < n; ++i){ b[i] = maze[i]; }
dfs(b,entry);
p.push({1,1});
while(!(p.empty()))
{
if(p.size()!=1)
cout<<p.top().row<<" "<<p.top().col<<endl;

p.pop();
}
return 0;
}