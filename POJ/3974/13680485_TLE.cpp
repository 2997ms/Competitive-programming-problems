#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void result (string test)
{
	int start,end,i=0;
	int count = test.size(),max = 0;

    
    for(i = 0;i < count;i++)
    {  
       start = i-1;
       end = i+1;
       
       while(start >= 0 && end < count &&test[start] == test[end]){
    	 if(end-start+1 > max){
	    	max = end-start+1;
	     }
	    start--;
	    end++;   	
       }
    }

    for(i = 0;i < count;i++){
    	
		start = i;
        end = i+1;
    	while(start >= 0 && end < count &&test[start] == test[end]){
	    	if(end-start+1 > max){
	    	max = end-start+1;
	     }
	    start--;
	    end++; 
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
