import java.util.*;
import java.io.*;

public class milkvisits 
{
	static String[] cows;
	static int n, m;
	static LinkedList<Integer> edges[];
	static int[] id;
	static int current = 0;
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader(new File("milkvisits.in")));
		FileWriter out = new FileWriter(new File("milkvisits.out"));
		
		String[] temp = in.readLine().split(" ");
		n = Integer.parseInt(temp[0]);
		m = Integer.parseInt(temp[1]);
		
		cows = in.readLine().split("");
		id = new int[n];
		
		
		edges = new LinkedList[n];
		for(int i = 0; i < n; i++)
			edges[i] = new LinkedList<Integer>();
		
		for(int i = 0; i < n - 1; i++)
		{
			temp = in.readLine().split(" ");
			int a = Integer.parseInt(temp[0]);
			int b = Integer.parseInt(temp[1]);
			edges[a - 1].add(b - 1);
			edges[b - 1].add(a - 1);
		}
		long start = System.nanoTime();
		fill();
		long end = System.nanoTime();
		System.out.println(end - start);
		StringBuilder binstring = new StringBuilder();
		
		long timing = 0;
		
		for(int i = 0; i < m; i++)
		{
			String[] q = in.readLine().split(" ");
			int[] query = new int[] {Integer.parseInt(q[0]) - 1, Integer.parseInt(q[1]) - 1};
			String type = q[2];
			if(id[query[0]] != id[query[1]]) binstring.append("1");
			else if(cows[query[0]].equals(type)) binstring.append("1");
			else binstring.append("0");
		}
		
//		System.out.println(end - start);
//		System.out.println(binstring.toString());
		out.write(binstring.toString() + "\n");
		out.close();
			
	}
	
	static void fill()
	{
		Queue<Integer> q = new LinkedList<Integer>();
		int currid = 1;
		boolean[] visited = new boolean[n];
		while(true)
		{
			int curr = unvis(visited);
			if(!(curr == -1)) 
			{
				q.add(curr);
				id[curr] = currid;
				visited[curr] = true;
			}
			else break;
			while(!q.isEmpty())
			{
				curr = q.poll();
				for(int adjnode : edges[curr])
				{
					if(visited[adjnode] || !cows[adjnode].equals(cows[curr])) continue;
					visited[adjnode] = true;
					q.add(adjnode);
					id[adjnode] = currid;
				}
					
			}
			currid++;
		}
	}
	
	static int unvis(boolean[] visited)
	{
		for(int i = current; i < n; i++)
		{
			if(!visited[i]) 
			{
				current = i;
				return current;
			}
		}
		return -1;
	}
	

}
