#include<stdio.h>
#include<math.h>
int main()
{
    double h,d,e,t;
    char c,f;
    while(scanf("%c",&c),c!='E'){
        scanf("%lf %c %lf",&t,&f,&d);
        getchar();
        if(c=='T'&&f=='D'||c=='D'&&f=='T'){
            if(c=='D') h=d,d=t,t=h;
            e=6.11*exp(5417.7530*((1.0/273.16)-(1.0/(d+273.16))));
            h=0.5555*(e-10.0);
            h=t+h;
        }
        if(c=='T'&&f=='H'||c=='H'&&f=='T'){
            h=d;
            if(c=='H') d=h,h=t,t=d;
            h-=t;
            e=h/0.5555+10;
            e/=6.11;
            d=log(e)/5417.7530;
            d=(1.0/273.16)-d;
            d=1.0/d-273.16;
            h += t;
        }
        if(c=='H'&&f=='D'||c=='D'&&f=='H'){
            h=t;
            if(c=='D') t=h,h=d,d=t;
            e=6.11*exp(5417.7530*((1.0/273.16)-(1.0/(d+273.16))));
            t=h-0.5555*(e-10.0);
        }
        printf("T %.1lf D %.1lf H %.1lf\n",t,d,h);
    }
    return 1;
}