import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.IntSummaryStatistics;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class distant 
{
	
	static int a;
	static int b;
	static int n;

	public static void main(String[] args) throws Exception
	{
		
		BufferedReader br = new BufferedReader(new FileReader(new File("distant.in")));
		FileWriter bw = new FileWriter(new File("distant.out"));
		
		String[] ipt = br.readLine().split(" ");
		n = Integer.valueOf(ipt[0]);
		a = Integer.valueOf(ipt[1]);
		b = Integer.valueOf(ipt[2]);
		
		LinkedList<int[]> edges[][] = new LinkedList[n][n];
		String[][] pasture = new String[n][n];
		
		for(int i = 0; i < n; i++)
		{
			String[] abc = br.readLine().split("");
			pasture[i] = abc;
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

		long start = System.nanoTime();
		int largest = -1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				int large = longest(edges, new int[] {i, j}, pasture);
				if(large > largest) largest = large;
			}
		long end = System.nanoTime();		
		System.out.println(end - start);
		System.out.println(largest);
		
		bw.write(largest + "\n");
		bw.close();
		br.close();

	}
	
	static int longest(LinkedList<int[]>[][] adj, int[] start, String[][] pasture)
	{
		int[][] dist = new int[n][n];
		for(int[] i : dist)
			Arrays.fill(i, Integer.MAX_VALUE);
		
		
		
		PriorityQueue<Node> q = new PriorityQueue<Node>(); //create vertex set Q

		q.add(new Node(start[0], start[1], 0));
		
		dist[start[0]][start[1]] = 0; //dist[source] = 0
		
		while(!q.isEmpty()) //while Q is not empty:
		{
			Node u = q.poll();
			if(u.d > dist[u.r][u.c]) continue;
			
			for(int[] adjnode: adj[u.r][u.c]) // for each neighbour v of u
			{
				int alt = 0;
				if(pasture[u.r][u.c].equals(pasture[adjnode[0]][adjnode[1]])) //loop through to check weight
				{
					alt = dist[u.r][u.c] + a; //same parentheses
				}
				else alt = dist[u.r][u.c] + b; //different parentheses
				// alt = dist[u] + length(u, v)
				
				if(alt < dist[adjnode[0]][adjnode[1]]) 
				{
					dist[adjnode[0]][adjnode[1]] = alt; 
					q.offer(new Node(adjnode[0], adjnode[1], alt));
					
				}	// if alt < dist[v]: dist[v] = alt
			}
		}
		
		int temp = -1;
		for(int i = 0; i < dist.length; i++)
			for(int j = 0; j < dist[i].length; j++)
			{
				if(dist[i][j] > temp && dist[i][j] != Integer.MAX_VALUE) temp = dist[i][j];
			}
		
		return temp;
		
	}
	

}

class Node implements Comparable<Node>
{
	int r;
	int c;
	int d;
	
	public Node(int row, int column, int dist)
	{
		r = row;
		c = column;
		d = dist;
	}
	
	public int compareTo(Node other)
	{
		return (d - other.d);
	}
	
}
