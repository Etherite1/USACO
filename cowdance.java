
import java.io.*;
import java.util.*;

public class cowdance {
	
	static int t;

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("cowdance.in"));
		FileWriter out = new FileWriter(new File("cowdance.out"));
		
		int n = in.nextInt();
		t = in.nextInt();
		
		
		
		int[] cows = new int[n];
		
		
		for(int i = 0; i < n; i++)
		{
			cows[i] = in.nextInt();
		}

		
		for(int k = 1; k <= n; k++)
		{
			if(find(k, cows)) 
			{
				out.write(k + "\n");
				break;
			}
		}

		
		in.close();
		out.close();
		
	}
	
	
	static boolean find(int k, int[] cows)
	{
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		for(int i = 0; i < k; i++)
			q.offer(cows[i]);
		
		for(int i = k; i < cows.length; i++)
		{
			int a = q.poll();
			if(a + cows[i] > t) return false;
			q.offer(a + cows[i]);
		}
		
		int temp = 0;
		
		while(!q.isEmpty())
			temp = q.poll();
		
		return temp <= t;
	}
}
