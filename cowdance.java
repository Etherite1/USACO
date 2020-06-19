
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class cowdance {
	
	static int t;

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("cowdance.in"));
		FileWriter out = new FileWriter(new File("cowdance.out"));
		
		int n = in.nextInt();
		t = in.nextInt();
		
		int num = 0;
		int[] cows = new int[n];
		ArrayList<Integer> q = new ArrayList<Integer>();
		
		for(int i = 0; i < n; i++)
		{
			cows[i] = in.nextInt();
		}
		
		for(int k = 1; k <= n; k++)
		{
			if(find(cows, k)) 
			{
				System.out.println(k);
				out.write(k + "\n");
				break;
			}
		}
		out.close();
		in.close();
		
	}
	
	static boolean find(int[] cows, int k)
	{
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		for(int i = 0; i < k; i++)
			q.add(cows[i]);
		
		for(int i = k; i < cows.length; i++)
		{
			int temp = q.poll();
			q.add(cows[i] + temp);
		}
		
		int temp = 0;
		while(q.size() > 0)
		{
			temp = q.poll();
		}
		
		return temp <= t;
	}

}
