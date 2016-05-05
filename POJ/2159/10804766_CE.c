#include<iostream>
#include<string.h>
using namespace std;
int main(){
int a[27],b[27],d[101],e[101];
char c;
int i;
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
memset(d,0,sizeof(d));
memset(e,0,sizeof(e));
while(scanf("%c",&c)&&c!='\n')
a[c-'A']++;
for(i=0;i<27;i++)
d[a[i]]++;
while(scanf("%c",&c)&&c!='\n')
b[c-'A']++;
for(i=0;i<27;i++)
e[b[i]]++;
for(i=0;i<101;i++)
if(d[i]!=e[i])
break;
if(i==101)
cout<<"YES";
else
cout<<"NO";
// system("pause");
}