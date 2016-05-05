#include<stdio.h>
    double a[1003],b[1003];
int qsort(int s,int t)
{
    int i,j;
    double mid,tmp;
    i=s;j=t;mid=a[(i+j)/2];
    while (i<=j)
    {
        while (a[i]<mid)    i++;
        while (a[j]>mid)    j--;
        if (i<=j)
        {
            tmp=a[i];a[i]=a[j];a[j]=tmp;
            tmp=b[i];b[i]=b[j];b[j]=tmp;
            i++;
            j--;
        }
    }
    if (s<j)    qsort(s,j);
    if (i<t)    qsort(i,t); 
}
int main()
{
    int n,i,x,y,d,ans,flag,t;
    double right,xx;
    scanf("%d%d",&n,&d);

    t=0;
    while (n!=0||d!=0)
    {
        flag=0;t++;
        for (i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            if (y>d)
                flag=1;
            xx=sqrt(d*d-y*y);
            a[i]=x-xx;b[i]=x+xx; 
        }

        if (flag)
        {
            printf("Case %d: -1\n",t);
            scanf("%d%d",&n,&d);
            continue;
        }

        qsort(1,n);
        ans=0;
    
        right=b[1];i=2;
        while (i<=n)
        {
            if (a[i]>right)
            {
                ans++;right=b[i];
            }
            if (b[i]<right)
                    right=b[i];
            i++;
        }
        ans++;
        printf("Case %d: %d\n",t,ans);
        scanf("%d%d",&n,&d);
    }
}
