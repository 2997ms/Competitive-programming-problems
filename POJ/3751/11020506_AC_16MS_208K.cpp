#include <iostream>
using namespace std;

int main()
{
	int count,y,mon,d,h,min,s;
	cin>>count;
	while(count--)
	{
		scanf("%d/%d/%d-%d:%d:%d",&y,&mon,&d,&h,&min,&s);
	if(h>=0&&h<12)
        {
            if(h>=0&&h<1) h=h+12;
            printf("%02d/%02d/%04d-%02d:%02d:%02dam\n",mon,d,y,h,min,s);
        }
        else
        {
            if(h>=13) h=h-12;
            printf("%02d/%02d/%04d-%02d:%02d:%02dpm\n",mon,d,y,h,min,s);
        }

	}
	return 0;
}
