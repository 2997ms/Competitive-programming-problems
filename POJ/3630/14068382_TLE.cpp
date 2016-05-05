#include <iostream>
#include <cstring>
using namespace std;

struct node{
	int get;
	node *child[10];
};

node* create()
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
