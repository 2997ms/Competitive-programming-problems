import java.util.Scanner;
import java.io.*;
import java.math.*;
import java.math.BigInteger;
import java.util.HashMap;
public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        while(true) {
            BigInteger tmp1 = cin.nextBigInteger();
            BigInteger N = cin.nextBigInteger();
            BigInteger m = tmp1.add(N);
            System.out.println(m.toString());
        }
        // for(int i=0;i<6;i++) {
        //     m = m.add(BigInteger.ONE);
        // }
        // N = N.mod(m);
        // for(int i=0;i<3;i++) {
        //     m = m.add(BigInteger.ONE);
        // }
        // BigInteger x = BigInteger.ONE;
        // for(int i=0;i<Integer.valueOf(N.toString());i++) {
        //     x = x.multiply(tmp1);
        //     x = x.mod(m);
        // }
        // x = x.mod(m);
        // if(x.equals(BigInteger.ZERO)) {
        //     System.out.println(m.toString());   
        // } else {
        //     System.out.println(x.toString());
        // }
        // BigInteger f[][] = new BigInteger[155][155];
        // BigInteger g[][] = new BigInteger[155][155];
        // BigInteger h[][] = new BigInteger[155][155];
        // int maxn = 80;
        // for (int i=0;i<=maxn;i++) {
        //     for (int j=0;j<=maxn;j++) {
        //         f[i][j] = BigInteger.ZERO;
        //         g[i][j] = BigInteger.ZERO;
        //     }
        // }
        // f[0][0] = BigInteger.ONE;

        // for (int i=1;i<=maxn;i++) {
        //     for(int j=0;j<=maxn;j++) {
        //         for(int k=0;k<=maxn;k++) {
        //             g[j][k] = BigInteger.ZERO;
        //         }
        //     }
        //     for(int j=0;j<=i-1;j++) {
        //         g[1][j] = f[i-1][j];
        //     }
        //     for(int j=2;j<=K;j++) {
        //         for(int k=0;k<i;k++) {
        //             for(int x=0;x<=k;x++) {
        //                 g[j][k] = g[j][k].add(g[j-1][x].multiply(f[i-1-x][k-x]));
        //             }
        //         }
        //     }

        //     for(int j=0;j<i;j++) {
        //         f[i][j] = g[K][j];
        //     }
        //     f[i][i]=BigInteger.ONE;
        // }
        // int tot = 0;
        // int wz = 0;
        // g[0][0] = BigInteger.ONE;
        // for (int i=0;i<=maxn;i++) {
        //     String tmp = N.mod(tmp1).toString();
        //     int s =Integer.valueOf(tmp);
    
        //     for(int x=0;x<=maxn;x++) {
        //         for (int j=0;j<=maxn;j++) {
        //              h[x][j] = BigInteger.ZERO;
        //         }
        //     }
        //     for(int j=0;j<=i;j++) h[0][j]=g[i][j];
        //     for(int x=1;x<=s;x++) {
        //         for (int j=0;j<=i;j++) {
        //             h[x][j] = BigInteger.ZERO;
        //             for (int k=0;k<=j;k++) {
        //                 h[x][j]=h[x][j].add(h[x-1][k].multiply(f[i-k][j-k]));
        //             }
        //         }
        //     }
        //      for(int x=0;x<=maxn;x++) {
        //         for (int j=0;j<=maxn;j++) {
        //              g[x][j] = BigInteger.ZERO;
        //         }
        //     }
        //     for (int j=0;j<=i;j++) g[i+1][j]=h[s][j];
        //     N=N.divide(tmp1);
        //     if(N.equals(BigInteger.ZERO)) {
        //         wz=i+1;
        //         break;
        //     }
        // }

        // BigInteger ans=BigInteger.ZERO;
        // for (int i=0;i<=maxn;i++) {
        //     ans = ans.add(g[wz][i]);
        // }
        //System.out.println(x.toString());
    }
}


import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
    static public void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int t = cin.nextInt();
        while (t-- != 0)
        {
            int a = cin.nextInt();
            String s = cin.next();
            char ch = s.charAt(0);
            BigInteger ans = new BigInteger("1");
            for (int i = 2; i <= a; i++)
                ans = ans.multiply(BigInteger.valueOf(i));
            s = ans.toString();
            int len = s.length();
            int x = 0;
            for (int i = 0; i < len; i++)
                if (s.charAt(i) == ch)
                    x++;
            System.out.println(x);
        }
    }
}


import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        BigInteger b;
        BigInteger one=new BigInteger("1");
        BigInteger zero=new BigInteger("0");
        while(cin.hasNext()){
            BigInteger a=new BigInteger("1");
            b=cin.nextBigInteger();
            if(b.equals(zero)){
                break;
            }
            System.out.print(b);
            for(; ; b=b.subtract(one)){
                if(b.equals(zero)) break;
                a=a.multiply(b);
            }
            String p=a.toString();
            int len=p.length();
            int res[]=new int[11];
            for(int i=0; i<11; i++){
                res[i]=0;
            }
            for(int i=0; i<len; i++){
                if(p.charAt(i)=='0') res[0]++;
                if(p.charAt(i)=='1') res[1]++;
                if(p.charAt(i)=='2') res[2]++;
                if(p.charAt(i)=='3') res[3]++;
                if(p.charAt(i)=='4') res[4]++;
                if(p.charAt(i)=='5') res[5]++;
                if(p.charAt(i)=='6') res[6]++;
                if(p.charAt(i)=='7') res[7]++;
                if(p.charAt(i)=='8') res[8]++;
                if(p.charAt(i)=='9') res[9]++;
            }
            System.out.printf("! --\n   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9]);
            
        }
    }
}