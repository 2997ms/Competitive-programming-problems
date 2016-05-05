#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

char k_c,q_c,b_c,K_c,Q_c,N_c;
char r_c[5],p_c[10],n_c[5],R_c[5],B_c[5],P_c[10];

int k_y,q_y,b_y,K_y,Q_y,N_y;
int r_y[5],n_y[5],p_y[10],R_y[5],B_y[5],P_y[10];

string temp,test[20];
int i,j;
int r_num,b_num,p_num,n_num,R_num,B_num,P_num;

int main()
{
	r_num=1;b_num=1;p_num=1;n_num=1;R_num=1;B_num=1;P_num=1;

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
				b_c='a'+(j/4);
				b_y=9-i;
			}
			else if(test[i][j]=='k')
			{
				k_c='a'+(j/4);
				k_y=9-i;
			}
			else if(test[i][j]=='q')
			{
				q_c='a'+(j/4);
				q_y=9-i;
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
				K_c='a'+(j/4);
				K_y=9-i;
			}
			else if(test[i][j]=='Q')
			{
				Q_c='a'+(j/4);
				Q_y=9-i;
			}
			else if(test[i][j]=='N')
			{
				N_c='a'+(j/4);
				N_y=9-i;
			}
			else if(test[i][j]=='P')
			{
				P_c[P_num]='a'+(j/4);
				P_y[P_num]=9-i;
				P_num++;
			}
		}
	}

	cout<<"White: K"<<K_c<<K_y<<",Q"<<Q_c<<Q_y<<",R"<<R_c[1]<<R_y[1]<<",R"<<R_c[2]<<R_y[2]
	<<",B"<<B_c[1]<<B_y[1]<<",B"<<B_c[2]<<B_y[2]<<",N"<<N_c<<N_y
		<<","<<P_c[1]<<P_y[1]
	<<","<<P_c[2]<<P_y[2]
	<<","<<P_c[3]<<P_y[3]
	<<","<<P_c[4]<<P_y[4]
	<<","<<P_c[5]<<P_y[5]
	<<","<<P_c[6]<<P_y[6]
	<<","<<P_c[7]<<P_y[7]
	<<","<<P_c[8]<<P_y[8]<<endl;

	cout<<"Black: K"<<k_c<<k_y<<",Q"<<q_c<<q_y<<",R"<<r_c[1]<<r_y[1]<<",R"<<r_c[2]<<r_y[2]
	<<",B"<<b_c<<b_y<<",N"<<n_c[1]<<n_y[1]<<",N"<<n_c[2]<<n_y[2]
	<<","<<p_c[1]<<p_y[1]
	<<","<<p_c[2]<<p_y[2]
	<<","<<p_c[3]<<p_y[3]
	<<","<<p_c[4]<<p_y[4]
	<<","<<p_c[5]<<p_y[5]
	<<","<<p_c[6]<<p_y[6]
	<<","<<p_c[7]<<p_y[7]
	<<","<<p_c[8]<<p_y[8]<<endl;

	return 0;
}
