

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

public class moocast {
	
	ArrayList<Integer> cowcount = new ArrayList<Integer>();
	static int count;


	public static void main(String[] args) throws Exception {
		String filename = "moocast.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);

		String filename2 = "moocast.out";
		File file2 = new File(filename2);
		FileWriter bw = new FileWriter(file2);
		
		String s = br.readLine();
		int n = Integer.valueOf(s);
		int[][] cows = new int[n][3];
		
		int[] visited = new int[n];
		Arrays.fill(visited, 0);
		
		LinkedList<Integer> edges[] = new LinkedList[n];
		for(int i = 0; i < edges.length; i++) 
		{
			edges[i] = new LinkedList<Integer>();
		}
		
		for(int i = 0; i < n; i++) {
			s = br.readLine();
			String[] a = s.split(" ");
			cows[i][0] = Integer.valueOf(a[0]);
			cows[i][1] = Integer.valueOf(a[1]);
			cows[i][2] = Integer.valueOf(a[2]);
			edges[i] = new LinkedList<Integer>();
		}
		
		for(int i = 0; i < cows.length; i++)
		{
			int[] cow1 = cows[i];
			for(int j = 0; j < cows.length; j++)
			{
				int[] cow2 = cows[j];
				if(within(cow1, cow2)) 
				{
					edges[i].add(j);
				}
			}
		}

		System.out.println();
		int max = 0;
		
		for(int i = 0; i < cows.length; i++)
		{
			int current = dfs(edges, i, visited);
			if(current > max) max = current;
			Arrays.fill(visited, 0);
			count = 0;
		}
		
		bw.write(max + "\n");
		bw.close();
		br.close();
		
	}
	
	public static int dfs(LinkedList<Integer>[] adj, int start, int[] visited)
	{
		for(int adjnode : adj[start]) 
		{
			if(visited[adjnode] == 1) continue;
			visited[adjnode] = 1;
			count++;
    		dfs(adj, adjnode, visited);
		}
		return count;
	}
	
	public static boolean within(int[] cow1, int[] cow2) {
		if((Math.pow(cow2[0] - cow1[0], 2) + Math.pow(cow2[1] - cow1[1], 2)) <= Math.pow(cow1[2], 2)) return true;
		else return false;
	}

}
