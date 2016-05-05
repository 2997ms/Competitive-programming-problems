#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

queue <int> pot1;
queue <int> pot2;

int buzhou[105][105];
string path[105][105];// drop[1] drop[2] fill[1] fill[2] pour[2,1] pour[1,2]

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int A,B,C,flag,v1,v2,i;
	cin>>A>>B>>C;

	memset(buzhou,0,sizeof(buzhou));

	pot1.push(0);
	pot2.push(0);

	flag=0;	
	v1=0;
	v2=0;
	buzhou[v1][v2]=1;

	while(pot1.size()&&pot2.size())
	{
		v1=pot1.front();
		v2=pot2.front();

		pot1.pop();
		pot2.pop();

		if(v1==C||v2==C)
		{
			flag=1;
			cout<<buzhou[v1][v2]-1<<endl;
			for(i=0;i<path[v1][v2].size();i++)
			{
				if(path[v1][v2][i]=='1')
					cout<<"DROP(2)"<<endl;
				else if(path[v1][v2][i]=='2')
					cout<<"DROP(1)"<<endl;
				else if(path[v1][v2][i]=='3')
					cout<<"FILL(1)"<<endl;
				else if(path[v1][v2][i]=='4')
					cout<<"FILL(2)"<<endl;
				else if(path[v1][v2][i]=='5')
					cout<<"POUR(2,1)"<<endl;
				else if(path[v1][v2][i]=='6')
					cout<<"POUR(1,2)"<<endl;
			}
			break;
		}
		if(!buzhou[0][v2])//drop1
		{
			buzhou[0][v2]=buzhou[v1][v2]+1;
			path[0][v2] = path[v1][v2]+"2";
			pot1.push(0);
			pot2.push(v2);
		}
		if(!buzhou[v1][0])//drop2
		{
			buzhou[v1][0]=buzhou[v1][v2]+1;
			path[v1][0] = path[v1][v2]+"1";
			pot1.push(v1);
			pot2.push(0);
		}
		if(!buzhou[v1][B])//fill2
		{
			buzhou[v1][B]=buzhou[v1][v2]+1;
			path[v1][B] = path[v1][v2]+"4";
			pot1.push(v1);
			pot2.push(B);
		}
		if(!buzhou[A][v2])//fill1
		{
			buzhou[A][v2]=buzhou[v1][v2]+1;
			path[A][v2] = path[v1][v2]+"3";
			pot1.push(A);
			pot2.push(v2);
		}

		if(v1+v2<A)//b to a
		{
			if(!buzhou[v1+v2][0])
			{
				buzhou[v1+v2][0]=buzhou[v1][v2]+1;
				path[v1+v2][0]= path[v1][v2]+"5";
				pot1.push(v1+v2);
				pot2.push(0);
			}
		}
		else
		{
			if(!buzhou[A][v1+v2-A])
			{
				buzhou[A][v1+v2-A]=buzhou[v1][v2]+1;
				path[A][v1+v2-A]= path[v1][v2]+"5";
				pot1.push(A);
				pot2.push(v1+v2-A);
			}
		}

		if(v1+v2<B)
		{
			if(!buzhou[0][v1+v2])
			{
				buzhou[0][v1+v2]=buzhou[v1][v2]+1;
				path[0][v1+v2]= path[v1][v2]+"6";
				pot1.push(0);
				pot2.push(v1+v2);
			}
		}
		else
		{
			if(!buzhou[v1+v2-B][B])
			{
				buzhou[v1+v2-B][B]=buzhou[v1][v2]+1;
				path[v1+v2-B][B]= path[v1][v2]+"6";
				pot1.push(v1+v2-B);
				pot2.push(B);
			}
		}
	}
	if(!flag)
		cout<<"impossible"<<endl;
	return 0;
}
