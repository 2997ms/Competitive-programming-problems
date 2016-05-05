#include<stdio.h>   
#include<string.h>   
#include<algorithm>   
using namespace std;  
bool cmp(int a,int b)  
{  
    return a>b;  
}  
int poww(int x,int y)  
{  
    int xx=x;  
    for(int i=1;i<y;i++)  
        xx=xx*x;  
    return xx;  
}  
char str[500];  
int num,strnum[500];  
int main()  
{  
    while(scanf("%d%s",&num,str)&&num)  
    {  
        int len=strlen(str);  
        int v,w,x,y,z,flag=0,vv,ww,xx,yy,zz;  
        for(int i=0;i<len;i++)  
            strnum[i]=str[i]-'A'+1;  
        sort(strnum,strnum+len,cmp);  
        for(int i1=0;i1<len;i1++){  
            for(int i2=0;i2<len;i2++){  
                if(i2!=i1){  
                    for(int i3=0;i3<len;i3++){  
                        if(i3!=i2&&i3!=i1){  
                            for(int i4=0;i4<len;i4++){  
                                if(i4!=i1&&i4!=i2&&i4!=i3){  
                                    for(int i5=0;i5<len;i5++){  
                                        if(i5!=i1&&i5!=i2&&i5!=i3&&i5!=i4)  
                                        {  
                                            vv=strnum[i1],ww=strnum[i2],xx=strnum[i3],yy=strnum[i4],zz=strnum[i5];  
                                            v=strnum[i1];  
                                            w=poww(strnum[i2],2);  
                                            x=poww(strnum[i3],3);  
                                            y=poww(strnum[i4],4);  
                                            z=poww(strnum[i5],5);  
                                            if(v-w+x-y+z==num)  
                                            {  
                                                flag=1;  
                                                break;  
                                            }  
                                        }  
                                        if(flag)break;  
                                    }  
                                }  
                                if(flag)break;  
                            }  
                        }  
                        if(flag)break;  
                    }  
                }  
                if(flag)break;  
            }  
        }  
        if(flag)  
            printf("%c%c%c%c%c\n",vv-1+'A',ww-1+'A',xx-1+'A',yy-1+'A',zz-1+'A');  
        else  
            printf("no solution\n");  
    }  
    return 0;  
} 