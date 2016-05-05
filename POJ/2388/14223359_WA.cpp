#include <iostream>
using namespace std;
#define len 100002

int s[len];

int AdjustArray(int s[],int l,int r)//返回调整之后基准数的位置
{
	int i = l,j = r;
	int x = s[l];

	while(i < j)
	{
		while(i < j && s[j] >= x)
			j--;
		if(i < j)
		{
			s[i]=s[j];
			i++;
		}

		while(i < j && s[i] < x)
			i++;
		if(i < j)
		{
			s[j] = s[i];
			j--;
		}
	}
	s[i]=x;

	return i;
}

int quick_sort(int s[], int l,int r,int mid)//利用分治法来找中位数
{
	if(l < r)
	{
		int i = AdjustArray(s,l,r);
		if(i == mid)
			return s[i];
		quick_sort(s,i+1,r,mid);
		quick_sort(s,l,i-1,mid);
	}
}

int main()
{

	int count,i;


	cin>>count;

	for(i=0;i<count;i++)
	{
		cin>>s[i];
	}

	cout<<quick_sort(s,0,count-1,count/2)<<endl;

	return 0;
}