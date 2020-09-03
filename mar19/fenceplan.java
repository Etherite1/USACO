
import java.util.*;
import java.io.*;


public class fenceplan {
	
	static int n, m;

	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("fenceplan.in"));
		FileWriter out = new FileWriter("fenceplan.out");
		
		String[] x = in.readLine().split(" ");
		n = Integer.parseInt(x[0]);
		m = Integer.parseInt(x[1]);
		
		Cow[] cows = new Cow[n];
		for(int i = 0; i < n; i++)
		{
			x = in.readLine().split(" ");
			Cow c = new Cow(Integer.parseInt(x[0]), Integer.parseInt(x[1]));
			cows[i] = c;
		}
		
		LinkedList<Integer> edges[] = new LinkedList[n];
		for(int i = 0; i < n; i++)
			edges[i] = new LinkedList<Integer>();
		
		for(int i = 0; i < m; i++)
		{
			x = in.readLine().split(" ");
			edges[Integer.parseInt(x[0]) - 1].add(Integer.parseInt(x[1]) - 1);
			edges[Integer.parseInt(x[1]) - 1].add(Integer.parseInt(x[0]) - 1);
		}
		
		out.write(find(edges, cows) + "\n");
		out.close();
	}
	
	static int find(LinkedList<Integer> edges[], Cow[] cows)
	{
		boolean[] visited = new boolean[n];
		Queue<Integer> q = new LinkedList<Integer>();
		ArrayList<Component> comps = new ArrayList<Component>();
		
		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				visited[i] = true;
				Component x = new Component();
				q.add(i);
				x.nodes.add(cows[i]);
				while(!q.isEmpty())
				{
					int curr = q.poll();
					for(int adjnode : edges[curr])
					{
						if(!visited[adjnode])
						{
							q.add(adjnode);
							visited[adjnode] = true;
							x.nodes.add(cows[adjnode]);
						}
					}
				}
				comps.add(x);
			}
		}
		
		int small = Integer.MAX_VALUE;
		for(Component x : comps)
		{
			int a = findperimeter(x);
			if(a < small) small = a;
		}
		
		return small;
	}
	
	static int findperimeter(Component x)
	{
		int sx = Integer.MAX_VALUE;
		int lx = 0;
		int sy = Integer.MAX_VALUE;
		int ly = 0;
		for(Cow i : x.nodes)
		{
			if(i.x < sx) sx = i.x;
			if(i.y < sy) sy = i.y;
			if(i.x > lx) lx = i.x;
			if(i.y > ly) ly = i.y;
		}
		
		return 2 * ((lx - sx) + (ly - sy));
	}

}

class Cow
{
	int x, y;
	public Cow(int l, int r)
	{
		x = l;
		y = r;
	}
}

class Component
{
	ArrayList<Cow> nodes = new ArrayList<Cow>();
}

