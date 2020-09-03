


import java.util.*;
import java.io.*;


public class div7 {

	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("div7.in"));
		FileWriter out = new FileWriter("div7.out");
		

		int n = Integer.parseInt(in.readLine());

		
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = Integer.parseInt(in.readLine());

		
		long[] psums = new long[n + 1];
		for(int i = 0; i < n; i++)
		{
			psums[i + 1] = psums[i] + arr[i];
		}
		
		long largest = 0;
		for(int i = 0; i < 6; i++)
		{
			int first = -1, last = -1;
			for(int j = 0; j < n + 1; j++)
			{
				if(psums[j] % 7 == i)
				{
					first = j;
					break;
				}
			}
			for(int j = n; j >= 0; j--)
			{
				if(psums[j] % 7 == i)
				{
					last = j;
					break;
				}
			}
			largest = Math.max(last - first, largest);
		}
		
		
		System.out.println(largest);
		out.write(largest + "\n");
		out.close();
	}

}
