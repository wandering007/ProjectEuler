import java.math.BigInteger;
public class P65
{
   public static void main( String[] args )
   {
	  long start = System.currentTimeMillis();
	  BigInteger numerator = new BigInteger("1");//初始化时为第100个分数的值
	  BigInteger denominator = new BigInteger("1");
	  BigInteger temp;
	  int num = 98, k = 0;//注意：要除去第零个，故不是99，而是98
	  while(num > 0)
	  {
		  switch(num % 3)
		  {
		  case 1: 
		  case 0:
			  k = 1; break;
		  case 2:
			  k = (num + 2) / 3 * 2;
			  //break;
		  }
		  temp = denominator;
		  denominator = denominator.multiply(new BigInteger(k + "")).add(numerator);
		  numerator = temp;
		  num--;
	  }
	  numerator = denominator.multiply(new BigInteger("2")).add(numerator);
	  int res = SumOfDigits(numerator);
	  System.out.println(res);
	  //System.out.println(numerator.doubleValue() / denominator.doubleValue());
	  System.out.println("time cost: " + (System.currentTimeMillis() - start) + "ms");
   }

private static int SumOfDigits(BigInteger n) {
	int res = 0;
	BigInteger zero = new BigInteger("0");
	BigInteger ten = new BigInteger("10");
	while(n.compareTo(zero) != 0)
	{
		res += n.mod(ten).intValue();
		n = n.divide(ten);
	}
	return res;
}
}
