
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class div7 
{

	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("div7.in"));
		FileWriter out = new FileWriter(new File("div7.out"));
		int n = in.nextInt();
		
		long[] psums = new long[n];
		psums[0] = 0;
		psums[1] = in.nextInt();
		for(int i = 2; i < n; i++)
		{
			psums[i] = (psums[i - 1] + in.nextInt());
		}
		
		int[] first = new int[7];
		int[] last = new int[7];
		
		boolean[] visited = new boolean[7];
		
		for(int i = 0; i < psums.length; i++)
		{
			int temp = (int) (psums[i] % 7);
			if(!visited[temp])
			{
				visited[temp] = true;
				first[temp] = i;
			}
		}
		
		Arrays.fill(visited, false);
		
		for(int i = psums.length - 1; i >= 0; i--)
		{
			int temp = (int) (psums[i] % 7);
			if(!visited[temp])
			{
				visited[temp] = true;
				last[temp] = i;
			}
		}
		
		int largest = 0;
		
		for(int i = 0; i < 7; i++)
		{
			if(last[i] - first[i] > largest) largest = last[i] - first[i];
		}
		
		
		out.write(largest + "\n");
		out.close();
		in.close();
	}
	
}
