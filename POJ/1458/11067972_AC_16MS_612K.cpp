#include <iostream>
#include <string>
using namespace std;

int main()
{
	char a[1000],b[1000];
	int len1,len2,count1,count2,map[310][310];
	while(scanf("%s%s",&a,&b)!=EOF)
	{
		len1=strlen(a);
		len2=strlen(b);
		memset(map,0,sizeof(map));
		for(count1=1;count1<=len1;count1++)
		{
			for(count2=1;count2<=len2;count2++)
			{
				if(a[count1-1]==b[count2-1])
				{
					map[count1][count2]=map[count1-1][count2-1]+1;
				}
				else
					map[count1][count2]=map[count1-1][count2]>map[count1][count2-1]?map[count1-1][count2]:map[count1][count2-1];
			}
		}
		cout<<map[count1-1][count2-1]<<endl;
	}
	return 0;
}






