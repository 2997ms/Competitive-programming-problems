#include <iostream>
#include <cstring>
using namespace std;

char moshi[1000004];
int calnext[1000004];

void Calnext(int len1)
{
	memset(calnext,0,1000004*sizeof(int));

	calnext[0]=-1;

	int i,j=-1;

	for(i=0;i<len1;)
	{
		if(moshi[i]==moshi[j]||j==-1)
		{
			i++;
			j++;
			calnext[i]=j;
		}
		else
		{
			j=calnext[j];
		}
	}
}


int main()
{
	while(true)
	{
		scanf("%s",moshi);

		if(strcmp(moshi, "."))
		{
			int len1 = strlen(moshi);

			Calnext(len1);

			if(len1%(len1-calnext[len1])==0)
			{
				cout<<len1/(len1-calnext[len1])<<endl;
			}
			else
			{
				cout<<'1'<<endl;
			}

		}
		else
			break;

	}

	return 0;
}