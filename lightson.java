import java.io.File;
import java.io.FileWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class lightson 
{
	static int n;

	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("lightson.in"));
		FileWriter out = new FileWriter(new File("lightson.out"));
		
		n = in.nextInt();
		int m = in.nextInt();
		
		LinkedList<int[]> lights[][] = new LinkedList[n][n];
		LinkedList<int[]> edges[][] = new LinkedList[n][n];
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				lights[i][j] = new LinkedList<int[]>();
				edges[i][j] = new LinkedList<int[]>();
			}
		
		for(int i = 0; i < m; i++)
		{
			int[] temp = new int[4];
			temp[0] = in.nextInt();
			temp[1] = in.nextInt();
			temp[2] = in.nextInt();
			temp[3] = in.nextInt();
			lights[temp[0] - 1][temp[1] - 1].add(new int[] {temp[2] - 1, temp[3] - 1});
			
		}
		
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
				if(!(y + 1 >= n)) edges[x][y].add(new int[] {x, y + 1});
				
			}
		
		out.write(find(lights, edges) + "\n");
		out.close();
//		System.out.println(find(lights, edges));
		in.close();
		
		
	}

	static int find(LinkedList<int[]> lights[][], LinkedList<int[]> adj[][])
	{
		Queue<int[]> q = new LinkedList<int[]>();
		boolean[][] light = new boolean[n][n];
		boolean[][] visited = new boolean[n][n];
		light[0][0] = true;
		visited[0][0] = true;
		q.add(new int[] {0, 0});
		
		while(!q.isEmpty())
		{
			for(int[] lightswitch: lights[q.peek()[0]][q.peek()[1]]) // turn on the lights in current node
			{
				if(visited[lightswitch[0]][lightswitch[1]]) continue;
				light[lightswitch[0]][lightswitch[1]] = true;
				if(nextToVis(visited, lightswitch))
				{
					q.add(lightswitch);
					visited[lightswitch[0]][lightswitch[1]] = true;
				}
			}
			for(int[] adjnode: adj[q.peek()[0]][q.peek()[1]])
			{
				if(light[adjnode[0]][adjnode[1]] && !visited[adjnode[0]][adjnode[1]]) 
				{
					q.add(adjnode);
					visited[adjnode[0]][adjnode[1]] = true;
				}
			}
			q.poll();
		}
		
		int temp = 0;
		for(boolean[] i : light)
			for(boolean j : i)
				if(j) temp++;
				
		return temp;
	}
	
	static boolean nextToVis(boolean[][] visited, int[] node)
	{
		try
		{
			if(visited[node[0] - 1][node[1]]) return true;
		}
		catch(Exception IndexOutOfBounds) {}
		try 
		{
			if(visited[node[0] + 1][node[1]]) return true;
		}
		catch(Exception IndexOutOfBounds) {}
		try
		{	
			if(visited[node[0]][node[1] - 1]) return true;
		}
		catch(Exception IndexOutOfBounds) {}
		try
		{	
			if(visited[node[0]][node[1] + 1]) return true;
		}
		catch(Exception IndexOutOfBounds) {}
		
		return false;
	}
	
}
