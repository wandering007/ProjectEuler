import java.math.*;

public class P97
{
   public static void main( String[] args )
   {
	   long start = System.currentTimeMillis();
	   BigInteger a = new BigInteger("28433");
	   int n = 7830457;
	   BigInteger one = new BigInteger("1");
	   BigInteger x = new BigInteger("2");
	   BigInteger Module = new BigInteger("10000000000");
	   BigInteger res = one;
	   while(n != 0)
	   {
		   if(1 == (n & 1))
			   res = res.multiply(x).mod(Module);
		   x = x.multiply(x);
		   n >>= 1;
	   }
	   res = a.multiply(res).add(one).mod(Module);
	   System.out.println(res);
	   System.out.println("time cost: " + (System.currentTimeMillis() - start) + "ms");
   }
}
