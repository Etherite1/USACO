/*
ID: xuhumph1
LANG: JAVA
PROB: pprime

 */


import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class pprime {
	
	static ArrayList<Integer> all = new ArrayList<Integer>();

	public static void main(String[] args) throws Exception{
		FileReader myread = new FileReader(new File("pprime.in"));
		BufferedReader br = new BufferedReader(myread);
		FileWriter bw = new FileWriter(new File("pprime.out"));
		
		String input = br.readLine();
		String[] inputarr = input.split(" ");
		int a = Integer.valueOf(inputarr[0]); 
		int b = Integer.valueOf(inputarr[1]);
		
		ArrayList<Integer> result = new ArrayList<Integer>();
		
		one();
		two();
		three();
		four();
		five();
		six();
		seven();
		eight();
		
		for(int i = 0; i < all.size(); i++) if(all.get(i) >= a && all.get(i) <= b) bw.write(all.get(i) + "\n");
		
		bw.close();
		br.close();
	}
	
	static void one()
	{
		all.add(5);
		all.add(7);
	}
	
	
	static void two()
	{
		all.add(11);
	}
	
	static void three()
	{
		for (int d1 = 0; d1 <= 9; d1++) 
		{
	        for (int d2 = 0; d2 <= 9; d2++) 
	        {
	        	int palindrome = 100*d1 + 10* d2 + d1;
	        	if(isPrime(palindrome)) all.add(palindrome);
	        }
	    }
	}
	
	static void four()
	{
		for (int d1 = 1; d1 <= 9; d1+=2) 
		{	/* only odd; evens aren't so prime */
		    for (int d2 = 0; d2 <= 9; d2++) 
		    {
			    int palindrome = 1000*d1 + 100*d2  + 10*d2 + d1;
			    if(isPrime(palindrome)) all.add(palindrome);
			    	
			}
		}
	}
	
	static void five()
	{
		for (int d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
		    for (int d2 = 0; d2 <= 9; d2++) {
		        for (int d3 = 0; d3 <= 9; d3++) {
			    int palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
			    if(isPrime(palindrome)) all.add(palindrome);
			}
		    }
		}
	}
	
	static void six()
	{
		for (int d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
		    for (int d2 = 0; d2 <= 9; d2++) {
		        for (int d3 = 0; d3 <= 9; d3++) {
			    int palindrome = 100000*d1 + 10000*d2 +1000*d3 + 100*d3 + 10*d2 + d1;
			    if(isPrime(palindrome)) all.add(palindrome);
			}
		    }
		}
	}
	
	static void seven()
	{
		for (int d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
		    for (int d2 = 0; d2 <= 9; d2++) {
		        for (int d3 = 0; d3 <= 9; d3++) {
		        	for(int d4 = 0; d4 <= 9; d4++)
		        	{
		        		int palindrome = 1000000*d1 + 100000*d2 +10000*d3 + 1000*d4 + 100 * d3 + 10 * d2 + d1;
		        		if(isPrime(palindrome)) all.add(palindrome);
		        	}
			}
		    }
		}
	}
	
	static void eight()
	{
		for (int d1 = 1; d1 <= 9; d1+=2) {	/* only odd; evens aren't so prime */
		    for (int d2 = 0; d2 <= 9; d2++) {
		        for (int d3 = 0; d3 <= 9; d3++) {
		        	for(int d4 = 0; d4 <= 9; d4++)
		        	{
		        		int palindrome = 10000000*d1 + 1000000*d2 +100000*d3 + 10000*d4 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
		        		if(isPrime(palindrome)) all.add(palindrome);
		        	}
			}
		    }
		}
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
