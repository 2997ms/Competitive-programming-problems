#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

char str[1000005];
int p[1000005<<1];
char a[1000005<<1];
int min(int a,int b){
	return a>b?b:a;
}
void result(){
	int maxLine=0,ID=1,maxResult=0;
	int n=0,i,len;
	
	len=strlen(str)<<1;
	
	for(i=0;i<(1000005<<1);i++){
		p[i]=0;
		a[i]='#';
	}
	for(i=0;i<strlen(str);i++){
		a[((i+1)<<1)-1]=str[i];
		
	}

	for(i=1;i<=len;i++){
		
		if(maxLine >i){
			p[i]=min(p[2*ID-i],maxLine-i);
		}
		else{
			p[i]=1;
		}
		
		while(a[i+p[i]]==a[i-p[i]]){
			p[i]++;
			if(i-p[i]>=0)continue;
			else break;
		}
		if(p[i]+i>maxLine){
		   maxLine=p[i]+i;
		   ID=i;
		}
		if(p[i]>maxResult){
		   maxResult=p[i];	
		}
	}


	cout<<maxResult-1<<endl;
}
int main()
{
	int count=1;
	while(true)
	{
        cin>>str;
        if(str == "END")
         return 1;
        else
        cout<<"Case "<<count++<<":";
		result();
	}
	return 0;
}