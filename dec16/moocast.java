import java.io.*;
import java.util.*;

public class moocast {
	
	static int n;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("moocast.in"));
		FileWriter bw = new FileWriter("moocast.out");
		
		n = Integer.valueOf(br.readLine());
		
		int[][] cows = new int[n][3];
		for(int i = 0; i < n; i++)
		{
			String[] s = br.readLine().split(" ");
			cows[i][0] = Integer.valueOf(s[0]);
			cows[i][1] = Integer.valueOf(s[1]);
			cows[i][2] = Integer.valueOf(s[2]);
		}
		LinkedList<Integer>[] edges = new LinkedList[n];
		for(int i = 0; i < n; i++) edges[i] = new LinkedList<>();
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(within(cows[i], cows[j])) edges[i].add(j);
			}
		}
		
		bw.write(bfs(edges) + "\n");
		bw.close();
		br.close();
		
	}
	
	static int bfs(LinkedList<Integer>[] edges)
	{
		int max = 0;
		for(int i = 0; i < n; i++)
		{
			Queue<Integer> q = new LinkedList<>();
			boolean[] visited = new boolean[n];
			visited[i] = true;
			q.add(i);
			int count = 0;
			while(!q.isEmpty())
			{
				int curr = q.poll();
				count++;
				for(int adjnode : edges[curr])
				{
					if(visited[adjnode]) continue;
					visited[adjnode] = true;
					q.add(adjnode);
				}
			}
			max = Math.max(max, count);
		}
		
		return max;
	}
	
	public static boolean within(int[] cow1, int[] cow2) {
		if((Math.pow(cow2[0] - cow1[0], 2) + Math.pow(cow2[1] - cow1[1], 2)) <= Math.pow(cow1[2], 2)) return true;
		else return false;
	}

}
