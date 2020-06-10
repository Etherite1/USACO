/*
ID: xuhumph1
LANG: JAVA
PROB: hamming
 */

import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class hamming {
	static int n;
	static int b;
	static int d;
	static ArrayList<Integer> codes = new ArrayList<Integer>();

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("hamming.in"));
		FileWriter bw = new FileWriter(new File("hamming.out"));
		
		n = in.nextInt();
		b = in.nextInt();
		d = in.nextInt();
		
		
		codes.add(0);
		
		for(int i = 1; i < (int) Math.pow(2, b); i++)
		{
			if(!(codes.size() < n)) break;
			if(greater(i)) codes.add(i);
		}
		
		int[][] format = new int[codes.size() / 10 + 1][10];
		
		String temp = "";

		for(int i = 0; i < codes.size() / 10 + 1; i++)
		{
			try 
			{
				temp += (codes.get(i * 10) + " ");
				temp += (codes.get(i * 10 + 1) + " ");
				temp += (codes.get(i * 10 + 2) + " ");
				temp += (codes.get(i * 10 + 3) + " ");
				temp += (codes.get(i * 10 + 4) + " ");
				temp += (codes.get(i * 10 + 5) + " ");
				temp += (codes.get(i * 10 + 6) + " ");
				temp += (codes.get(i * 10 + 7) + " ");
				temp += (codes.get(i * 10 + 8) + " ");
				temp += (codes.get(i * 10 + 9) + "\n");
			}
			catch(Exception IndexOutOfBounds)
			{
				break;
			}
		}
		
		temp = temp.substring(0, temp.length() - 1);
		bw.write(temp);
		bw.write("\n");
		bw.close();
		in.close();
	}
	
	static String tobin(int x)
	{
		String hex = Integer.toBinaryString(x);
		while (hex.length() < b) 
		{    //pad with 16 0's
	        hex = "0" + hex;
	    }
		
		return hex;

	}
	
	static boolean compare(String x, String y)
	{
		int counter = 0;
		String[] tempx = x.split("");
		String[] tempy = y.split("");
		for(int i = 0; i < x.length(); i++)
			if(!tempx[i].equals(tempy[i])) counter++;
		
		if(counter >= d) return true;
		else return false;

	}
	
	static boolean greater(int x) 
	{
		String hex = tobin(x);
		for(int i : codes)
		{
			String current = tobin(i);
			if(!compare(hex, current)) return false;
		}
		return true;
	}
	

}
