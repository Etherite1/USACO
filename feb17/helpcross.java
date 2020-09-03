import java.util.*;
import java.io.*;


public class helpcross
{

	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("helpcross.in"));
		FileWriter out = new FileWriter("helpcross.out");
		
		int c = in.nextInt();
		int n = in.nextInt();
		int[] chickens = new int[c];
		int[][] cows = new int[n][2];
		
		for(int i = 0; i < c; i++)
		{
			chickens[i] = in.nextInt();
		}
		
		Arrays.sort(chickens);
		
		for(int i = 0; i < n; i++)
		{
			cows[i][0] = in.nextInt();
			cows[i][1] = in.nextInt();
		}
		
		Arrays.sort(cows, (a, b) -> compare(a, b));
		
		boolean[] pcow = new boolean[n];
		int pairs = 0;
		
//		for(int[] i : cows) System.out.println(i[0] + " " + i[1]);
		
		for(int i : chickens) System.out.println(i);
		
		for(int i = 0; i < c; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(pcow[j]) continue;
				if(chickens[i] >= cows[j][0] && chickens[i] <= cows[j][1])
				{
					pcow[j] = true;
					pairs++;
					break;
				}
				
			}
		}
		System.out.println(pairs);
		out.write(pairs + "\n");
		out.close();
	}
	
	static int compare(int[] a, int[] b)
	{
//		if(a[0] == b[0]) return a[1] - b[1];
//		else return a[0] - b[0];
		if((a[1] - a[0]) == (b[1] - b[0])) return a[0] - b[0];
		return (a[1] - a[0]) - (b[1] - b[0]);
	}

}
