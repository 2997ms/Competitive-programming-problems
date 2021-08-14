// https://www.geeksforgeeks.org/given-a-set-of-line-segments-find-if-any-two-segments-intersect/

// CF 1359F
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
// #include <unordered_map>
// #include <bitset>
// #include <iomanip>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define EPS 1e-9
#define LL_INF 0x3fffffffffffffff
#define MEM(a, b) memset(a, b, sizeof(a))
#define PPER(i, n, m) for (int i = n; i >= m; i--)
#define REPP(i, n, m) for (int i = n; i <= m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)
#define PER(i, n, m) for (int i = n; i > m; i--)
#define SA(n) scanf("%d", &(n))
#define SLLA(n) scanf("%lld", &(n))
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define DE(val) cout << #val << ": " << val << endl;
// #define DBG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// #else
// #define DBG(...) 42
// #endif
const int dx44[6] = {0, -1, -1, 1, 1};
const int dy44[6] = {0, -1, 1, -1, 1};
const int dx4[6] = {0, 0, 1,-1};
const int dy4[6] = {1, -1, 0,0};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};

void update(ll& x,ll v){
    if(x==-1)x=v;
    else if(x>v)x=v;
}
 
ll po(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}
void extgcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b)
    {
        d = a;
        x = 1;
    }
    else
    {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
ll inverse(ll a, ll n)
{
    ll d, x, y;
    extgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const int maxn = 1e5 + 15;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
#define mst(x, a) memset(x, a, sizeof(x))
/*************************************************************************/

inline int sign(double x) { return x < -EPS ? -1 : x > EPS; }
inline int cmp(double x, double y) { return sign(x - y); }

struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) : x(_x), y(_y) {}
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double k) const { return Point(x * k, y * k); }
  Point operator/(double k) const { return Point(x / k, y / k); }
  double operator^(const Point &p) const { return x*p.y - y*p.x; }
}pog[maxn];

double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
double det(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
 
double curX;

struct Segment {
    Point left, right;
    int idx;
    Segment() {}
    Segment(Point a, Point b, int _idx): idx(_idx) {
        if(cmp(a.x, b.x) < 0) {
            left = a;
            right = b;
        } else {
            left = b;
            right = a;
        }
    }

    double getY(double xx) const{
        return left.y + (xx - left.x) * (right.y - left.y) / (right.x - left.x);
    }

    bool operator<(const Segment &b) const {
        double y1 = getY(curX);
        double y2 = b.getY(curX);
        if(cmp(y1, y2) != 0) {
            return cmp(y1, y2) < 0;
        }
        return idx < b.idx;
    }
}seg[maxn];

double xmult(Point p0,Point p1,Point p2) //p0p1 X p0p2
{
    return (p1-p0)^(p2-p0);
}
 
bool left(const Point &start, const Point &dir, const Point &p) {
  return sign(det(p - start, dir)) >= 0;
}

bool Seg_inter_line(Segment l1,Segment l2) //判断直线l1和线段l2是否相交
{
    return sign(xmult(l2.left,l1.right,l1.left))*sign(xmult(l2.right,l1.right,l1.left)) <= 0;
}

bool intersectLine(const Segment &a, const Segment &b) {
  if (left(a.left, a.right - a.left, b.right)) {
    return left(a.right, a.left - a.right, b.left) &&
           left(b.left, b.right - b.left, a.left) &&
           left(b.right, b.left - b.right, a.right);
  } else {
    return left(a.left, a.right - a.left, b.left) &&
           left(b.left, b.right - b.left, a.right) &&
           left(b.right, b.left - b.right, a.left);
  }
}
bool intersectSegment(const Segment &a, const Segment &b) {
  bool f1;
  if (left(a.left, a.right - a.left, b.right)) {
    f1 = left(a.right, a.left - a.right, b.left) &&
           left(b.left, b.right - b.left, a.left) &&
           left(b.right, b.left - b.right, a.right); 

  } else {
    f1 = left(a.left, a.right - a.left, b.left) &&
           left(b.left, b.right - b.left, a.right) &&
           left(b.right, b.left - b.right, a.left);
  }

  return f1 && ((max(a.left.x, a.right.x)>=min(b.left.x, b.right.x))&&                     //排斥实验
   (max(b.left.x, b.right.x)>=min(a.left.x, a.right.x))&&
   (max(a.left.y, a.right.y)>=min(b.left.y, b.right.y))&&
   (max(b.left.y, b.right.y)>=min(a.left.y, a.right.y)));
}

bool hasIntersection(vector<Segment> &v) {
  vector<tuple<Point, bool, int>> points;
  int N = v.size();
  REP(i, 0, N) {
    points.emplace_back(v[i].left, true, i);
    points.emplace_back(v[i].right, false, i);
  }
  sort(points.begin(), points.end(),
       [](const tuple<Point, bool, int> &a, const tuple<Point, bool, int> &b) {
         return cmp(get<0>(a).x, get<0>(b).x) < 0;
       });
 
  set<Segment> tree;
  for (auto g : points) {
    Point p = get<0>(g);
    bool isLeft = get<1>(g);
    int idx = get<2>(g);
    curX = p.x;
    if (isLeft) {
      auto iter = tree.insert(v[idx]).first;
      if (iter != tree.begin()) {
        iter--;
        if (intersect(v[idx], *iter)) return true;
        iter++;
      }
      iter++;
      if (iter != tree.end() && intersect(v[idx], *iter)) return true;
    } else {
      auto iter = tree.find(v[idx]);
      if (iter != tree.begin()) {
        auto iter1 = iter;
        auto iter2 = iter;
        iter1--;
        iter2++;
        if (iter2 != tree.end() && intersect(*iter1, *iter2)) return true;
      }
      tree.erase(iter);
    }
  }
  return false;
}

std::vector<Segment> testv;
int n;
double dx[maxn], dy[maxn], dirx[maxn], diry[maxn];

void solve() {
    SA(n);
    REPP(i,1,n) {
        double tmpx, tmpy, tmpv;
        scanf("%lf%lf%lf%lf%lf", &dx[i], &dy[i], &tmpx, &tmpy, &tmpv);

        double len = sqrt(tmpx*tmpx + tmpy*tmpy);
        dirx[i] = tmpx/len*tmpv;
        diry[i] = tmpy/len*tmpv;
    }

    double le = 0;
    double ri = 1e11;
    int cnt = 0;
    while(fabs(ri - le) / max(1.0, abs(ri)) > 1e-9) {
        double mid = (le + ri)/2;
        testv.clear();
        REPP(i,1,n) {
            Point tmpst = Point(dx[i], dy[i]);
            Point tmpen = Point(dx[i] + mid* dirx[i], dy[i] + mid*diry[i]); 
            Segment t = Segment(tmpst, tmpen, i);
            testv.push_back(t);
        }
        if(hasIntersection(testv)) {
            ri = mid;
        } else {
            le = mid;
        }
    }
    double g = 1e11;
    if(ri == g) {
        puts("No show :(");
        return;
    }
    printf("%.15lf\n", le);
}

int main()
{   
#ifndef ONLINE_JUDGE
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
#endif
    //  ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;
    // SA(t);
    t = 1;
    REPP(i,1,t) {
        solve();
    }
    return 0;
 
}
