#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
using namespace std;
struct poly
{
	int pow;
	float cof;
	poly *next;
};
int cmp(poly *a,poly *b)
{
	if (a->pow<b->pow) return  -1;
	else if(a->pow == b->pow) return  0;
	else return 1;
}
int main()
{
	 poly *head=new poly();
	head->next=NULL;
	int signflag=0,powflag=0,cofflag=1;
	string pow,cof;
	string poly1, poly2;
	cin>>poly1;
	cin>>poly2;
	poly *current=head;
	for(int i=0;poly1[i]!='\0';++i)    
	{
	    
		if(poly1[i]=='+')
		{
		    cofflag=1;
			continue;
		}
		else if(poly1[i]=='-')
		{
		    cofflag=1;
			signflag=1;
			continue;
		}
		else if(poly1[i]=='x')
		{
			powflag=1;
			cofflag=0;
			continue;
		}
		else if(poly1[i]=='^')
			continue;
		else if(('0'<=poly1[i]<='9' || poly1[i]=='.')&& cofflag==1)
		{
			cof.append(poly1,i,1);
			if(poly1[i+1]=='\0')
			{
				if(signflag==1)
				{
					current->cof=-atof(cof.c_str());
					signflag=0;
					break;
				}
				else
				{
					current->cof=atof(cof.c_str());
					break;
				}
			}
		}
		if(powflag==1)
		{
		    pow.append(poly1,i,1);
		    if(poly1[i+1]=='+'||poly1[i+1]=='-'||poly1[i+1]=='\0')
		    powflag=0;
		}
		if(powflag==0&&cofflag==0)
		{
		    if(cof.empty())
		    {
		        if(signflag==1)
		        {
		            current->cof=-1;
		            current->pow=atoi(pow.c_str());
		            signflag=0;
		        }
		        else
		        {
		            current->cof=1;
		            current->pow=atoi(pow.c_str());
		        }
		    }
		    else
		    {
		        if(signflag==1)
		        {
		            current->cof=-atof(cof.c_str());
		            current->pow=atoi(pow.c_str());
		            signflag=0;
		        }
		        else
		        {
		            current->cof=atof(cof.c_str());
		            current->pow=atoi(pow.c_str());
		        }
		    }
		    current->next=new poly();
		    current=current->next;
		    current->next=NULL;
			pow.clear();
			cof.clear();	
		}
	}
	cofflag=1;
	pow.clear();
	cof.clear();
	powflag=0;
	signflag=0;
	poly *head1=new poly();
	head1->next=NULL;
	poly *current1=head1;
	for(int i=0;poly2[i]!='\0';++i)    
	{
	    
		if(poly2[i]=='+')
		{
		    cofflag=1;
			continue;
		}
		else if(poly2[i]=='-')
		{
		    cofflag=1;
			signflag=1;
			continue;
		}
		else if(poly2[i]=='x')
		{
		    cofflag=0;
			powflag=1;
			continue;
		}
		else if(poly2[i]=='^')
			continue;
		else if(('0'<=poly2[i]<='9' || poly2[i]=='.')&&cofflag==1)
		{
			cof.append(poly2,i,1);
			if(poly2[i+1]=='\0')
			{
				if(signflag==1)
				{
					current1->cof=-atof(cof.c_str());
					signflag=0;
					break;
				}
				else
				{
					current1->cof=atof(cof.c_str());
					break;
				}
			}
		}
		if(powflag==1)
		{
		    pow.append(poly2,i,1);
		    if(poly2[i+1]=='+'||poly2[i+1]=='-'||poly2[i+1]=='\0')
		    powflag=0;
		}
		if(powflag==0&&cofflag==0)
		{
		        if(cof.empty())
		        {
		            if(signflag==1)
		            {
		                current1->cof=-1;
		                current1->pow=atoi(pow.c_str());
		                signflag=0;
		            }
		            else
		            {
		                current1->cof=1;
		                current1->pow=atoi(pow.c_str());
		            }
		        }
		        else
		        {
		            if(signflag==1)
		            {
		                current1->cof=-atof(cof.c_str());
		                current1->pow=atoi(pow.c_str());
		                signflag=0;
		            }
		            else
		            {
		             current1->cof=atof(cof.c_str());
		             current1->pow=atoi(pow.c_str());
		            }
		        }
		    current1->next=new poly();
		    current1=current1->next;
		    current1->next=NULL;
			pow.clear();
			cof.clear();	
		}
	}
/*current=head;
current1=head1;
while(current!=NULL)
{
    cout<<current->cof<<" "<<current->pow<<endl;
    current=current->next;
}
while(current1!=NULL)
{
    cout<<current1->cof<<" "<<current1->pow<<endl;
    current1=current1->next;
}*/
vector<float> vc;
	vector<int> vp;
	current=head;
	current1=head1;
	while(current&&current1)
	{
		switch(cmp(current,current1))
		{
			case 1:
				vc.push_back(current->cof);
				vp.push_back(current->pow);
				current=current->next;
				break;
			case -1:
				vc.push_back(current1->cof);
				vp.push_back(current1->pow);
				current1=current1->next;
				break;
			case 0:
				if((current->cof+current1->cof)==0)
				{
					current=current->next;
					current1=current1->next;
					break;
				}
				vc.push_back((current->cof)+(current1->cof));
				vp.push_back(current->pow);
				current=current->next;
				current1=current1->next;
		}

	}
	while(current1==NULL^current==NULL)
	{
		if(current1==NULL)
		{
		vc.push_back(current->cof);
		vp.push_back(current->pow);
		current=current->next;
		}
		if(current==NULL)
		{
		vc.push_back(current1->cof);
		vp.push_back(current1->pow);
		current1=current1->next;
		}
	}
	
	for(int i=0;i<vc.size();++i)
	{
	    if(vp[i]==0)
			cout<<vc[i];
		else if(vc[i+1]>0)
		    if(vc[i]==1)
		         cout<<"x^"<<vp[i]<<"+";
		    else if(vc[i]==-1 )
		         cout<<"-x^"<<vp[i]<<"+";
		    else
		        cout<<vc[i]<<"x^"<<vp[i]<<"+";
		else if(vc[i+1]<0)
		    if(vc[i]==1)
		         cout<<"x^"<<vp[i];
		    else if(vc[i]==-1 )
		         cout<<"-x^"<<vp[i];
		    else
		        cout<<vc[i]<<"x^"<<vp[i];
		  
		else
		    cout<<vc[i]<<"x^"<<vp[i];
		 
	}
    if(vc.empty())
    cout<<"0";
	return 0;
}