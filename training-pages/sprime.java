
/*
ID: xuhumph1
LANG: JAVA
PROB: sprime
 */

import java.io.*;
import java.util.*;

public class sprime {
	
	static long start;
	static long end;
	static int[] primes = new int[] {1, 2, 3, 5, 7, 9};
	static int[] rest = new int[] {1, 3, 7, 9};
	static ArrayList<Integer> all = new ArrayList<Integer>();
	static ArrayList<Integer> templist = new ArrayList<Integer>();
	
	public static void main(String[] args) throws Exception
	{
		start = System.nanoTime();
		BufferedReader br = new BufferedReader(new FileReader(new File("sprime.in")));
		FileWriter bw = new FileWriter(new File("sprime.out"));
		
		int n = Integer.valueOf(br.readLine());
		find(n - 1, n - 1);
		for(int i : all) bw.write(i + "\n");
		
		bw.close();
		br.close();
		end = System.nanoTime();
		System.out.println(end - start);
	}
	
	static void find(int n, int temp)
	{
		if(temp == 0) 
		{
			String a = "";
			for(int i : templist) a += String.valueOf(i);
			for(int i : rest)
			{
				a += i;
				int b = Integer.valueOf(a);
				if(isPrimerib(b, n + 1))
				{
					all.add(b);
				}
				a = a.substring(0, a.length() - 1);
				
			}
			templist.remove(templist.size() - 1);
			
			return;
		}
		for(int i = 0; i < 6; i++) 
		{
			if(templist.size() == 0 && primes[i] == 1)
			{
				continue;
			}
			else if (templist.size() != 0 && primes[i] == 2) 
			{
				continue;
			}
			templist.add(primes[i]);
			find(n, temp - 1);
		}
		if(templist.size() > 0) templist.remove(templist.size() - 1);

	}
	
	static boolean isPrimerib(int a, int n)
	{
		for(int i = n - 1; i >= 0; i--)
		{
			if(isPrime(a / (int) Math.pow(10, i) )) 
			{
				continue;
			}
			else 
				return false;
		}
		return true;
	}

	public static boolean isPrime(int a)
	{
		int root = (int) Math.sqrt(a) ;
		for(int i=2; i<=root; i++) 
		{
		   if(a % i == 0)
		       return false;
		} 
		return true;
	}
	
}
