<<<<<<< HEAD
import java.math.*;
public class P20
{
	public static void main(String[] args)
	{
		BigInteger n=new BigInteger("100");
		BigInteger m=new BigInteger("10");
		BigInteger N=new BigInteger("100");
		BigInteger one=new BigInteger("1");
		BigInteger zero=new BigInteger("0");
		BigInteger res=zero;
		while(n.compareTo(one)==1)
		{
			N = N.multiply(n.subtract(one));
			n = n.subtract(one);
		}
		while(N.compareTo(zero)==1)
		{
			res=res.add(N.mod(m));
			N=N.divide(m);
		}
		System.out.println(res);
	}
=======
import java.math.*;
public class P20
{
	public static void main(String[] args)
	{
		BigInteger n=new BigInteger("100");
		BigInteger m=new BigInteger("10");
		BigInteger N=new BigInteger("100");
		BigInteger one=new BigInteger("1");
		BigInteger zero=new BigInteger("0");
		BigInteger res=zero;
		while(n.compareTo(one)==1)
		{
			N = N.multiply(n.subtract(one));
			n = n.subtract(one);
		}
		while(N.compareTo(zero)==1)
		{
			res=res.add(N.mod(m));
			N=N.divide(m);
		}
		System.out.println(res);
	}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
}