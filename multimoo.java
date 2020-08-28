
import java.util.*;
import java.io.*;

public class multimoo 
{
	static int n;
	static int[][] grid;
	static LinkedList<int[]> edges[][];
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("C:\\temp\\multimoo.in"));
		FileWriter out = new FileWriter("multimoo.out");
		
		n = Integer.parseInt(in.readLine());
		grid = new int[n][n];
		for(int i = 0; i < n; i++) 
		{
			String[] s = in.readLine().split(" ");
			for(int j = 0; j < n; j++)
			{
				grid[i][j] = Integer.parseInt(s[j]);
			}
		}
		
		edges = new LinkedList[n][n];
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				edges[i][j] = new LinkedList<int[]>();
		
		for(int x = 0; x < n; x++)
			for(int y = 0; y < n; y++)
			{
				if(!(x - 1 < 0)) edges[x][y].add(new int[] {x - 1, y});
				if(!(x + 1 >= n)) edges[x][y].add(new int[] {x + 1, y});
				if(!(y - 1 < 0)) edges[x][y].add(new int[] {x, y - 1});
				if(!(y + 1 >= n))edges[x][y].add(new int[] {x, y + 1});
			}
		
		int part1 = ff();
		
		System.out.println(part1);
		
		int[][] unique = genunique();
		LinkedList<Integer>[] cadj = compress(unique); // compressed graph
		int part2 = teams(cadj);
		
		System.out.println(part2);
		out.write(part1 + "\n" + part2 + "\n");;
		out.close();
		in.close();
		
	}
	
	static int teams(LinkedList<Integer>[] adj) // O(n^3 * (n + m)) yikes.......
	{
		int maxsize = 0;
		Queue<Integer> q = new LinkedList<>();

		for(int i = 0; i < id; i++) 
		{
			for(int edge : adj[i])
			{
				if(label[i] == label[edge]) continue;
				/* for every pair of unique ids, perform bfs on each pair
				 * bfs: check if adjnode is one of the two labels (non unique grid), if it is then add to queue and increase sum by size of id
				 * if not break
				 * label array : id -> player number in non unique grid
				 */
				
				boolean[] visited = new boolean[id];
				int tempsize = 0;

				q.add(i);
				tempsize += sizes[i];
				visited[i] = true;
				while(!q.isEmpty())
				{
					int curr = q.poll();
					for(int adjnode : adj[curr])
					{
						if(visited[adjnode]) continue;
						if(label[i] == label[adjnode] || label[edge] == label[adjnode]) 
						{
							q.add(adjnode);
							tempsize += sizes[adjnode];
							visited[adjnode] = true;
						}
					}
				}

				maxsize = Math.max(maxsize, tempsize);
			}
		}
		return maxsize;
	}
	
	static int[] sizes, label;
	
	static LinkedList<Integer>[] compress(int[][] unique) // compresses unique id grid into a graph O(n^2)
	{
		LinkedList<Integer> adj[] = new LinkedList[id];
		for(int i = 0; i < adj.length; i++)
		{
			adj[i] = new LinkedList<>();
		}
		sizes = new int[id];
		label = new int[id];

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int curr = unique[i][j];
				label[curr] = grid[i][j];
				sizes[curr]++;
				if(i - 1 >= 0)
				{
					if(!adj[curr].contains(unique[i - 1][j]))
						adj[curr].add(unique[i - 1][j]);
				}
				if(i + 1 < n)
				{
					if(!adj[curr].contains(unique[i + 1][j]))
						adj[curr].add(unique[i + 1][j]);
				}
				if(j - 1 >= 0)
				{
					if(!adj[curr].contains(unique[i][j - 1])) 
						adj[curr].add(unique[i][j - 1]);
				}
				if(j + 1 < n)
				{
					if(!adj[curr].contains(unique[i][j + 1])) 
						adj[curr].add(unique[i][j + 1]);
				}
			}
		}
		for(int i = 0; i < adj.length; i++)
		{
			for(int j = 0; j < adj[i].size(); j++)
			{
				if(adj[i].get(j) == i)
				{
					adj[i].remove(j);
					break;
				}
			}
		}
		
		return adj;
	}
	
	static int id = 0;
	
	static int[][] genunique() //generates unique ids and puts them into a new grid O(n^2 * (n + m))
	{
		int[][] newgrid = new int[n][n];
		boolean[][] visited = new boolean[n][n];
		Queue<int[]> q = new LinkedList<int[]>();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				if(visited[i][j]) continue;
				q.add(new int[] {i, j});
				visited[i][j] = true;
				newgrid[i][j] = id;
				while(!q.isEmpty()) 
				{
					int[] curr = q.poll();
					newgrid[curr[0]][curr[1]] = id;
					for(int[] adjnode : edges[curr[0]][curr[1]])
						if(grid[curr[0]][curr[1]] == grid[adjnode[0]][adjnode[1]])
						{
							if(visited[adjnode[0]][adjnode[1]]) continue;
							visited[adjnode[0]][adjnode[1]] = true;
							q.add(adjnode);
						}
				}	
				id++;
			}
		
		return newgrid;
	}
	
	static int ff() //O(n^2 * (n + m))
	{
		
		boolean[][] visited = new boolean[n][n];
		Queue<int[]> q = new LinkedList<int[]>();
		int largest = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				if(visited[i][j]) continue;
				q.add(new int[] {i, j});
				visited[i][j] = true;
				int size = 0;
				while(!q.isEmpty()) 
				{
					int[] curr = q.poll();
					size++;
					for(int[] adjnode : edges[curr[0]][curr[1]])
						if(grid[curr[0]][curr[1]] == grid[adjnode[0]][adjnode[1]])
						{
							if(visited[adjnode[0]][adjnode[1]]) continue;
							visited[adjnode[0]][adjnode[1]] = true;
							q.add(adjnode);
						}
				}	
				largest = Math.max(size, largest);
			}
		
		return largest;
	}
	
	
	
	
	
	
}



