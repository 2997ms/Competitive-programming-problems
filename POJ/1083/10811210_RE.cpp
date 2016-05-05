#include <iostream>
using namespace std;
int main()
{
      int count1,count2=1,count3,count4,count5=0,count6,finalcount,room1,room2,a[230];
      memset(a,0,sizeof(a));
      cin>>count1;
      for(count2=1;count2<=count1;)
      {
		  memset(a,0,sizeof(a));
         cin>>count4;
          for(count3=1;count3<=count4;)
          {
             cin>>room1>>room2;
             for(count5=room1;count5<=room2;count5++)
             {
               a[count5]++;
             }
             count3++;         
          }
		  for(count6=1;count6<201;count6++)
            {
               while(count6<200&&a[count6]==0)
                {count6++;}
			   if(a[count6]>finalcount)
                {finalcount=a[count6];}
            }
		    cout<<finalcount*10<<endl; 
             count2++;
			 finalcount=0;
       }
      return 0;
 }