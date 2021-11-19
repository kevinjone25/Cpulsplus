#include <iostream>
#include <stack>
using namespace std;
int found=0;
int m,n;

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
		if(ne.row==cu.row && ne.col==cu.col)
			return false;
		else
			return true;
	}
	return false;
}
void dfs(int** map,pos cur)
{
    
    pos next;
	if(found==1)
	{
		return;
	}
	next.row=cur.row+1;
	next.col=cur.col+1;

	if(checkAccess(map[cur.row+1][cur.col+1],next,cur)&& !(next.row<0 ||next.col<0||next.row>m-1||next.col>n-1))						   		//(1,1) cur=(0,0)
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
	next.col=cur.col+1;

	if(checkAccess(map[cur.row][cur.col+1],next,cur)&& !(next.row<0 ||next.col<0||next.row>m-1||next.col>n-1))							//(0,1)
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
	next.row=cur.row+1;

	if(checkAccess(map[cur.row+1][cur.col],next,cur)&& !(next.row<0 ||next.col<0||next.row>m-1||next.col>n-1))							//(1,0)
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
	next.row=cur.row-1;
	next.col=cur.col+1;

	if(checkAccess(map[cur.row-1][cur.col+1],next,cur)&&!(next.row<0 ||next.col<0||next.row>m-1||next.col>n-1))					    //(-1,1)
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
	next.row=cur.row-1;

	if(checkAccess(map[cur.row-1][cur.col],next,cur)&& !(next.row<0 ||next.col<0||next.row>m-1||next.col>n-1))							//(-1,0)
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
	next.col=cur.col-1;

	if(checkAccess(map[cur.row][cur.col-1],next,cur)&& !(next.row<0 ||next.col<0||next.row>m-1||next.col>n-1))							//(0,-1)
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
	next.row=cur.row+1;
	next.col=cur.col-1;

	if(checkAccess(map[cur.row+1][cur.col-1],next,cur)&& !(next.row<0 ||next.col<0||next.row>m-1||next.col>n-1))					    //(1,-1)
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
	next.row=cur.row-1;
	next.col=cur.col-1;
	if(checkAccess(map[cur.row-1][cur.col-1],next,cur)&& !(next.row<0 ||next.col<0||next.row>m-1||next.col>n-1))							//(-1,-1)
	{
	    map[cur.row][cur.col]=1;
		dfs(map,next);
		if(found==1)
	    {
	    p.push({next.row+1,next.col+1});
		return;
	    }	
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
for(int i = 0; i < n; ++i){ b[i] = maze[i]; }
/*for(row=0;row<m;++row)
{
	for(col=0;col<n;++col)
	{
		cout<<maze[row][col];
	}
}*/
dfs(b,entry);
p.push({1,1});
while(!(p.empty()))
{
if(p.size()!=1)
cout<<p.top().row<<" "<<p.top().col<<endl;
else
cout<<p.top().row<<" "<<p.top().col;
p.pop();
}
p.clear();
return 0;
}