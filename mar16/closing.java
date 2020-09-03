import java.io.*;
import java.util.*;
public class closing 
{
	static int n, m;
	
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new FileReader("C:\\temp\\closing.in"));
		FileWriter out = new FileWriter("closing.out");
		
		n = in.nextInt();
		m = in.nextInt();
		
		LinkedList<Integer> edges[] = new LinkedList[n];
		for(int i = 0; i < n; i++)
		{
			edges[i] = new LinkedList<Integer>();
		}
		
		for(int i = 0; i < m; i++)
		{
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			edges[x].add(y);
			edges[y].add(x);
		}
		
		int[] closings = new int[n - 1];
		for(int i = 0; i < n - 1; i++)
		{
			closings[i] = in.nextInt() - 1;
		}
		
		if(fill(edges)) out.write("YES\n");
		else out.write("NO\n");
		
		for(int i : closings)
		{
			for(LinkedList<Integer> j : edges)
				for(int k = 0; k < j.size(); k++)
				{
					if(j.get(k) == i) 
					{
						j.remove(k);
						k--;
					}
				}
			edges[i].clear();
			edges[i].add(-1);
			if(fill(edges)) out.write("YES\n");
			else out.write("NO\n");
		}
		
		out.close();
		in.close();
	}
	
	static boolean fill(LinkedList<Integer>[] adj)
	{
		Queue<Integer> q = new LinkedList<Integer>();
		boolean[] visited = new boolean[n];
		int compnum = 0;
		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				visited[i] = true;
				if(!adj[i].isEmpty())
					if(adj[i].get(0) == -1) continue;
				
				if(compnum + 1 > 1) return false;
				else compnum++;

				q.add(i);
				while(!q.isEmpty())
				{
					int curr = q.poll();
					for(int adjnode : adj[curr])
					{
						if(visited[adjnode] || adjnode == -1) continue;
						visited[adjnode] = true;
						q.add(adjnode);
					}
				}
			}
		}
		if(compnum > 1) return false;
		else return true;
	}

}
