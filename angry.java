import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class angry {

	static int n;
	static int k;
	
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("angry.in"));
		FileWriter out = new FileWriter(new File("angry.out"));
		
		n = in.nextInt();
		k = in.nextInt();
		
		int[] bales = new int[n];

		for(int i = 0; i < n; i++) bales[i] = in.nextInt();
		Arrays.sort(bales);
		
		int abc = find(bales);
		
		out.write(abc + "\n");
		out.close();
		in.close();

	}
	
	static int find(int[] bales)
	{
		boolean[] visited = new boolean[n];
		int ktemp = 0;
		for(int r = 1; r < Integer.MAX_VALUE; r++)
		{
			try
			{
				while(true)
				{
					int left = findleft(visited);
					int leftplusr = bales[left] + r;
					for(int i = left; i < bales.length; i++)
					{
						if(bales[i] <= leftplusr + r && bales[i] >= leftplusr - r && !visited[i])
						{
							visited[i] = true;
						}
						else break;
					}
					ktemp++;
					if(ktemp > k) break;
				}
				
			}
			catch(Exception IndexOutOfBounds) 
			{
				if(ktemp <= k) return r;
			}
			ktemp = 0;
			Arrays.fill(visited, false);
		}
		
		return -1;
	}
	
	static int findleft(boolean[] visited)
	{
		for(int i = 0; i < visited.length; i++)
			if(!visited[i]) return i;
		
		return -1;
	}

}
