
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class mootube {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(new File("mootube.in")));
		FileWriter bw = new FileWriter(new File("mootube.out"));
		String[] input = br.readLine().split(" ");
		int n = Integer.valueOf(input[0]);
		int q = Integer.valueOf(input[1]);

		LinkedList<Integer> edges[] = new LinkedList[n + 1];
		for(int i = 0; i < edges.length; i++) 
		{
			edges[i] = new LinkedList<Integer>();
		}
		int[][] matrix = new int[n + 1][n + 1];

		for(int i = 0; i < n - 1; i++)
		{
			input = br.readLine().split(" ");
			int a = Integer.valueOf(input[0]);
			int b = Integer.valueOf(input[1]);
			int c = Integer.valueOf(input[2]);
			
			edges[a].add(b);
			edges[b].add(a);
			matrix[a][b] = c;
			matrix[b][a] = c;
		}
		
		int[] relevances = new int[n + 1];
		int[] visited = new int[n + 1];

		for(int i = 0; i < q; i++)
		{
			input = br.readLine().split(" ");
			int k = Integer.valueOf(input[0]);
			int v = Integer.valueOf(input[1]);
			
			relevances[v] = -1;
			visited[v] = 1;
			compute2(k, v, edges, matrix, relevances, visited);
			int count = 0;
			
			for(int j = 1; j < relevances.length; j++)
			{
				if(relevances[j] >= k) count++;
			}
			
			bw.write(count + "\n");
			Arrays.fill(relevances, 0);	
			Arrays.fill(visited, 0);
		}
		bw.close();
		br.close();
	}
	
	static void compute(int k, int v, LinkedList<Integer>[] adj, int[][] matrix, int[] relevances, int[] visited)
	{
		for(int adjnode : adj[v]) 
		{
			if(visited[adjnode] == 1) continue;
			visited[adjnode] = 1;
			if(matrix[v][adjnode] < k) continue;
			if(relevances[v] < matrix[v][adjnode] && relevances[v] >= 0) relevances[adjnode] = relevances[v];
			else relevances[adjnode] = matrix[v][adjnode];
			
    		compute(k, adjnode, adj, matrix, relevances, visited);
		}
		
		return;
	}
	
	static void compute2(int k, int v, LinkedList<Integer>[] adj, int[][] matrix, int[] relevances, int[] visited)
	{
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(v);
		while(queue.size() > 0)
		{
			int a = queue.peek();
			for(int adjnode: adj[a])
			{
				if(matrix[a][adjnode] < k) continue;
				if(visited[adjnode] == 1) continue;
				
				visited[adjnode] = 1;

				queue.add(adjnode);
				if(relevances[a] < matrix[a][adjnode] && relevances[a] >= 0) 
					relevances[adjnode] = relevances[a];
				else 
					relevances[adjnode] = matrix[a][adjnode];
			}
			queue.poll();
		}
	}
}
