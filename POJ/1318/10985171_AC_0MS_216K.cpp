#include <iostream>   
#include <algorithm>   
#include <cmath>   
#include <cstdio>   
#include <cstdlib>   
#include <cstring>   
#include <string>   
using namespace std;  
int main()  
{  
    string a[105],b[105],c;  
    int n,i;  
    for(i=0;; i++)       //输入字典   
    {  
        cin>>a[i];  
        if(a[i][0]=='X')  
            break;  
    }  
    sort(a,a+i);    //单词之间字典排序   
    n=i;  
    for(i=0;i<n;i++)  
    {  
        b[i]=a[i];     //a串排序 b串起输出作用   
        sort(a[i].begin(),a[i].end());//单词之内字典排序   
    }  
    while(cin>>c)//测试样例   
    {  
        if(c[0]=='X')  
            break;  
         int index=0;  
        sort(c.begin(),c.end());//样例排序   
        for(i=0;i<n;i++)  
        {  
            if(c==a[i])  
            {  
                index=1;  
                cout<<b[i]<<endl;  
            }  
        }  
        if(index==0)//没有在字典中找到对应单词   
        {  
            cout<<"NOT A VALID WORD"<<endl;  
        }  
        cout<<"******"<<endl;  
    }  
    return 0;  
}  
