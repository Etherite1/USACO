package everything;

/*
ID: xuhumph1
LANG: JAVA
PROB: numtri

 */

import java.io.*;
import java.util.*;

public class numtri 
{
	public static void main(String[] args) throws Exception
	{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new FileReader(new File("C:\\temp\\numtri.in")));
		FileWriter bw = new FileWriter(new File("C:\\temp\\numtri.out"));
		
		int n = Integer.valueOf(br.readLine());

		ArrayList<int[]> tri = new ArrayList<int[]>();
		ArrayList<int[]> counts = new ArrayList<int[]>();
		for(int i = 0; i < n; i++)
		{
			String in = br.readLine();
			int[] numbers = Arrays.stream(in.split(" ")).mapToInt(Integer::parseInt).toArray();  
			tri.add(numbers);
			int[] a = new int[numbers.length];
			counts.add(a);
		}
		
//		for(int i = 0; i < counts.size(); i++) Arrays.fill(counts.get(i), 0);
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < counts.get(i).length; j++)
			{
				if(i == 0 && j == 0) counts.get(i)[j] = tri.get(i)[j];
				else if(j == 0) counts.get(i)[j] += counts.get(i - 1)[j] + tri.get(i)[j];
				else if(j == counts.get(i).length - 1) counts.get(i)[j] += counts.get(i - 1)[j - 1] + tri.get(i)[j];
				else 
				{
					if(counts.get(i - 1)[j] >= counts.get(i - 1)[j - 1]) counts.get(i)[j] += counts.get(i - 1)[j] + tri.get(i)[j];
					else counts.get(i)[j] += counts.get(i - 1)[j - 1] + tri.get(i)[j];
				}
			}
		}
		
		int largest = 0;
		for(int i = 0; i < counts.get(counts.size() - 1).length; i++)
		{
			if(counts.get(counts.size() - 1)[i] > largest) largest = counts.get(counts.size() - 1)[i];
		}
		
		bw.write(largest + "\n");
		bw.close();
		br.close();
		
	}
	
	

}

