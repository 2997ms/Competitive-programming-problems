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
 int T,N,k=0,room1,room2,time[200],used[400];   
    cin>>T;
  while(k<T)
 {
   for(int i=1;i<400;i++)used[i]=0;
   time[k]=0;
   cin>>N; 
   for(int i=0;i<N;i++)
   {
           cin>>room1>>room2;
            if(room1>room2) 
                   {room1=room1+room2;
                   room2=room1-room2;
                   room1=room1-room2;
                   } 
            if(room1%2==0) 
                  room1--;
            if(room2%2!=0) 
                   room2++; 
            for(int j=room1;j<=room2;j++) 
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