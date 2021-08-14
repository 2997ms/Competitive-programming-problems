//复数结构体
struct complex
{
    double r, i;
    complex(double _r = 0.0, double _i = 0.0)
    {
        r = _r;
        i = _i;
    }
    complex operator +(const complex &b)
    {
        return complex(r + b.r, i + b.i);
    }
    complex operator -(const complex &b)
    {
        return complex(r - b.r, i - b.i);
    }
    complex operator *(const complex &b)
    {
        return complex(r*b.r - i*b.i, r*b.i + i*b.r);
    }
};

/*
*进行fft和ifft前的反转变换
*位置i和i二进制反转后位置互换
*len必须去2的幂
*/
void change(complex y[], int len)
{
    int i, j, k;
    for (i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j)
            swap(y[i], y[j]);
        //交换互为小标反转的元素,i<j保证交换一次
        //i做正常的+1，j左反转类型的+1，始终i和j是反转的
        k = len / 2;
        while (j >= k)
        {
            j -= k;
            k /= 2;
        }
        if (j < k)
            j += k;
    }
}

/*
*fft
*len必须为2^k形式
*on=1时DFT,on=-1是IDFT
*/
void fft(complex y[], int len, int on)
{
    change(y, len);
    for (int h = 2; h <= len; h <<= 1)
    {
        complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
        for (int j = 0; j < len; j += h)
        {
            complex w(1, 0);
            for (int k = j; k < j + h / 2; k++)
            {
                complex u = y[k];
                complex t = w*y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w*wn;
            }
        }
    }
    if (on == -1)
    {
        for (int i = 0; i < len; i++)
        {
            y[i].r /= len;
        }
    }
}

ll sum[maxn];
complex x1[maxn], x2[maxn];

int n,m,k,maxx;

void get_ans() {
    int len = 1;
    while (len < ( n + m + 1))
        len <<= 1;
    for (int i = 0; i <= n; i++)
    {
        x1[i] = complex(c[i], 0);
    }
    for (int i = maxx + 1; i < len; i++)
    {
        x1[i] = complex(0, 0);
    }
     for (int i = 0; i <= m; i++)
    {
        x2[i] = complex(d[i], 0);
    }
    for (int i = m + 1; i < len; i++)
    {
        x2[i] = complex(0, 0);
    }
    fft(x1, len, 1);
    fft(x2, len, 1);
    for (int i = 0; i < len; i++)
    {
        x1[i] = x1[i] * x2[i];
    }
    fft(x1, len, -1);
    for (int i = 0; i < len; i++)
    {
        sum[i] = (ll)(x1[i].r + 0.5);
    }
}