#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

char k_c[70],q_c[70],r_c[70],b_c[70],n_c[70],p_c[70],K_c[70],Q_c[70],R_c[70],B_c[70],N_c[70],P_c[70];

int  k_y[70],q_y[70],r_y[70],b_y[70],n_y[70],p_y[70],K_y[70],Q_y[70],R_y[70],B_y[70],N_y[70],P_y[70];

string temp,test[20];
int i,j,flag;
int k_num,q_num,r_num,b_num,n_num,p_num,K_num,Q_num,R_num,B_num,N_num,P_num;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	k_num=1;q_num=1;r_num=1;b_num=1;n_num=1;p_num=1;K_num=1;Q_num=1;R_num=1;B_num=1;N_num=1;P_num=1;

	cin>>temp;
	for(i=1;i<=8;i++)
	{
		cin>>test[i];
		cin>>temp;

		for(j=2;j<=30;j=j+4)
		{
			if(test[i][j]=='r')
			{
				r_c[r_num]='a'+(j/4);
				r_y[r_num]=9-i;
				r_num++;
			}
			else if(test[i][j]=='b')
			{
				b_c[b_num]='a'+(j/4);
				b_y[b_num]=9-i;
				b_num++;
			}
			else if(test[i][j]=='k')
			{
				k_c[k_num]='a'+(j/4);
				k_y[k_num]=9-i;
				k_num++;
			}
			else if(test[i][j]=='q')
			{
				q_c[q_num]='a'+(j/4);
				q_y[q_num]=9-i;
				q_num++;
			}
			else if(test[i][j]=='n')
			{
				n_c[n_num]='a'+(j/4);
				n_y[n_num]=9-i;
				n_num++;
			}
			else if(test[i][j]=='p')
			{
				p_c[p_num]='a'+(j/4);
				p_y[p_num]=9-i;
				p_num++;
			}
		}
	}
	for(i=8;i>=1;i--)
	{
		for(j=2;j<=30;j=j+4)
		{
			if(test[i][j]=='R')
			{
				R_c[R_num]='a'+(j/4);
				R_y[R_num]=9-i;
				R_num++;
			}
			else if(test[i][j]=='B')
			{
				B_c[B_num]='a'+(j/4);
				B_y[B_num]=9-i;
				B_num++;
			}
			else if(test[i][j]=='K')
			{
				K_c[K_num]='a'+(j/4);
				K_y[K_num]=9-i;
				K_num++;
			}
			else if(test[i][j]=='Q')
			{
				Q_c[Q_num]='a'+(j/4);
				Q_y[Q_num]=9-i;
				Q_num++;
			}
			else if(test[i][j]=='N')
			{
				N_c[N_num]='a'+(j/4);
				N_y[N_num]=9-i;
				N_num++;
			}
			else if(test[i][j]=='P')
			{
				P_c[P_num]='a'+(j/4);
				P_y[P_num]=9-i;
				P_num++;
			}
		}
	}
	
	flag=1;
	cout<<"White: ";
	for(i=1;i<K_num;i++)
	{
		if(flag)
		{
			flag=0;
			cout<<"K"<<K_c[i]<<K_y[i];
		}
		else
		{
			cout<<",K"<<K_c[i]<<K_y[i];
		}
	}
	for(i=1;i<Q_num;i++)
	{
		if(flag)
		{
			flag=0;
			cout<<"Q"<<Q_c[i]<<Q_y[i];
		}
		else
		{
			cout<<",Q"<<Q_c[i]<<Q_y[i];
		}
	}
	for(i=1;i<R_num;i++)
	{
		if(flag)
		{
			flag=0;
			cout<<"R"<<R_c[i]<<R_y[i];
		}
		else
		{
			cout<<",R"<<R_c[i]<<R_y[i];
		}
	}
	for(i=1;i<B_num;i++)
	{
		if(flag)
		{
			flag=0;
			cout<<"B"<<B_c[i]<<B_y[i];
		}
		else
		{
			cout<<",B"<<B_c[i]<<B_y[i];
		}
	}
	for(i=1;i<N_num;i++)
	{
		if(flag)
		{
			flag=0;
			cout<<"N"<<N_c[i]<<N_y[i];
		}
		else
		{
			cout<<",N"<<N_c[i]<<N_y[i];
		}
	}
	for(i=1;i<P_num;i++)
	{
		if(flag)
		{
			flag=0;
			cout<<P_c[i]<<P_y[i];
		}
		else
		{
			cout<<","<<P_c[i]<<P_y[i];
		}
	}
	cout<<endl;
	
	flag=1;
	cout<<"Black: ";
	for(i=1;i<k_num;i++)
	{
		if(flag)
		{
			flag=0;
			cout<<"K"<<k_c[i]<<k_y[i];
		}
		else
		{
			cout<<",K"<<k_c[i]<<k_y[i];
		}
	}
	for(i=1;i<q_num;i++)
	{
		if(flag)
		{
			flag=0;
			cout<<"Q"<<q_c[i]<<q_y[i];
		}
		else
		{
			cout<<",Q"<<q_c[i]<<q_y[i];
		}
	}
	for(i=1;i<r_num;i++)
	{
		if(flag)
		{
			flag=0;
			cout<<"R"<<r_c[i]<<r_y[i];
		}
		else
		{
			cout<<",R"<<r_c[i]<<r_y[i];
		}
	}
	for(i=1;i<b_num;i++)
	{
		if(flag)
		{
			flag=0;
			cout<<"B"<<b_c[i]<<b_y[i];
		}
		else
		{
			cout<<",B"<<b_c[i]<<b_y[i];
		}
	}
	for(i=1;i<n_num;i++)
	{
		if(flag)
		{
			flag=0;
			cout<<"N"<<n_c[i]<<n_y[i];
		}
		else
		{
			cout<<",N"<<n_c[i]<<n_y[i];
		}
	}
	for(i=1;i<p_num;i++)
	{
		if(flag)
		{
			flag=0;
			cout<<p_c[i]<<p_y[i];
		}
		else
		{
			cout<<","<<p_c[i]<<p_y[i];
		}
	}
	cout<<endl;

	return 0;
}
