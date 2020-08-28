
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class pails 
{
	static int x, y, k, m;
	static int mindiff = Integer.MAX_VALUE;
	static boolean[][] visited;
	
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("pails.in"));
		FileWriter out = new FileWriter(new File("pails.out"));
		
	    x = in.nextInt();
		y = in.nextInt();
		k = in.nextInt();
		m = in.nextInt();
//		
//		x = 14;
//		y = 50;
//		k = 2;
//		m = 32;
//		
		visited = new boolean[x + 1][y + 1];
		
		pour2();
		
		for(int i = 0; i < visited.length; i++)
		{
			for(int j = 0; j < visited[i].length; j++)
			{
				if(visited[i][j])
				{
					if(Math.abs(m - (i + j)) < mindiff) mindiff = Math.abs(m - (i + j));
				}
					
			}
		}
		
		System.out.println(mindiff);
		out.write(mindiff + "\n");
		out.close();
	}
	
	static void pour2()
	{
		visited[0][0] = true;
		for(int op = 0; op < k; op++)
		{
			boolean[][] temp = new boolean[x + 1][y + 1];
			for(int i = 0; i < visited.length; i++)
			{
				for(int j = 0; j < visited[i].length; j++)
				{
					if(!visited[i][j]) continue;
					temp[i][j] = true;
					temp[0][j] = true;
					temp[i][0] = true;
					temp[x][j] = true;
					temp[i][y] = true;
					int pourtoy = Math.min(i, y - j);
					temp[i - pourtoy][j + pourtoy] = true;
					int pourtox = Math.min(j, x - i);
					temp[i + pourtox][j - pourtox] = true;
					
				}
			}
			visited = temp;
		}
		
		System.out.println();
		
	}
}
