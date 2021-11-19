//往深處查找看目前總和是否能達成邊長，若有任何一根棍子無法達成一邊停止搜查(?)
#include <iostream>
#include<algorithm>
#include<functional>
using namespace std;
#define MAX 100
int M,on,side;
int stick[MAX];
bool t[MAX];
void dfs(int ssum,int s,int st)
{
    if(on)
    return;
    if(s==3)
    {
    cout<<"yes"<<endl;
    on=1;
    return;
    }
    if(ssum==side)
    {
        dfs(0,s+1,0);
        return;
    }
    int i;
    for(i=st;i<M;i++)
    {
        if(t[i]||ssum+stick[i]>side)
        continue;
        t[i]=true;
        dfs(ssum+stick[i],s,i+1);
        t[i]=false;
        if(on)
        return;
        //重複查找是否可以省略及判斷為no部分尚未完成
        
    }
    
    
}
int main()
{
    int N,i,j;
    cin>>N;
    for(i=0;i<N;i++)
    {
        on=0;
        cin>>M;
        int sum=0,max=0;
        for(j=0;j<M;j++)
        {
            cin>>stick[j];
            sum+=stick[j];
            if(stick[j]>max)
            max=stick[j];
        }
        if(sum%4!=0||max>(side=sum/4))
        {
            cout<<"no"<<endl;
            continue;
        }
        sort(stick,stick+M,greater<int>());
        dfs(0,0,0);
        if(on==0)
        cout<<"no"<<endl;
        
    }

return 0;
}
