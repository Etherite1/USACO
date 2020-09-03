import java.util.*;
import java.io.*;


public class maxcross 
{

	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("maxcross.in"));
		FileWriter out = new FileWriter("maxcross.out");
		
		int n = in.nextInt();
		int k = in.nextInt();
		int b = in.nextInt();
		
		int[] psums = new int[n + 1];
		boolean[] broken = new boolean[n];
		
		for(int i = 0; i < b; i++)
		{
			broken[in.nextInt() - 1] = true;
		}

		for(int i = 0; i < n; i++)
		{
			if(broken[i]) psums[i + 1] = psums[i];
			else psums[i + 1] = psums[i] + 1;
		}
		
		int smallest = Integer.MAX_VALUE;
		
		for(int i = 1; i < n - k + 2; i++)
		{
			if(k - (psums[i + k - 1] - psums[i - 1]) < smallest) 
				smallest = k - (psums[i + k - 1] - psums[i - 1]);
		}
		System.out.println(smallest);
		out.write(smallest + "\n");
		out.close();
	}

}
