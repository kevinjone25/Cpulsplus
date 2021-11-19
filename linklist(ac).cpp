#include <iostream>
#include <string>
using namespace std;
int count=0;
struct element{
		int num;
		element *next;
};
void insert(element *current){
	int insertNum;
	cin>>insertNum;
	string ts;
	cin>>ts;
	int indexNum;
	cin>>indexNum;
	if(indexNum>count){
		cout<<"Index is out of range!!"<<endl;
		return;
	}
	for(int i=0;i<indexNum;++i){
		current=current->next;
	}
	element *temp=new element();
	temp->next=current->next;
	current->next=new element();
	current=current->next;
	current->num=insertNum;
	current->next=temp->next;
	delete temp;
	count+=1;
	return;
}
void add(element *current){
	int addNum;
	cin>>addNum;
	while(current->next!=NULL)
	current=current->next;
	current->next=new element();
	current=current->next;
	current->next=NULL;
	current->num=addNum;
	count+=1;
	return;
}
void reverse(element *head, element *current){
	element *pre=new element();
	element *future=new element();
	pre=NULL;
	current=current->next;
	future=current->next;
	while(future!=NULL){
		current->next=pre;
		pre=current;
		current=future;
		future=future->next;
	}
	current->next=pre;
	head->next=current;
	return;
}
void deletele(element *current, element *head){
	int delNum;
	cin>>delNum;
	if(delNum>count){
		cout<<"Index is out of range!!"<<endl;
		return;
	}
	element *temp=new element();
	if(delNum==1)
	{
	temp=head->next;
	head->next=temp->next;
	delete temp;
	return;
	}
	for(int i=0;i<delNum-1;++i){
        current=current->next;
	}
		temp=current->next;
		current->next=temp->next;
		delete temp;
		return;
}
void print(element *current){
	while(current->next!=NULL){
		current=current->next;
		if(current->next==NULL)
		cout<<current->num;
		else
		cout<<current->num<<" ";
	}
	cout<<endl;
	return;
}
int main(){
string s;
char c;
element *head=new element();
head->next=NULL;
element *current=head;
while(cin>>s){
switch(s[0]){
	case 'A':
		add(current);
		break;
	case 'I':
		insert(current);
		break;
	case 'D':
		deletele(current,head);
		break;
	case 'R':
		reverse(head,current);
		break;
}
current=head;
print(current);
current=head;
}
return 0;
}