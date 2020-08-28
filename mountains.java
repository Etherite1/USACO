
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class mountains 
{

	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("mountains.in"));
		FileWriter out = new FileWriter(new File("mountains.out"));
		
		int n = in.nextInt();
		
		
		int[][] basepoints = new int[n][2];
		
		for(int i = 0; i < n; i++)
		{
			int x = in.nextInt();
			int y = in.nextInt();

			basepoints[i][0] = x - y;
			basepoints[i][1] = x + y;
		}

		Arrays.sort(basepoints, (a, b) -> compare(a, b));

		int max = -1;
		int vis = 0;
		
		for(int i = 0; i < basepoints.length; i++)
		{
			if(basepoints[i][1] > max) 
			{
				max = basepoints[i][1];
				vis++;
			}
		}
		
		out.write(vis + "\n");
		out.close();
		
		
		
//		int temp = n;
//		
//		for(int i = 0; i < n; i++)
//		{
//			if(basepoints[i][2] == -1) continue;
//			for(int j = 0; j < n; j++)
//			{
//				if(i==j) continue;
//				if(basepoints[j][2] == -1)
//					continue;
//				
//				if(basepoints[j][0] >= basepoints[i][0] && basepoints[j][1] <= basepoints[i][1])
//				{
//					temp--;
//					basepoints[j][2] = -1;
//				}
//
//			}
//		}
//		System.out.println(temp);
//		out.write(temp + "\n");
//		out.close();
//		in.close();

	}
	
	static int compare(int[] x, int[] y)
	{
		if(x[0] == y[0]) return y[1] - x[1];
		else return x[0] - y[0];
	}

}
