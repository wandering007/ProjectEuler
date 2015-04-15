import java.math.*;
//Reference: https://proofwiki.org/wiki/Pell%27s_Equation#Proof
public class P66
{
   public static final int MAXD = 1000;
   public static final double eps = 1e-6;
   public static final BigInteger zero = new BigInteger("0");
   public static final BigInteger one = new BigInteger("1");
   public static void main( String[] args )
   {
	  long start = System.currentTimeMillis();
	  BigInteger x = zero, temp;
	  int rec = 0;
	  for(int D = 1; D <= MAXD; D++)
	  {
		  temp = PellEqtSol(D);
		  if(x.compareTo(temp) == -1)
			  {
			  	System.out.println(D + " " + temp);
			  	x = temp;
			  	rec = D;
			  }
	  }
	  System.out.println(rec);
	  System.out.println("time cost: " + (System.currentTimeMillis() - start) + "ms");
   }
private static BigInteger PellEqtSol(int d) {
	int a0 = (int)(Math.sqrt(d) + eps);
	if(a0 * a0 == d)
		return zero;
	BigInteger p0 = one, p1 = new BigInteger(a0 + "");
	BigInteger q0 = zero, q1 = one, tmp;
    int k = a0, a = a0, t = 1, period = 0, c;
    while(true)
    {//此处仍有优化的可能
        period++;
        c = d - k * k;
        t = c / t;
        a = (int)((Math.sqrt(d) + k) / (t * 1.0) + eps);//a为整数部分
        k = a * t - k;
        if(k == a0 && 1 == t && 0 == (period & 1))
        	break;
        tmp = p1;
        p1 = p0.add(p1.multiply(new BigInteger(a + "")));
        p0 = tmp;
        tmp = q1;
        q1 = q0.add(q1.multiply(new BigInteger(a + "")));
        q0 = tmp;
    }
	return p1;
}
}
