#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
	char a,b;

	double H,h,T,D,e; 
	
	while(scanf("%c",&a),a!='E')
	{
	  if(a=='D')
	  {
		scanf("%lf",&D);
		  
		scanf("%c",&b);
		  
		scanf("%c",&b);
		  
	    if(b=='H')
		  {
		    scanf("%lf",&H);

		    e=6.11*exp(5417.7530*((1/273.16)-(1/(D+273.16))));
	
		    h=(0.5555)*(e-10.0);
       
		    T=H-h;

		    printf("T %.1f D %.1f H %.1f\n",T,D,H);
		   }
	  }
	  if(a=='T')
	  {
		   scanf("%lf",&T);

		   scanf("%c",&b);

		   scanf("%c",&b);

		   if(b=='D')
		   {
               scanf("%lf",&D);

			   e=6.11*exp(5417.7530*((1/273.16)-(1/(D+273.16))));
	
		       h=0.5555*(e-10.0);
	
			   H=T+h;

	           printf("T %.1f D %.1f H %.1f\n",T,D,H);
		   }
	  }
	  if(a=='T')
	  {
		   scanf("%lf",&T);

		   scanf("%c",&b);

		   scanf("%c",&b);

		   if(b=='H')
		   {
			   scanf("%lf",&H);

			   h=H-T;
			   
			   e=h/0.5555+10.0;
		
			   D=1/(1/273.16-(((log(e/6.11))/5417.7530)))-273.16;
              
			   printf("T %.1f D %.1f H %.1f\n",T,D,H);	  
		   }
	   }
	  if(a=='H')
	  {
		  scanf("%lf",&H);
		    
		  scanf("%c",&b);

		   scanf("%c",&b);
		    
		   if(b=='D')
		   {
			   scanf("%lf",&D);

		    e=6.11*exp(5417.7530*((1/273.16)-(1/(D+273.16))));
	
		    h=(0.5555)*(e-10.0);
       
		    T=H-h;

		    printf("T %.1f D %.1f H %.1f\n",T,D,H);
		   }
	  }
	  if(a=='D')
	  {
		   scanf("%lf",&D);

		   scanf("%c",&b);

		   scanf("%c",&b);

		   if(b=='T')
		   {
               scanf("%lf",&T);

			   e=6.11*exp(5417.7530*((1/273.16)-(1/(D+273.16))));
	
		       h=0.5555*(e-10.0);
	
			   H=T+h;

	           printf("T %.1f D %.1f H %.1f\n",T,D,H);
		   }
	  } if(a=='H')
	  {
		   scanf("%lf",&H);

		   scanf("%c",&b);

		   scanf("%c",&b);

		   if(b=='T')
		   {
			   scanf("%lf",&T);

			   h=H-T;
			   
			   e=h/0.5555+10.0;
		
			   D=1/(1/273.16-(((log(e/6.11))/5417.7530)))-273.16;
              
			   printf("T %.1f D %.1f H %.1f\n",T,D,H);	  
		   }
	   }
	   getchar();	   
}	  	
return 0;
}