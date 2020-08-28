
import java.util.*;
import java.io.*;


public class leftout {

	static int n;
	static int[][] grid;
	static int[] rows, columns;
	static ArrayList<int[]> a = new ArrayList<int[]>();
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("leftout.in"));
		FileWriter out = new FileWriter("leftout.out");
		
		n = Integer.parseInt(in.readLine());
		grid = new int[n][n];
		
		for(int i = 0; i < n; i++)
		{
			String[] row = in.readLine().split("");
			for(int j = 0; j < n; j++)
			{
				if(row[j].equals("R")) grid[i][j] = 1;
				else grid[i][j] = 0;
			}
		}
		rows = new int[n];
		columns = new int[n];
		for(int row = 0; row < n; row++)
		{
			for(int i : grid[row])
				if(i == 1) rows[row]++;
		}
		
		find();
		
		if(a.size() == 0) out.write("-1\n");
		else
		{
			out.write((a.get(0)[0] + 1) + " " + (a.get(0)[1] + 1) + "\n");
		}
		
		out.close();
		in.close();

		System.out.println();
		
	}
	
	static void fliprow(int row)
	{
		rows[row] = n - rows[row];
		for(int c = 0; c < n; c++)
		{
			if(grid[row][c] == 1) 
				columns[c] -= 1;
			else columns[c] += 1;
			
			grid[row][c] = 1 - grid[row][c];
		}
		
	}
	
	static void flipcol(int col)
	{
		columns[col] = n - columns[col];
		for(int r = 0; r < n; r++)
		{
			if(grid[r][col] == 1)
				rows[r] -= 1;
			else rows[r] += 1;
			
			grid[r][col] = 1 - grid[r][col];
		}
	}
	
	
	
	static void find()
	{
		for(int i = 0; i < n; i++)
		{
			if(grid[i][0] == 0) fliprow(i);
		}
		for(int i = 0; i < n; i++)
		{
			if(grid[0][i] == 0) flipcol(i);
		}
		
		if(case1()) return;
		else if(case2()) return;
		else case3();
		
		
	}
	
	static boolean case1()
	{
		for(int i = 1; i < n; i++)
		{
			for(int j = 1; j < n; j++)
			{
				if(grid[i][j] != 0) 
				{
					return false;
				}
			}
		}
		a.add(new int[] {0, 0});
		return true;
	}
	
	static boolean case2()
	{
		for(int i = 0; i < n; i++) //rows
		{
			int x = 0;
			for(int j = 0; j < n; j++)
			{
				if(grid[i][j] == 0) x++;
				
			}
			if(x == n - 1) 
			{
				a.add(new int[] {i, 0});
				return true;
			}
		}
		
		for(int i = 0; i < n; i++)
		{
			int x = 0;
			for(int j = 0; j < n; j++)
			{
				if(grid[j][i] == 0) x++;
				
			}
			if(x == n - 1) 
			{
				a.add(new int[] {0, i});
				return true;
			}
		}


		return false;
	}
	
	static void case3()
	{
		ArrayList<int[]> list = new ArrayList<int[]>();
		for(int i = 1; i < n; i++)
		{
			for(int j = 1; j < n; j++)
			{
				if(grid[i][j] == 0) 
				{
					list.add(new int[] {i, j});
				}
			}
		}
		if(list.size() == 1) 
		{
			a.add(list.get(0));
		}
	}

}

