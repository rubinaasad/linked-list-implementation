// linked list practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *link;
};

typedef Node* NodePtr;
NodePtr head;




void head_insert(int num)
{
	NodePtr temp_ptr;
	temp_ptr=new Node;
	temp_ptr->data=num;
	temp_ptr->link=head;
	head=temp_ptr;
}
NodePtr search1(int target)
{
	NodePtr here;
	here=head;
	while(here->data!=target && here->link!=NULL)
	{
		here=here->link;
		if(here->data==target)
			return here;
		else
			return NULL;
	}
}

NodePtr search2(int target)
{
	NodePtr here;
	here=head;
	while(here!=0)
	{
		if(here->data==target)
			return here;
		else
			return NULL;
		here=here->link;
	}
}

NodePtr search3(int target)
{
	NodePtr here;
	here=head;
	if(here==NULL)
	{
		return NULL;
	}
	else
	{
		while(here->data!=target && here->link!=NULL)
			here=here->link;
		if(here->data==target)
			return here;
		else
			return NULL;
	}
}

void displayAll()
{
	NodePtr iter;
	cout<<"Displaying all data..." <<endl;
	for(iter=head;iter!=NULL;iter=iter->link)
		cout<<iter->data <<endl;
	system("pause");
}

void traverse()
{
	NodePtr ptemp;
	ptemp=head;
	while(ptemp!=NULL)
	{
		cout<<ptemp->data <<endl;
		ptemp=ptemp->link;
	}
}

void insertAfter(NodePtr afterme,int num)
{
	NodePtr temp_ptr;
	temp_ptr=new Node;
	temp_ptr->data=num;
	temp_ptr->link=afterme->link;
	afterme->link=temp_ptr;
}

bool deleteNode(int num)
{
	NodePtr prev=head;
	NodePtr temp=head->link;
	while(temp!=0)
	{
		if(temp->data==num)
		{
			prev->link=temp->link;
		delete temp;
		return true;
		}
	prev=temp;
	temp=temp->link;
	}
	return false;
}

bool delete_before(int before)
{
	NodePtr prev=head;
	NodePtr temp=head->link;
	while(temp!=0)
	{
		if((temp->link)->data==before)
		{
			prev->link=temp->link;
			delete temp;
			return true;
		}
		prev=temp;
		temp=temp->link;
	}
	return false;

}

bool delete_after(int after)
{
	NodePtr prev=head;
	NodePtr temp=head;
	if(head==0)
	{
		return false;
	}
	else
	{
	while(temp!=0)
	{
		if(temp->data==after)
		{
			prev->link=temp->link->link;
			delete temp->link;
			return true;
		}
		prev=temp;
		temp=temp->link;
	}
	return false;
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	head=new Node;
	head->data=3;
	head->link=NULL;
	int number1;
	cout<<"Enter a number to place in new node: " <<endl;
	cin>>number1;
	head_insert(number1);
	int targ;
	cout<<"Enter a number to search: " <<endl;
	cin>>targ;
	cout<<"Searched through method 1..." <<search1(targ) <<endl;
	cout<<"Searched through method 2..." <<search2(targ) <<endl;
	cout<<"Searched through method 3..." <<search3(targ) <<endl;
	int number1_2;
	cout<<"Enter a number to place in new node: " <<endl;
	cin>>number1_2;
	head_insert(number1_2);
	displayAll();
	cout<<endl;
	traverse();
	cout<<"Enter to search: " <<endl;
	cin>>targ;
	cout<<search1(targ) <<endl;
	int insertafter,number2;
	cout<<"Enter the number you want to place in node: " <<endl;
	cin>>number2;
	cout<<"Inser the number you want to create node after: " <<endl;
	cin>>insertafter;
	
	NodePtr after=head;
	while(after!=0)
	{
		if(after->data==insertafter)
		{
			insertAfter(after,number2);
		}
		after=after->link;
	}
	cout<<endl;
	traverse();
	cout<<"enter the number to delete..." <<endl;
	int num_del;
	cin>>num_del;
	deleteNode(num_del);
	cout<<endl;
	displayAll();
	int before_me;
	cout<<"you want to delete the number before???" <<endl;
	cin>>before_me;
	delete_before(before_me);
	displayAll();
	int after_me;
	cout<<"You want to delete the number after???" <<endl;
	cin>>after_me;
	delete_after(after_me);
	displayAll();


	system("pause");

	return 0;
}