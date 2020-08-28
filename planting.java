package everything;

import java.io.*;
import java.util.*;

public class planting 
{

	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("C:\\temp\\planting.in"));
//		FileWriter out = new FileWriter(new File("planting.out"));
		
		int n = in.nextInt();
		
		int[] all = new int[n];
		
		
		for(int i = 0; i < n - 1; i++)
		{
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			all[a]++;
			all[b]++;
		}
		
		Arrays.sort(all);
//
//		out.write((all[all.length - 1] + 1) + "\n");
//		out.close();
//		

		System.out.println();
	}
	
	

}
