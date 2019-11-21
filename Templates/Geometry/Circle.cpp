// const long double PI=acos(-1.0);
struct Circle
{
    long double x,y;
    long double r;
    long double square(long double x)
    {
        return x*x;
    }
    long double dis(Circle a,Circle b)
    {
        return sqrt(square(a.x-b.x)+square(a.y-b.y));
    }
    long double intersectionArea(Circle a,Circle b)
    {
        long double d=dis(a,b);
        if(a.r==0||b.r==0||d>=a.r+b.r)return 0;
        else if(d<=fabs(a.r-b.r))return PI*square(min(a.r,b.r));
        else
        {
            long double angA=2*acos( (square(a.r)+square(d)-square(b.r))/(2*a.r*d) );
            long double angB=2*acos( (square(b.r)+square(d)-square(a.r))/(2*b.r*d) );
            long double areaA=square(a.r)*(angA-sin(angA))/2;
            long double areaB=square(b.r)*(angB-sin(angB))/2;
            return areaA+areaB;
        }
    }
}a,b;