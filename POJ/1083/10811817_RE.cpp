#include<iostream> 
using namespace std; 
int max(int *a)
{
   int max=0;
    for(int i=0;i<400;i++)  
      if(a[i]>max)max=a[i];
    return max; 
}
int main() 
{ 
 int T,N,k=0;
 int s,t,s1[200],t1[200],time[200],used[400],temp,i;   
    cin>>T;
  while(k<T)
 {
   for(i=0;i<400;i++)used[i]=0;
   cin>>N; 
   for(i=0;i<N;i++)
   {
           cin>>s>>t;
		  		   
            if(s>t) 
                  {
                           temp=s;s=t;t=temp;}
            if(s%2==0) 
                  s--;
            if(t%2!=0) 
                   t++; 
			s1[i]=s;t1[i]=t;
            for(;s1[i]<=t1[i];s1[i]++) 
                     used[s1[i]]++;    
   } 
  time[k]=max(used)*10;k++;
 }
   for(i=0;i<T;i++)
   {
     cout<<time[i]<<endl;
   } 
system("PAUSE");
return 0;                 
} 
