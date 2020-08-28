import java.io.*;
import java.util.*;

public class where 
{
	static int n;
	static ArrayList<int[][]> pcls = new ArrayList<int[][]>();
	static ArrayList<int[][]> fin = new ArrayList<int[][]>();
	static ArrayList<String[][]> allcurr = new ArrayList<String[][]>();
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("C:\\temp\\where.in"));
		FileWriter out = new FileWriter(new File("where.out"));
		
		n = Integer.parseInt(in.readLine());
		
		String[][] grid = new String[n][n];

		for(int i = 0; i < n; i++)
		{
			grid[i] = in.readLine().split("");
		}
		
		for(int a = 0; a < n; a++)
			for(int b = 0; b < n; b++)
				for(int c = a; c < n; c++)
					for(int d = b; d < n; d++)
					{
						find(grid, new int[] {a, b}, new int[] {c, d});
					}
		
		int num = 0;
		for(int i = 0; i < pcls.size(); i++)
			if(ismax(i)) 
			{
				num++;
				fin.add(pcls.get(i));
			}
		
		for(String[][] i : allcurr)
		{
			for(String[] j : i)
				System.out.println(Arrays.toString(j));
			
			System.out.println();
		}
		
		System.out.println(num);
//		out.write(num + "\n");
//		out.close();
		in.close();
	}
	
	static boolean within(int[][] a, int[][] b)
	{
		if(a[1][1] <= b[1][1] && a[1][0] <= b[1][0] && a[0][0] >= b[0][0] && a[0][1] >= b[0][1]) return true;
		return false;
	}
	
	static boolean ismax(int x)
	{
		for(int i = 0; i < pcls.size(); i++)
		{
			if(within(pcls.get(x), pcls.get(i)) && i != x)
				return false;
		}
		return true;
	}

	
	static boolean find(String[][] grid, int[] a, int[] b)
	{
		int x = 0;
		int y = 0;
		
		String[][] curr = new String[b[0] - a[0] + 1][b[1] - a[1] + 1];
		for(int i = a[0]; i <= b[0]; i++)
		{
			for(int j = a[1]; j <= b[1]; j++)
			{
				curr[x][y] = grid[i][j];
				y++;
			}
			x++;
			y = 0;
		}
		HashSet<String> aa = new HashSet<String>();
		
		for(String[] i : curr)
			for(String j : i)
			{
				if(!aa.contains(j)) aa.add(j);

			}
		if(aa.size() != 2) return false;
		
		if(curr.length == 0) return false;
		if(curr[0].length == 0) return false;
		allcurr.add(curr);
		if(fill(curr)) 
		{
			pcls.add(new int[][] {a, b});
			return true;
		}
		else return false;
	}
	
	static boolean fill(String[][] curr)
	{
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		Queue<int[]> q = new LinkedList<int[]>();
		boolean[][] visited = new boolean[curr.length][curr[0].length];
		
		for(int i = 0; i < curr.length; i++)
		{
			for(int j = 0; j < curr[0].length; j++)
			{
				if(visited[i][j]) continue;
				if(!map.containsKey(curr[i][j])) map.put(curr[i][j], 1);
				else map.put(curr[i][j], map.get(curr[i][j]) + 1);
				int[] start = new int[] {i, j};
				visited[i][j] = true;
				q.add(start);
				while(!q.isEmpty())
				{
					int[] temp = q.poll();
					if(temp[0] - 1 >= 0)
						if(!visited[temp[0] - 1][temp[1]] && curr[temp[0] - 1][temp[1]].equals(curr[temp[0]][temp[1]]))
						{
							q.add(new int[] {temp[0] - 1, temp[1]});
							visited[temp[0] - 1][temp[1]] = true;
						}
					if(temp[0] + 1 < curr.length)
						if(!visited[temp[0] + 1][temp[1]] && curr[temp[0] + 1][temp[1]].equals(curr[temp[0]][temp[1]]))
						{
							q.add(new int[] {temp[0] + 1, temp[1]});
							visited[temp[0] + 1][temp[1]] = true;
						}
					if(temp[1] - 1 >= 0)
					{
						if(!visited[temp[0]][temp[1] - 1] && curr[temp[0]][temp[1] - 1].equals(curr[temp[0]][temp[1]]))
						{
							q.add(new int[] {temp[0], temp[1] - 1});
							visited[temp[0]][temp[1] - 1] = true;
						}
					}
					if(temp[1] + 1 < curr[0].length)
					{
						if(!visited[temp[0]][temp[1] + 1] && curr[temp[0]][temp[1] + 1].equals(curr[temp[0]][temp[1]]))
						{
							q.add(new int[] {temp[0], temp[1] + 1});
							visited[temp[0]][temp[1] + 1] = true;
						}
					}
				}
			}
		}
		boolean one = false;
		boolean two = false;

		for(int value : map.values()) 
		{
			if(value == 1) one = true;
			if(value == 2) two = true;
		}

		if(one && two) 
		{
			return true;
		}
		else return false;
	}

}
