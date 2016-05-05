#include <iostream>
using namespace std;

int main()
{
    char ch;
    long long sum,mum;
    scanf("%c",&ch);
    for(;ch!='#';)
    {
      for(mum=1,sum=0;ch!='\n';scanf("%c",&ch),mum++)
      {
           sum=(ch-64)*mum+sum;
      }
	  cout<<sum<<endl;
	  scanf("%c",&ch);
    }
    system("pause");
    return 0;
}
      