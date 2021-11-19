#include <iostream>

using namespace std;
struct matrix{
	int row;
	int col;
	int val;
};

int main(){
int m,n,ansr,ansc,row,col,count=0;
cin>>m>>n;
ansr=m;
int matrix1[m][n];
for(row=0;row<m;++row){
	for(col=0;col<n;++col){
		cin>>matrix1[row][col];
		if(matrix1[row][col]!=0)
			count++;
	}
}
matrix fm[count+1];
fm[0].row=m;
fm[0].col=n;
fm[0].val=count;
count=1;
for(row=0;row<m;++row){
	for(col=0;col<n;++col){
		if(matrix1[row][col]!=0){
			fm[count].row=row;
			fm[count].col=col;
			fm[count].val=matrix1[row][col];
			count++;
		}
	}
}
count=0;

cin>>m>>n;
ansc=n;
int matrix2[m][n];
for(row=0;row<m;++row){
	for(col=0;col<n;++col){
		cin>>matrix2[row][col];
		if(matrix2[row][col]!=0)
			count++;
	}
}
matrix sm[count+1];
sm[0].row=m;
sm[0].col=n;
sm[0].val=count;
count=1;
for(row=0;row<m;++row){
	for(col=0;col<n;++col){
		if(matrix2[row][col]!=0){
			sm[count].row=row;
			sm[count].col=col;
			sm[count].val=matrix2[row][col];
			count++;
		}
	}
}

int ans[ansr][ansc];
for(row=0;row<ansr;++row){
	for(col=0;col<ansc;++col){
	  ans[row][col]=0;
	}
}

for(int i=1;i<=fm[0].val;++i){
	for(int j=1;j<=sm[0].val;++j){
		if(fm[i].col==sm[j].row&&fm[i].val*sm[j].val)
			ans[fm[i].row][sm[j].col]+=fm[i].val*sm[j].val;
	}
}
/*
for(row=0;row<ansr;++row){
	for(col=0;col<ansc;++col){
	  cout<<ans[row][col];
	}
	cout<<endl;
}*/
for(row=0;row<ansr;++row){
	for(col=0;col<ansc;++col){
	    if(ans[row][col]!=0)
		cout<<row<<" "<<col<<" "<<ans[row][col]<<endl;
	}
}
}