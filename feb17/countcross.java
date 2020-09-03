
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

public class countcross {
	
	static int notdistant = 0;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(new File("countcross.in")));
		FileWriter bw = new FileWriter(new File("countcross.out"));
		String[] input = br.readLine().split(" ");
		int n = Integer.valueOf(input[0]);
		int k = Integer.valueOf(input[1]);
		int r = Integer.valueOf(input[2]);
		int[][] cows = new int[k][2];
		ArrayList<int[][]> pairs = new ArrayList<int[][]>();

		LinkedList<int[]> edges[][] = new LinkedList[n][n];
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				edges[i][j] = new LinkedList<int[]>();
			}
		}
		
		//all adjacencies linkedlist
		for(int x = 0; x < n; x++)
			for(int y = 0; y < n; y++)
			{
				//left
				if(!(x - 1 < 0)) edges[x][y].add(new int[] {x - 1, y});
				
				//right
				if(!(x + 1 >= n)) edges[x][y].add(new int[] {x + 1, y});

				//up
				if(!(y - 1 < 0)) edges[x][y].add(new int[] {x, y - 1});

				//down
				if(!(y + 1 >= n))edges[x][y].add(new int[] {x, y + 1});
				
			}
		
		System.out.println();
			
		//removing roads
		for(int i = 0; i < r; i++)
		{
			String[] a = br.readLine().split(" ");
			int b = Integer.valueOf(a[0]) - 1;
			int c = Integer.valueOf(a[1]) - 1;
			int d = Integer.valueOf(a[2]) - 1;
			int e = Integer.valueOf(a[3]) - 1;
			
			for(int ab = 0; ab < edges[b][c].size(); ab++)
			{
				try
				{
					if(Arrays.equals(edges[b][c].get(ab), new int[] {d, e}))
					{
						edges[b][c].remove(ab);
						break;
					}
				}
				catch(Exception IndexOutOfBounds) {};

			}
			for(int ab = 0; ab < edges[d][e].size(); ab++)
			{
				try 
				{
					if(Arrays.equals(edges[d][e].get(ab), new int[] {b, c})) 
					{
						edges[d][e].remove(ab);
						break;
					}
				}
				catch(Exception IndexOutOfBounds) {};
			}
			
			
//			edges[b][c].remove(new int[] {d, e});
//			edges[d][e].remove(new int[] {b, c});
		}
		
		//reading cows
		for(int i = 0; i < k; i++)
		{
			String[] a = br.readLine().split(" ");
			int b = Integer.valueOf(a[0]);
			int c = Integer.valueOf(a[1]);
			cows[i] = new int[] {b - 1, c - 1};
		}
		
		//finding all pairs
		int[][] visitedpairs = new int[k][k];
		for(int i = 0; i < k; i++)
		{
			for(int j = 0; j < k; j++)
			{
				if (i==j) continue;
				else if(visitedpairs[i][j] == 1 || visitedpairs[j][i] == 1) continue;
				else
				{
					visitedpairs[i][j] = 1;
					visitedpairs[j][i] = 1;
				}
				pairs.add(new int[][] {cows[i], cows[j]});
			}
			
		}
		
		//compute distant pairs
		
		boolean[][] visited = new boolean[n][n];
		int i = 0;
		while(true)
		{
			visited[pairs.get(i)[0][0]][pairs.get(i)[0][1]] = true;
			distant(pairs.get(i)[0], edges, visited);
			if(visited[pairs.get(i)[1][0]][pairs.get(i)[1][1]] == true) 
				notdistant++;
			try{
				
				while(Arrays.equals(pairs.get(i)[0], pairs.get(i + 1)[0]))
				{
					if(visited[pairs.get(i+1)[1][0]][pairs.get(i+1)[1][1]]) 
					{
						notdistant++;
					}
					else 
					{	
//						break;
					}	
					i++;
				}
				if(!Arrays.equals(pairs.get(i)[0], pairs.get(i + 1)[0])) i++;
			}
			catch(Exception IndexOutOfBounds) {
				break;
			}
			for(int a = 0; a < visited.length; a++) Arrays.fill(visited[a], false);;
		}
		
		System.out.println(pairs.size() - notdistant);
		
		bw.write((pairs.size() - notdistant) + "\n");
		bw.close();
		br.close();
		
	}
	
	static void distant(int[] start, LinkedList<int[]> adj[][], boolean[][] visited)
	{
		for(int[] adjnode: adj[start[0]][start[1]])
		{
			if(visited[adjnode[0]][adjnode[1]]) continue;
			visited[adjnode[0]][adjnode[1]] = true;
			
//			if(Arrays.equals(adjnode, finish)) 
//				notdistant ++;
			distant(adjnode, adj, visited);
		}
		return;
	}
}
