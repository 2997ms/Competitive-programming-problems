#include <iostream>
using namespace std;

int main()
{
        int treesum,gap,pre,cur;
		cin>>treesum>>gap;
		for(;treesum||gap;)
		{
			for(;cin>>pre>>cur;)
			{
				if(cur<=pre)
					break;
				treesum=treesum-(cur-pre+1);
			}
			cout<<treesum+1<<endl;
			treesum=pre;
			gap=cur;
		}
		return 0;
}
