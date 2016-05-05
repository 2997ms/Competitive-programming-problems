#include<iostream>
 #include<cstring>
#include<cmath>
 using namespace std;
 
 int dif[3000];
 
int main(){
 	int n;
	while(cin >> n){
 		memset(dif,0,sizeof(dif));
 		int pre,current;
 		cin >> pre;
 		int i;
 		for(i = 1; i < n; i++){
 			cin >> current;
 			int abs_dif = abs(current - pre);
 			dif[abs_dif] = 1;
 			pre = current; 	
 		}
 		
 		for(i = 1; i < n; i++){
 			if(dif[i] == 0)
 				break;
 		}
 
 		if(i == n)
 			cout << "Jolly" << endl;
		else
 			cout << "Not jolly" << endl;
 	}
 }
