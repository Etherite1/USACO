

import java.util.*;
import java.io.*;


public class where {

	static String[][] grid;
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("where.in"));
		FileWriter out = new FileWriter("where.out");
		int n = Integer.parseInt(in.readLine());
		grid = new String[n][n];
		for(int i = 0; i < n; i++)
		{
			grid[i] = in.readLine().split("");
		}

		for(int x1 = 0; x1 < n; x1++)
		{
			for(int y1 = 0; y1 < n; y1++)
			{
				for(int x2 = x1; x2 < n; x2++)
				{
					for(int y2 = y1; y2 < n; y2++)
					{
						if(x1 == x2 && y1 == y2) continue;
						find(x1, y1, x2, y2);
					}
				}
			}
		}
		
		boolean[] marked = new boolean[pcls.size()];
		for(int i = 0; i < pcls.size(); i++)
		{
			for(int j = i + 1; j < pcls.size(); j++)
			{
				if(marked[i] || marked[j]) continue;
				if(contains(pcls.get(i), pcls.get(j))) 
				{
					marked[i] = true;
				}
				else if(contains(pcls.get(j), pcls.get(i)))
				{
					marked[j] = true;
				}
			}
		}
		
		for(int i = 0; i < pcls.size(); i++)
		{
			if(marked[i])
			{
				pcls.remove(i);
			}
		}
		for(PCL i : pcls) System.out.println(i);
		
		int num = 0;
		for(boolean i : marked) if(!i) num++;
		
		System.out.println(num);
		
		out.write(num + "\n");
		out.close();
	}
	
	static boolean contains(PCL a, PCL b)
	{
		if(a.x1 >= b.x1 && a.y1 >= b.y1 && a.x2 <= b.x2 && a.y2 <= b.y2) return true;
		else return false;
	}
	
	static ArrayList<PCL> pcls = new ArrayList<>();
	
	static boolean find(int x1, int y1, int x2, int y2)
	{
		String[][] curr = new String[x2 - x1 + 1][y2 - y1 + 1];
		for(int x = x1; x <= x2; x++)
		{
			for(int y = y1; y <= y2; y++)
			{
				curr[x - x1][y - y1] = grid[x][y];
			}
		}
		
		
		if(fill(curr)) pcls.add(new PCL(x1, y1, x2, y2, curr));
		return false;
	}
	
	static boolean fill(String[][] grid)
	{
		int n = grid.length;
		int m = grid[0].length;
		LinkedList<int[]> edges[][] = new LinkedList[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				edges[i][j] = new LinkedList<int[]>();
				
		for(int x = 0; x < n; x++)
			for(int y = 0; y < m; y++)
			{
				//left
				if(!(x - 1 < 0)) edges[x][y].add(new int[] {x - 1, y});
				
				//right
				if(!(x + 1 >= n)) edges[x][y].add(new int[] {x + 1, y});

				//up
				if(!(y - 1 < 0)) edges[x][y].add(new int[] {x, y - 1});

				//down
				if(!(y + 1 >= m))edges[x][y].add(new int[] {x, y + 1});
			}
		
		Queue<int[]> q = new LinkedList<>();
		boolean[][] visited = new boolean[n][m];
		HashMap<String, Integer> numbers = new HashMap<String, Integer>();
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(visited[i][j]) continue;
				q.add(new int[] {i, j});
				while(!q.isEmpty())
				{
					int[] curr = q.poll();
					visited[curr[0]][curr[1]] = true;
					for(int[] adjnode : edges[curr[0]][curr[1]])
					{
						if(visited[adjnode[0]][adjnode[1]]) continue;
						if(!grid[curr[0]][curr[1]].equals(grid[adjnode[0]][adjnode[1]])) continue;
						q.add(adjnode);
						
					}
				}
				numbers.put(grid[i][j], numbers.getOrDefault(grid[i][j], 0) + 1);
			}
		}
		
		if(numbers.size() > 2) return false;
		boolean one = false, two = false;
		for(int val : numbers.values())
		{
			if(val == 1) one = true;
			if(val >= 2) two = true;
		}
		if(one && two) return true;
		else return false;
	}
	
	static class PCL
	{
		int x1, y1, x2, y2;
		String[][] grid;
		public PCL(int x, int y, int xx, int yy, String[][] g)
		{
			x1 = x;
			y1 = y;
			x2 = xx;
			y2 = yy;
			grid = g;
		}
		
		public String toString()
		{
			String x = "";
			for(String[] i : grid) x += Arrays.toString(i) + "\n";
			return x;
		}
	}


}
