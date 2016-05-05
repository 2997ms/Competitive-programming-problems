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
 int s,t,time[200],used[400];   
    cin>>T;
  while(k<T)
 {
   for(int i=0;i<400;i++)used[i]=0;
   cin>>N; 
   for(int i=0;i<N;i++)
   {
           cin>>s>>t;
            if(s>t) 
            {s=s+t;
			t=s-t;
			s=s-t;}
            if(s%2==0) 
                  s--;
            if(t%2!=0) 
                   t++; 
            for(int j=s;j<=t;j++) 
                     used[j]++;    
   } 
  time[k]=max(used)*10;k++;
 }
   for(int i=0;i<T;i++)
   {
     cout<<time[i]<<endl;
   } 
system("PAUSE");
return 0;                 
} 
