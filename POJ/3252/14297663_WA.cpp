//Memory Time 
//224K   16MS  

#include<iostream>
using namespace std;

int c[33][33]={0};
int bin[35];  //鍗佽繘鍒秐鐨勪簩杩涘埗鏁�


void play_table(void)
{
    for(int i=0;i<=32;i++)
        for(int j=0;j<=i;j++)
            if(!j || i==j)
                c[i][j]=1;
            else
                c[i][j]=c[i-1][j-1]+c[i-1][j];
//    c[0][0]=0;
    return;
}

/*鍗佽繘鍒秐杞崲浜岃繘鍒讹紝閫嗗簭瀛樻斁鍒癰in[]*/

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



int round(int n)
{
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

int main(void)
{
    play_table();

    int a,b;
    cin>>a>>b;


    cout<<round(b+1)-round(a)<<endl;

    return 0;
}