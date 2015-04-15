import java.math.*;

public class P78
{
   public final static int MAXN = 100000;
   public final static BigInteger MOD = new BigInteger("1000000");
   public final static BigInteger zero = new BigInteger("0");
   public static BigInteger p[] = new BigInteger[MAXN];	
   public static void main( String[] args )
   {
	   long start = System.currentTimeMillis();
	   p[0] = new BigInteger("1");
	   for(int i = 1; i < MAXN; i++)
	   {
		   p[i] = zero;//需要初始化，否则为空指针，报错
		   if((getPartition(i).mod(MOD)).compareTo(zero) == 0)
		   {
			   System.out.println(i);
			   break;
		   }
		   //System.out.println(i + " " + p[i]);
	   }
	   System.out.println("time cost: " + (System.currentTimeMillis() - start) + "ms");
   }
private static BigInteger getPartition(int n) {
    for(int k = 1, g; ; k++)
    {
        g = k * (3 * k - 1) / 2;
        if(n - g < 0)
            break;
        if(1 == (k & 1))
        	p[n] = p[n].add(p[n - g]);
        else p[n] = p[n].subtract(p[n - g]);
        g = k * (3 * k + 1) / 2;
        if(n - g < 0)
            break;
        if(1 == (k & 1))
        	p[n] = p[n].add(p[n - g]);
        else p[n] = p[n].subtract(p[n - g]);
    }
    return p[n];
}
}
