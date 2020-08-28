import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class cbarn 
{

	static int n;
	
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("cbarn.in"));
		FileWriter out = new FileWriter(new File("cbarn.out"));

		n = in.nextInt();
		
		int[] barn = new int[n];
		for(int i = 0; i < n; i++)
		{
			barn[i] = in.nextInt();
		}
		
		int a = find(barn);
		
		in.close();
		System.out.println(a);
		out.write(a + "\n");
		out.close();
	}
	
	static int find(int[] barn)
	{
		int smallest = Integer.MAX_VALUE;
		Queue<Integer> q = new LinkedList<Integer>();
		
		
		
		for(int start = 0; start < n; start++)
		{
			int dist = 0;
			boolean[] visited = new boolean[n];
			int i = start;
			
			while(true)
			{
				if(i >= n)
				{
					boolean[] temparr = new boolean[n];
					Arrays.fill(temparr, true);
					if(!Arrays.equals(temparr, visited)) 
						i = 0;
					else break;
				}


				for(int j = 0; j < barn[i]; j++) // works
				{
					if(!visited[i]) q.add(i);
				}
				if(!visited[i] && !q.isEmpty()) 
				{
					visited[i] = true;
					int temp = q.poll();
					if(i >= temp) 
						dist += (i - temp) * (i - temp);
					else
						dist += (n - (temp - i)) * (n - (temp - i));
				}
				i++;
			}
			
			if(dist < smallest) 
				smallest = dist;
		}
		
		return smallest;
	}

}
