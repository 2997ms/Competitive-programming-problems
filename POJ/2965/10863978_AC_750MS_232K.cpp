#include <iostream>
using namespace std;
int a[5][5],b[5][5];
void intput()
{
	char c;int j,k;
	for(j=1;j<=4;j++)
	{
		for(k=1;k<=4;k++)
		{
			cin>>c;
			if(c=='-')
			{
			  a[j][k]=1;
			}
			else 
			{
				a[j][k]=0;
			}
		}
		getchar();
	}
}
int check()
{
	int sum,j,k;
	for(j=1,sum=0;j<=4;j++)
	{
		for(k=1;k<=4;k++)
		{
			sum+=b[j][k];
		}
	}
	if(sum==16)
     
		return 1;
	else
		return 0;
}
void turn(int m)
{
	int j,k,h;
	j=(m-1)/4+1;
	k=(m-1)%4+1;
	for(h=1;h<=4;h++)
       b[j][h]=!b[j][h];
	for(h=1;h<=4;h++)
		b[h][k]=!b[h][k];
	b[j][k]=!b[j][k];
}

int main()
{
	int t[20],m,n,s,step;
	intput();
	for(t[1]=0;t[1]<=1;t[1]++)
		for(t[2]=0;t[2]<=1;t[2]++)
			for(t[3]=0;t[3]<=1;t[3]++)
				for(t[4]=0;t[4]<=1;t[4]++)
					for(t[5]=0;t[5]<=1;t[5]++)
						for(t[6]=0;t[6]<=1;t[6]++)
							for(t[7]=0;t[7]<=1;t[7]++)
								for(t[8]=0;t[8]<=1;t[8]++)
									for(t[9]=0;t[9]<=1;t[9]++)
										for(t[10]=0;t[10]<=1;t[10]++)
											for(t[11]=0;t[11]<=1;t[11]++)
												for(t[12]=0;t[12]<=1;t[12]++)
													for(t[13]=0;t[13]<=1;t[13]++)
														for(t[14]=0;t[14]<=1;t[14]++)
															for(t[15]=0;t[15]<=1;t[15]++)
																for(t[16]=0;t[16]<=1;t[16]++)
																{
																	for(m=1;m<=4;m++)
																		for(n=1;n<=4;n++)
																		  b[m][n]=a[m][n];
																	for(m=1;m<=16;m++)
																		if(t[m])
																			turn(m);
																		if(check())
																		{
																			 step=0;
																			 for (n=1;n<=16;n++)
																				 step=step+t[n];
																			 cout<<step<<endl;
																			for(s=1;s<=16;s++)
																				 {
																					 if(t[s])
																						 cout<<(s-1)/4+1<<' '<<(s-1)%4+1<<endl;
																				 }
                                                                           return 0;
																		}
																}
}
																			


																			


