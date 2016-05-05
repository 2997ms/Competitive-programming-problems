#include <iostream>
using namespace std;

long long t, p, c;

void extend_euild(int a, int b)
{
    if(b == 0)
    {
        t = 1;
        p = 0;
        c = a;
    }
    else
    {
        extend_euild(b, a%b);
        int temp = t;
        t = p;
        p = temp - a/b*p;
    }
}

int main()
{
    int i, j, ok = 0, d, a, b;
    long long x, y, m, n, l;

    freopen("in.txt", "r", stdin);
    cin >> x >> y >> m >> n >> l;
    
    if(n == m)
        ok = 1;
    else{
        a = n-m;
        d = x-y;
        b = l;
        extend_euild(a, b);
        if(d % c !=0)
            ok = 1;
    }
    if(ok)
        cout << "Impossible" << endl;
    else
    {
        b = b / c;
        d = d / c;
        long long v = d * t;
        cout << (v%b+b)%b << endl;
    }
    return 0;
}