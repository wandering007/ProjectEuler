//http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibFormula.html

public class P104_Pandigital_Fibonacci_ends {
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		long Fn1 = 1, Fn2 = 1, Fn = 1;
		final long MOD = 1000000000;
		final double Phi = 1.618033988749894;
		for(int index = 3; ; ++index)
		{
			Fn = Fn1 + Fn2;
			Fn1 = Fn2;
			Fn2 = Fn;
			if(Fn2 >= MOD)
				Fn2 = Fn2 % MOD;
			if( true == isPandigital(Fn2) )
			{
				double p = index * Math.log10(Phi) - Math.log10(5) / 2;
				if ( true == isPandigital( (long)Math.pow( 10, p - (long)p + 8 ) ) )
				{
					System.out.println(index);
					break;
				}
			}
		}
		System.out.println("Time cost: " + (System.currentTimeMillis() - start) + "ms");
	}

	private static boolean isPandigital(long number) {
		boolean[] vis= new boolean[10];
		while(number != 0)
		{
			vis[(int)(number % 10)] = true;
			number /= 10;
		}
		for(int i = 1; i < 10; ++i)
		{
			if(false == vis[i])
				return false;
		}
		return true;
	}
}