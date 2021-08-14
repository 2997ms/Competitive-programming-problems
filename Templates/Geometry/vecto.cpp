#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define REP(_,a,b) for(int _ = (a); _ <= (b); _++)
using namespace std;
const double eps = 1e-10;
const int maxn = 160;
const double PI = acos(-1.0);
double ang,rad;
int n,n1,n2;
struct Point{
	double x,y;
	Point(double x=0.0,double y = 0.0):x(x),y(y){}
}P[maxn];
typedef Point Vector;

struct Line {
	Point P;
	Vector v;
	double ang;
	Line(){}
	Line(Point P,Vector v):P(P),v(v){
		ang = atan2(v.y,v.x);
	}
	bool operator <(const Line&L) const{
		return ang < L.ang;
	}
};
Vector operator + (Vector A,Vector B) {
	return Vector(A.x+B.x,A.y+B.y);
}
Vector operator - (Vector A,Vector B){
	return Vector(A.x-B.x,A.y-B.y);
}
Vector operator * (Vector A,double p){
	return Vector(A.x*p,A.y*p);
}
Vector operator / (Vector A,double p){
	return Vector(A.x/p,A.y/p);
}
bool operator < (const Point &a,const Point &b){
	return a.x < b.x || (a.x==a.y && a.y < b.y);
}
int dcmp(double x){
	if(fabs(x) < eps) return 0;
	else return x < 0? -1:1;
}
bool operator == (const Point &a,const Point &b){
	return dcmp(a.x-b.x)==0&& dcmp(a.y-b.y)==0;
}
double Dot(Vector A,Vector B) {return A.x*B.x+A.y*B.y;}
double Length(Vector A) {return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B) {return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vector A,Vector B) {return A.x*B.y-A.y*B.x;}
Vector Rotate(Vector A,double rad) {return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad)); }
Vector Normal(Vector A) {
	double L = Length(A);
	return Vector(A.x/L,A.y/L);
}
Point GetIntersection(Line a,Line b){
	Vector u = a.P-b.P;
	double t = Cross(b.v,u) / Cross(a.v,b.v);
	return a.P+a.v*t;
}
int main(){
	while(~scanf("%d%d%d",&n,&n1,&n2)){
		ang = (n2-n1)*PI/n;
		rad = 2*PI/n;
		scanf("%lf%lf%lf%lf",&P[n1].x,&P[n1].y,&P[n2].x,&P[n2].y);
		Line a = Line((P[n1]+P[n2])/2,Normal(P[n2]-P[n1]));
		Line b = Line(P[n1],Rotate(Normal(P[n2]-P[n1]),ang));
		Point o = GetIntersection(a,b);
		Vector t = P[n1]-o;
		int d = n1+1,cnt = 1;
		while(d != n1){
			P[d] = o+Rotate(t,-cnt*rad);
			d = d%n + 1;
			cnt++;
		}
		REP(i,1,n) {
			printf("%.6lf %.6lf\n",P[i].x,P[i].y);
		}
	}
	return 0;
}
