import java.io.*;
import java.util.*;
public class convention 
{
	static int n; 
	static int m; 
	static int c;
	
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("convention.in"));
		FileWriter out = new FileWriter(new File("convention.out"));

		n = in.nextInt();
		m = in.nextInt();
		c = in.nextInt();
		
		int[] cows = new int[n];
		for(int i = 0; i < n; i++)
			cows[i] = in.nextInt();
		
		System.out.println();
		
		Arrays.sort(cows);
		
		int low = 0;
		int high = cows[cows.length - 1];
		
		while(high - low > 1)
		{
			int mid = (low + high) / 2;
			if(find(cows, mid)) high = mid;
			else low = mid;
		}
		
		out.write(high + "\n");
		out.close();
		in.close();
	}
	
	static boolean find(int[] cows, int k)
	{
		ArrayList<Integer> bus = new ArrayList<Integer>();
		
		int buses = 0;
		int i = 0;
		
		outerloop:
		while(true)
		{
			
			int temp = cows[i];
			while(cows[i] <= (temp + k) && bus.size() < c)
			{
				
				bus.add(cows[i]);
				if(i + 1 >= cows.length) break outerloop;
				i++;
			}

			bus.clear();
			buses++;
			if(buses > m) break;
		}
		
		return !(buses >= m);
		
	}

}
