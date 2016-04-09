<<<<<<< HEAD
import java.math.BigInteger;
public class P57
{
   public static final int MAXN = 1000;
   public static void main( String[] args )
   {
	  long start = System.currentTimeMillis();
	  int num = 0;
	  BigInteger numerator = new BigInteger("1");
	  BigInteger denominator = new BigInteger("1");
	  for(int i = 1; i <= MAXN; i++)
	  {
		  numerator = numerator.add(denominator).add(denominator);
		  denominator = numerator.subtract(denominator);
		  if(numerator.toString().length() > denominator.toString().length())
		      num++;
	  }
	  System.out.println(num);
	  System.out.println("time cost: " + (System.currentTimeMillis() - start) + "ms");
   }
}
=======
import java.math.BigInteger;
public class P57
{
   public static final int MAXN = 1000;
   public static void main( String[] args )
   {
	  long start = System.currentTimeMillis();
	  int num = 0;
	  BigInteger numerator = new BigInteger("1");
	  BigInteger denominator = new BigInteger("1");
	  for(int i = 1; i <= MAXN; i++)
	  {
		  numerator = numerator.add(denominator).add(denominator);
		  denominator = numerator.subtract(denominator);
		  if(numerator.toString().length() > denominator.toString().length())
		      num++;
	  }
	  System.out.println(num);
	  System.out.println("time cost: " + (System.currentTimeMillis() - start) + "ms");
   }
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
