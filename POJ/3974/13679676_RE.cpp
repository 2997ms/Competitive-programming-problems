#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void result (string test)
{
	bool testarr[1000][1000] = {false};
	int count = test.size(),max = 0;
	
	for(int i=0;i<count;i++){
		
		testarr[i][i]=true;
		
		if(i+1<count&&test[i]==test[i+1]){
			
			max = 2;
			testarr[i][i+1] = true;
			
		}
	}
	for(int len=3;len<=count;len++)
	    
		for(int i=0;i<=count-len;i++){
			
			int j=i+len-1;
			if(testarr[i+1][j-1]&&test[i]==test[j]){
				
				max=len;
				testarr[i][j]=true;
			}
			
		}
	cout<<max<<endl;	
}

int main()
{
	int count=1;
	while(true)
	{
		string test;
        cin>>test;
        if(test == "END")
         return 1;
        else
        cout<<"Case "<<count++<<":";
		result(test);

	}
	return 0;
}
