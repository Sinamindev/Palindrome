/*--------------------------------------------------------------------------------
		Programmer:	Sina Amini

		Purpose:	Checks if phrase is a palindrome using stack/queue
--------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

struct NODE
{
	char info;
	NODE* next;
};
bool Palindrome(NODE* p, NODE* q);
void MakeStack(int x, NODE* &p);
void MakeQueue(int x, NODE* &p);

int main()
{
	char ans;
	do
	{
		NODE* StackList=NULL;
		NODE* QueueList=NULL;
		char p[10]={};
		//Read phrase into stack and queue
		cout << "	Enter a phrase: ";
		char c;
		while(cin.get(c), c!='\n')
		{
			int i = 0;
			if(c != ' ')
			{
				p[i] = c;
				MakeStack(p[i],StackList);
				MakeQueue(p[i],QueueList);
			}
			i++;
		}

		//checks for palindrome
		bool D = Palindrome(StackList, QueueList);

		if(D==true)
		{cout << "	   Is a PALINDROME\n";}
		else if(D==false) 
		{cout << "	   Not a PALINDROME\n";}
	
		cout << "	CONTINUE(y/n)? ";
		cin >> ans;
		cin.ignore();
		ans = toupper(ans);
		cout << endl;
	}while(ans == 'Y');
	
	//terminate program
	return 0;
}

//checks if statements are palindromes 
bool Palindrome(NODE* p, NODE* q)
{
	char c1, c2;
	int test=0;
	while(p != NULL || q !=NULL)
	{
		c1 = p->info; c2 = q->info;
		c1 = toupper(c1);
		c2 = toupper(c2);
		if(c1 != c2)return false;
	
		p=p->next; q=q->next;
	}
	//if(test == 0)return true;
	return true;
}
//creates stack
void MakeStack(int x, NODE* &p)
{
	NODE* q;
	q=new(NODE); q->info=x; q->next=NULL;
	q->next=p; p=q;
}
//creates queue
void MakeQueue(int x, NODE* &p)
{
	NODE* q;
	q=new(NODE); q->info=x;q->next=NULL;
	if(p==NULL)
	{q->next=p;p=q;}
	else
	{
		NODE *t=p;
		while(t->next!=NULL)
		{t=t->next;}
		t->next=q;
	}
}
/*------------------------------------------------------------------------
    Enter a phrase: A Toyota
        Is a PALINDROME
	CONTINUE(y/n)? y

    Enter a phrase: That's all
        Not a PALINDROME
	CONTINUE(y/n)? n
------------------------------------------------------------------------*/


