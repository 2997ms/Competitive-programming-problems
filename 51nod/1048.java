import java.util.Scanner;
import java.io.*;
import java.math.*;
import java.math.BigInteger;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        BigInteger N = cin.nextBigInteger();
        BigInteger f[][] = new BigInteger[155][155];
        BigInteger g[][] = new BigInteger[155][155];
        
        for (int i=0;i<=120;i++) {
            for (int j=0;j<=120;j++) {
                f[i][j] = BigInteger.ZERO; 
                g[i][j] = BigInteger.ZERO; 
            }
        }
        f[0][0] = BigInteger.ONE;

        for (int i=1;i<=120;i++) {
            f[i][i] = BigInteger.ONE;
            for (int j=0;j<i;j++) {
                for (int k=0;k<=j;k++) {
                    f[i][j] = f[i][j].add(f[i-1][k].multiply(f[i-1-k][j-k]));
                }
            }
        }
        BigInteger Two = BigInteger.ONE.add(BigInteger.ONE);
        int tot = 0;
        for (int i=0;i<=120;i++) {
            if (N.mod(Two).toString().charAt(0) == '1') {
                tot++;
                if(tot==1) {
                    for (int j=0;j<=i;j++) {
                        g[1][j] = f[i][j];
                    }
                } else {
                    for (int j=0;j<=i;j++) {
                        for(int k=0;k<=j;k++) {
                            g[tot][j] = g[tot][j].add(g[tot-1][k].multiply(f[i-k][j-k]));
                        }
                    }
                }
            }
            N=N.divide(Two);
        }
        BigInteger ans=BigInteger.ZERO;

        for (int i=0;i<=120;i++) {
            ans = ans.add(g[tot][i]);
        }
         System.out.println(ans.toString());
    }
}
