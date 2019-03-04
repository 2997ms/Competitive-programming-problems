import java.util.Scanner;
import java.io.*;
import java.math.*;
import java.math.BigInteger;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        BigInteger tmp1 = cin.nextBigInteger();
        BigInteger N = cin.nextBigInteger();
        BigInteger m = BigInteger.ZERO;
        for(int i=0;i<6;i++) {
            m = m.add(BigInteger.ONE);
        }
        N = N.mod(m);
        for(int i=0;i<3;i++) {
            m = m.add(BigInteger.ONE);
        }
        BigInteger x = BigInteger.ONE;
        for(int i=0;i<Integer.valueOf(N.toString());i++) {
            x = x.multiply(tmp1);
            x = x.mod(m);
        }
        x = x.mod(m);
        if(x.equals(BigInteger.ZERO)) {
            System.out.println(m.toString());   
        } else {
            System.out.println(x.toString());
        }
    }
}
