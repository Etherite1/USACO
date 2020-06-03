package everything2;
/*
ID: xuhumph1
LANG: JAVA
TASK: ariprog
*/


import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;

public class ariprog {
	
	public static ArrayList<Integer> allbs = new ArrayList<Integer>();;
	public static int[] arr1 = new int[125001];
	public static Set<Integer> set = new HashSet<>(allbs);

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception {
		String filename = "C:\\temp2\\ariprog.in";
//		String filename = "ariprog.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);

		String filename2 = "C:\\temp2\\ariprog.out";
//		String filename2 = "ariprog.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		int numProgs = Integer.valueOf(br.readLine());
		int bisquare = Integer.valueOf(br.readLine());
		genbs(numProgs, bisquare);
		
		allbs.addAll(set);

		Collections.sort(allbs);

		Arrays.fill(arr1, 0);
		for(int i = 0; i < allbs.size(); i++) {
			arr1[allbs.get(i)] = 1;
		}
		
    	ArrayList<int[]> res = findbisquares(numProgs, bisquare);
		
	    res.sort((firstElement, secondElement) -> Integer.compare(firstElement[1], secondElement[1]));
		if(res.size() == 0) {
			myread2.write("NONE\n");
		}
		else {
		for(int i = 0; i < res.size(); i++) {
			myread2.write(res.get(i)[0] + " " + res.get(i)[1] + "\n");
		}}
		br.close();
		myread2.close();
		
		
//		System.out.println(isbs(37 + 4 * 4, numProgs, bisquare));
	}
	
	public static ArrayList<int[]> findbisquares(int numProgs, int bisquare) 
	{
		boolean seq = true;
		long stt = System.nanoTime();
		ArrayList<int[]> res = new ArrayList();
		int startUpper = allbs.size() - numProgs;

		for(int start = 0; start <= startUpper; start++) 
		{
			int incrUpper = (2 * bisquare * bisquare - allbs.get(start)) ;
			
			for(int incr = 1; incr <= incrUpper; incr++) 
			{
				
//				if((allbs.get(start) + incr * (numProgs-1)) > (bisquare * bisquare * 2))
//					break;
				seq = true;
				//int[] current = generateap(allbs.get(start), incr, numProgs); // arithmetic progression list
				for(int k = 0; k < numProgs; k++)
				{
					
					int currentValue = allbs.get(start) + incr * k;

					if(isbs(currentValue))
					{
						continue;
					}
					else 
						seq = false; break;
				}
				if(seq)
				res.add(new int[] {allbs.get(start), incr});

			}
		}
		long end = System.nanoTime();
		System.out.println(end - stt);
		return res;
		
	}
	
	
	public static void genbs(int numProgs, int bisquare) {
		for(int p = 0; p <= bisquare; p++) 
		{
			for(int q = 0; q <= bisquare; q++) 
			{
				set.add(p * p + q * q);
			}
			
		}
	}
	
	public static boolean isbs(int input) {
		if(arr1[input] == 1) {
			return true;
		}
		else
			return false;
	}
	
	public static boolean arraybs(int[] input) {
		for(int i = 0; i < input.length; i++) {
			if(arr1[input[i]] == 1) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
	
	
	
	public static int[] generateap(int start, int incr, int length) {
		int[] fin = new int[length];
		for(int i = 0; i < length; i++) {
			fin[i] = start + incr * i;
		}
		return fin;
	}

}
