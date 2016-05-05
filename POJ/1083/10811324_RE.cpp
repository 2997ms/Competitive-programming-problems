#include <iostream>
using namespace std;
int max(int *a)
{
    int max=0;
    for(int i=0;i<201;i++)  
      if(a[i]>max)max=a[i];
    return max; 
}
int main()
{
      int count1,count2=1,count3,count4,count5=0,room1,room2,a[205];
      memset(a,0,sizeof(a));
      cin>>count1;
      for(count2=1;count2<=count1;count2++)
      {
		 memset(a,0,sizeof(a));
         cin>>count4;
          for(count3=1;count3<=count4;count3++)
          {
             cin>>room1>>room2;
			 if(room1>room2)
				 swap(room1,room2);
             for(count5=room1;count5<=room2;count5++)
             {
               a[count5]++;
             }       
          } 
            cout<<max(a)*10<<endl;
       }
      return 0;
 }
        
      