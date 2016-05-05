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
 int T,N,k=0,s[200],t[200],time[200],used[400];   
    cin>>T;
  while(k<T)
 {
   for(int i=1;i<400;i++)used[i]=0;
   time[k]=0;
   cin>>N; 
   for(int i=0;i<N;i++)
   {
           cin>>s[i]>>t[i];
            if(s[i]>t[i]) 
            swap(s[i],t[i]);
            if(s[i]%2==0) 
                  s[i]--;
            if(t[i]%2!=0) 
                   t[i]++; 
            for(int j=s[i];j<=t[i];j++) 
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
