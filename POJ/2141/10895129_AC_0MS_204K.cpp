#include <iostream>
using namespace std;

int main()
{
	char c[30],f[100];
	int count;
	cin>>c;
	cin>>f[0];
	for(count=1;;count++)
	{
		scanf("%c",&f[count]);
		if(f[count]=='\n')
			break;
	}
	for(count=0;f[count]!='\n';count++)
	{
		if(f[count]==' ')
		{
			cout<<' ';
		}
		else
		{
			if(f[count]>='A'&&f[count]<='Z')
			{
				c[f[count]-'A']=c[f[count]-'A']-32;
				cout<<c[f[count]-'A'];
				c[f[count]-'A']=c[f[count]-'A']+32;
			}
			if(f[count]>='a'&&f[count]<='z')
			{
				cout<<c[f[count]-'a'];
			}
		}
	}
	return 0;
}
