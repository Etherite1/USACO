
/*
ID: xuhumph1
LANG: JAVA
PROB: frac1

 */
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class frac1 {
	
	static ArrayList<Frac> all = new ArrayList<Frac>();

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new FileReader(new File("frac1.in")));
		FileWriter bw = new FileWriter(new File("frac1.out"));
		int n = Integer.valueOf(br.readLine());

		
		find(n);
		all.add(new Frac(0, 1));
		all.add(new Frac(1, 1));
		
		Frac[] fin = all.toArray(new Frac[0]);
		fin = bubbleSort(fin);

		
		for(Object a : fin) 
			bw.write(a.toString() + "\n");
		bw.close();
		br.close();

	}
	
	static void find(int n)
	{
		for(int num = 0; num <= n; num++)
			for(int denom = 1; denom <= n; denom++)
			{
				if(num > denom) continue;
				if(isReduced(num, denom)) all.add(new Frac(num, denom));
			}
	}
	
	static boolean isReduced(int num, int denom)
	{
		int gcd = GCD(num, denom);

		int[] a = new int[2];
		a[0] = num / gcd;
		a[1] = denom / gcd;
		
		if(a[1] == 1) return false;
		else if (gcd == 1) return true;
		else return false;
	}
	
	static int GCD(int a, int b)
	{
		   if (b==0) return a;
		   return GCD(b,a%b);
	}
	
	static Frac[] bubbleSort(Frac[] ar)
	{
	   for (int i = (ar.length - 1); i >= 0; i--)
	   {
	      for (int j = 1; j <= i; j++)
	      {
	         if (((float) ar[j-1].num / (float) ar[j-1].denom) > ((float) ar[j].num / (float) ar[j].denom))
	         {
	              Frac temp = ar[j-1];
	              ar[j-1] = ar[j];
	              ar[j] = temp;
	         } 
	      } 
	   } 
	   return ar;
	}
	

}

class Frac
{
	int num;
	int denom;
	public Frac(int n, int d)
	{
		num = n;
		denom = d;
	}
	
	public String toString()
	{
		return num + "/" + denom;
	}
}
