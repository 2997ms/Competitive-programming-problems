#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void result (string test)
{
	int count = test.size();
	int start=0,end=count-1,max=0;
	int i,j,loop;
	
	for(i = start; i < end; i++){
		for(j = end; j > start; j--){
			for(loop = (j-i)/2 ; loop >= 0;loop--){
					if(test[i+ loop] == test[j- loop])
					   continue;
					else
					   break;
			}
			if(loop == -1){
				if(j-i+1 > max){
				    max=j-i+1;	
				}
					
			}
					
		}
		
	}
	printf("%d\n",max);
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
