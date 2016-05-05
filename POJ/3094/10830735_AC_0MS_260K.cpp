#include <iostream>
using namespace std;

int main()
{
    char ch;
    int sum,mum;
	scanf("%c",&ch);
    for(;ch!='#';)
    {
      for(mum=1,sum=0;ch!='\n';mum++)
      {   
		  if(ch==' ')
		  {
			  sum=0*mum+sum;
		  }
        else
        { 
			sum=(ch-64)*mum+sum;
		}
           scanf("%c",&ch);
      }
	  cout<<sum<<endl;
      scanf("%c",&ch);
    }
    system("pause");
    return 0;
}
      
       
