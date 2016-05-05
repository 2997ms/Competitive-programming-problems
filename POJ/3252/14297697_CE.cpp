#include <iostream>
using namespace std;

int c[33][33]={0};
int bin[35];
int a,b;

void init()
{
	memset(c,0,sizeof(c));
	for(int i=0;i<=32;i++)
		for(int j=0;j<=i;j++)
			if(!j || i==j)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
}

void dec_to_bin(int n)
{
	bin[0]=0;   //b[0]鏄簩杩涘埗鏁扮殑闀垮害
	while(n)
	{
		bin[++bin[0]]=n%2;
		n/=2;
	}
	return;
}

int result(int n)
{
int i,j;
    int sum=0;  //姣斿崄杩涘埗鏁皀灏忕殑鎵�湁RN鏁�    dec_to_bin(n);

    /*璁＄畻闀垮害灏忎簬bin[0]鐨勬墍鏈変簩杩涘埗鏁颁腑RN鐨勪釜鏁�/

    for(i=1;i<bin[0]-1;i++)
        for(j=i/2+1;j<=i;j++)
            sum+=c[i][j];

    /*璁＄畻闀垮害绛変簬bin[0]鐨勬墍鏈変簩杩涘埗鏁颁腑RN鐨勪釜鏁�/

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