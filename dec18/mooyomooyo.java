
import java.util.*;
import java.io.*;

public class mooyomooyo {
	
	static int n, k;
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("mooyomooyo.in"));
		FileWriter out = new FileWriter("mooyomooyo.out");
		
		String[] asdf = in.readLine().split(" ");
		n = Integer.parseInt(asdf[0]);
		k = Integer.parseInt(asdf[1]);
		
		String[][] input = new String[n][10];
		int[][] grid = new int[n][10];
		
		for(int i = 0; i < n; i++) 
			input[i] = in.readLine().split("");
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < 10; j++)
				grid[i][j] = Integer.parseInt(input[i][j]);
		
		while(true)
		{
			boolean x = ff(grid);
			if(!x) break;
			drop(grid);
		}
		
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				out.write(String.valueOf(grid[i][j]));
			}
			out.write("\n");
		}
		out.close();
		in.close();
		
		
	}
	
	static void drop(int[][] grid)
	{
		for(int i = n - 1; i >= 0; i--)
		{
			for(int j = 0; j < 10; j++)
			{
				if(grid[i][j] > 0)
				{
					int x = i;
					while(true)
					{
						if(x + 1 >= n)
						{
							break;
						}
						else 
						{
							if(!(grid[x + 1][j] == 0)) break;
							grid[x + 1][j] = grid[x][j];
							grid[x][j] = 0;
							x++;
						}
					}
				}
			}
		}
	}
	
	static boolean ff(int[][] grid)
	{
		boolean[][] visited = new boolean[n][10];
		Queue<int[]> q = new LinkedList<int[]>();
		ArrayList<comp> comps = new ArrayList<comp>();
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				if(visited[i][j] || grid[i][j] == 0) continue;
				comp currcomp = new comp();
				q.add(new int[] {i, j});
				visited[i][j] = true;
				
				while(!q.isEmpty()) 
				{
					int[] curr = q.poll();
					currcomp.cells.add(curr);
					if(!(curr[0] - 1 < 0))
					{
						if(grid[curr[0]][curr[1]] == grid[curr[0] - 1][curr[1]])
						{
							if(!(visited[curr[0] - 1][curr[1]]))
							{
								visited[curr[0] - 1][curr[1]] = true;
								q.add(new int[] {curr[0] - 1, curr[1]});
							}
						}
					}
					if(!(curr[0] + 1 >= n))
					{
						if(grid[curr[0]][curr[1]] == grid[curr[0] + 1][curr[1]])
						{
							if(!(visited[curr[0] + 1][curr[1]]))
							{
								visited[curr[0] + 1][curr[1]] = true;
								q.add(new int[] {curr[0] + 1, curr[1]});
							}
						}
					}
					if(!(curr[1] - 1 < 0))
					{
						if(grid[curr[0]][curr[1] - 1] == grid[curr[0]][curr[1]])
						{
							if(!(visited[curr[0]][curr[1] - 1])) 
							{
								visited[curr[0]][curr[1] - 1] = true;
								q.add(new int[] {curr[0], curr[1] - 1});
							}
							
						}
					}
					if(!(curr[1] + 1 >= 10))
					{
						if(grid[curr[0]][curr[1] + 1] == grid[curr[0]][curr[1]])
						{
							if(!(visited[curr[0]][curr[1] + 1]))
							{
								visited[curr[0]][curr[1] + 1] = true;
								q.add(new int[] {curr[0], curr[1] + 1});
							}
						}
					}
					
				}
				
				comps.add(currcomp);
				
			}
		}
		
		boolean foundone = false;
		
		for(comp i : comps)
		{
			if(i.cells.size() >= k)
			{
				foundone = true;
				for(int[] j : i.cells)
				{
					grid[j[0]][j[1]] = 0;
				}
			}
		}
		
		return foundone;
		
	}

	
}

class comp
{
	ArrayList<int[]> cells = new ArrayList<int[]>();
	
	public comp() {}
}


