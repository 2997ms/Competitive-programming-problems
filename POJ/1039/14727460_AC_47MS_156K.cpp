#include <iostream>  
#include <cstdio>  
#include <cmath>  
using namespace std;  
  
//点定义  
struct Point {  
   double x, y;  
} up[22], down[22];  
  
//精度  
const double eps = 1e-3;  
  
double Max(double a, double b) {  
  return a > b ? a : b;  
}  
  
double Min(double a, double b) {  
  return a > b ? b : a;  
}  
  
/*若返回值大于0，则射线p0p1在射线p0p2顺时针方向;  
   若返回值小于0，则射线p0p1在射线p0p2逆时针方向; 
   若返回值等于0，则p0p1和p0p2共线，方向可能相同，也可能相反*/  
double Multi(Point p1, Point p2, Point p0) {  
   return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);  
}  
  
//与lrj书不同，书上是判断两线段是否严格相交，此处是判断直线ab与线段cd是否相交，cd的端点在ab上也算相交  
bool Across(Point a, Point b, Point c, Point d) {  
    double tmp = Multi(c, b, a) * Multi(d, b, a);  
    if (tmp < 0 || fabs(tmp) < eps) return true;  
    return false;  
}  
  
/*求直线 l1； A1*x + B1*y + C1 = 0 与直线 l2： A2*x + B2*y + C2 = 0 的交点，此处只返回交点横坐标x 
   a，b为直线 l1 上的两点， c , d为直线 l2 上的两点 */  
double getIntersect(Point a, Point b, Point c, Point d) {  
    double A1 = b.y - a.y;  
    double B1 = a.x - b.x;  
    double C1 = (b.x - a.x) * a.y - (b.y - a.y) * a.x;  
    double A2 = d.y - c.y;  
    double B2 = c.x - d.x;  
    double C2 = (d.x - c.x) * c.y - (d.y - c.y) * c.x;  
    double x = (C2 * B1 - C1 * B2) / (A1 * B2 - A2 * B1);  
    //y = (C1 * A2 - C2 * A1) / (A1 * B2 - A2 * B1); //交点纵坐标      
    return x;  
 }  
  
int main() {  
    int n, i, j, k;  
    double best;  
    bool flag;  
  
    while (scanf ("%d", &n) && n) {  
         for (i = 0; i < n; i++) {  
            scanf ("%lf%lf", &up[i].x, &up[i].y);  
            down[i].x = up[i].x;  
            down[i].y = up[i].y - 1;  
         }  
         best = up[0].x;  
         flag = false;  
         for (i = 0; i < n && !flag; i++) {  
            for (j = 0; j < n && !flag; j++) {  
                if (i != j) {  
                   for (k = 0; k < n; k++)  
                      if (!Across(up[i], down[j], up[k], down[k])) break;  
                   if (k == n) flag = true;  
                   else if (k > Max(i, j)) {  
                      double tmp;  
                      tmp = getIntersect(up[i], down[j], up[k-1], up[k]);  
                      if (tmp > best) best = tmp;  
                      tmp = getIntersect(up[i], down[j], down[k-1], down[k]);  
                      if (tmp > best) best = tmp;  
                   }  
                }  
            }  
         }  
         if (flag) printf ("Through all the pipe.\n");  
         else printf ("%.2lf\n", best);  
    }  
}  