import java.math.BigInteger;

public class P80
{
   public static final BigInteger twenty = new BigInteger("20");
   public static final BigInteger OneHundred = new BigInteger("100");
   public static void main(String args[])
   {
	   long start = System.currentTimeMillis();
	   int[] sqr = new int[10];
	   int sum = 0;
	   for(int i = 1; i <= 9; i++)
		   sqr[i] = i * i;
	   for(int i = 1, k = 1; i < 100; i++)
	   {
		   if(k <= 9 && sqr[k] == i)
		   {
			   k++;
			   continue;
		   }
		   sum += getDigitSum(i);
	   }
	   System.out.println(sum);
	   System.out.println("time cost: " + (System.currentTimeMillis() - start) + "ms");
   }

private static int getDigitSum(int n) {
	int res = 0, cnt = 100, x;
	BigInteger p = BigInteger.ZERO, c = new BigInteger(n + ""), temp, y = null;
	while(cnt-- > 0)
	{
		temp = p.multiply(twenty);
		for(x = 1; x <= 10; x++)
		{
			y = new BigInteger(x + "");
			y = y.multiply(temp.add(y));
			if(y.compareTo(c) == 1)
				break;
		}
		x--;
		res += x;
		y = y.subtract(temp).subtract(new BigInteger(2 * x + 1 + ""));
		//y = x * (20 * p + x)
		c = (c.subtract(y)).multiply(OneHundred);
		//c = c - y, c = c * 100
		p = p.multiply(BigInteger.TEN).add(new BigInteger(x + ""));
		//p = p * 10 + x
	}
	//http://en.wikipedia.org/wiki/Methods_of_computing_square_roots
	return res;
}
}
