/*
node* create()
{
node* tnew =(node*)malloc(sizeof(node));

for(int i=0;i<26;i++)
{
tnew->child[i]=NULL;
}
tnew->get=0;

return tnew;
}

int main()
{
long m,n;
int len;

cin>>m;

char str[35];

node* root = create();
node* temp = root;

while(m--)
{
cin>>str;
len=strlen(str);
temp = root;
for(int i=0;i<len;i++)
{
if(temp->child[str[i]-'a']==NULL)
{
temp->child[str[i]-'a']=create();
}
temp->child[str[i]-'a']->get++;
temp = temp->child[str[i]-'a'];
}
}

cin>>n;

while(n--)
{
temp=root;
cin>>str;
len=strlen(str);

for(int i=0;i<len;i++)
{
temp = temp->child[str[i]-'a'];
if(temp==NULL)
break;
}
if(temp==NULL)
cout<<0<<endl;
else
cout<<temp->get<<endl;
}

system("pause");
return 0;
}*/
/*node* create()
{
node* tnew = (node*)malloc(sizeof(node));

for(int i=0; i<10; i++)
{
tnew->child[i] = NULL;
}

tnew->get=0;

return tnew;
}

int main()
{
int count,n,len;

cin>>count;

char str[15];

while(count--)
{
cin>>n;

int flag=0;

node* root =create();
node* temp =root;

while(n--)
{	
cin>>str;

len = strlen(str);

for(int i =0 ; i<len; i++)
{
if(i==len-1)
{
if(temp->child[str[i]-'0']!=NULL)
{
flag=1;
break;
}
else
{
temp->child[str[i]-'0']=create();

temp->child[str[i]-'0']->get++;
}
}
else
{
if(temp->child[str[i]-'0']==NULL)
{
temp->child[str[i]-'0']=create();
}
else
{
if(temp->child[str[i]-'0']->get!=0)
{
flag++;
break;
}
}
temp=temp->child[str[i]-'0'];
}
}
}
if(flag)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}

//system("pause");
return 0;
}
*/

#include <iostream>
#include <cstring>
using namespace std;

struct node{
	int get;
	node *child[10];
}Node[100005];

void start()
{
	int i;
	node* temp;
	for(i=0;i<100005;i++)
	{
		temp=&Node[i];
		temp->get=0;
	}
}
int nodenum=1;

int test(char str[])
{
	int len = strlen(str);

	node* root = &Node[0];
	node* temp = root;

	for(int i=0; i<len; i++)
	{
		/*if((i==len-1)&&(temp->child[str[i]-'0']==NULL))
		{
		return 0;
		}
		else
		{
		if(temp->child[str[i]-'0']==NULL)
		{
		temp->child[str[i]-'0']= &Node[i+1];

		temp=temp->child[str[i]-'0'];
		}
		}*/
		if(i==len-1)
		{
			if (temp->child[str[i]-'0']!=NULL)
			{
				return 0;
			}
			else
			{
				temp->child[str[i]-'0']= &Node[nodenum++];

				temp->child[str[i]-'0']->get++;
			}
		}
		else
		{
			if(temp->child[str[i]-'0']==NULL)
			{
				temp->child[str[i]-'0']=&Node[nodenum++];
			}
			else
			{
				if(temp->child[str[i]-'0']->get!=0)
				{
					return 0;
				}
			}
			temp=temp->child[str[i]-'0'];
		}
	}
	return 1;
}

int main()
{
	int m,n;
	int flag=1,flag2=1;
	char str[35];	

	cin>>m;

	while(m--)
	{
		cin>>n;
		start();
		nodenum=1;
		flag=1;flag2=1;
		while(n--)
		{
			cin>>str;
			flag =test(str);

			if(flag==0)
				flag2=0;
		}
		if(flag2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

