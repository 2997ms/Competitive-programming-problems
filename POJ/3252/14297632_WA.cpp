#include <iostream>
using namespace std;

int c[33][33];
int bin[33];
int a,b;

void init()
{
	int i,j;
	memset(c,0,sizeof(c));

	for(i=0;i<=32;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j==0||j==i)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
}

void dec_to_bin(int x)
{
	memset(bin,0,sizeof(bin));

	while(x!=0)
	{
		bin[++bin[0]]=x&1;
		x=x>>1;
	}
}

int result(int n)
{
	/*dec_to_bin(x);
	
	int i,j;
	int sum=0;

	for(i=1;i<bin[0]-1;i++)
	{
		for(j=i/2+1;j<=i;j++)
		{
			sum +=c[i][j];
		}
	}
	sum++;
	int zero=0;

	for(i=bin[0]-1;i>=1;i--)
	{
		if(bin[i])
		{
			for(j=(bin[0]+1)/2-(zero+1);j<=i-1;j++)
				sum += c[i-1][j];
		}
		else
			zero++;
	}
	return sum;*/
	 int i,j;
    int sum=0;  //姣斿崄杩涘埗鏁皀灏忕殑鎵�湁RN鏁�    dec_to_bin(n);


    for(i=1;i<bin[0]-1;i++)
        for(j=i/2+1;j<=i;j++)
            sum+=c[i][j];



    int zero=0;  //浠庨珮浣嶅悜浣庝綅鎼滅储杩囩▼涓嚭鐜�鐨勪綅鐨勪釜鏁�    for(i=bin[0]-1;i>=1;i--)
        if(bin[i])   //褰撳墠浣嶄负1
            for(j=(bin[0]+1)/2-(zero+1);j<=i-1;j++)
                sum+=c[i-1][j];
        else
            zero++;

    return sum;
}

int main()
{
	init();
	cin>>a>>b;
	cout<<result(b+1)-result(a)<<endl;

	return 0;
}