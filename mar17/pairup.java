import java.io.*;
import java.util.*;

public class pairup 
{

	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("pairup.in"));
		FileWriter out = new FileWriter("pairup.out");
		
		int n = in.nextInt();
		
		int[][] list = new int[n][2];

		for (int i = 0; i < n; i++) 
		{
			int a = in.nextInt();
			int b = in.nextInt();
			list[i][0] = b;
			list[i][1] = a;
		}
		
		Arrays.sort(list, (a, b) -> compare(a, b));

		int curr = -1;
		
		int i = 0;
		int j = n - 1;
		while(i <= j)
		{
			int x = Math.min(list[i][1], list[j][1]);
			if(i == j) x/=2;
			
			list[i][1] -= x;
			list[j][1] -= x;
			
			curr = Math.max(curr, list[i][0] + list[j][0]);
			
			if(list[i][1] == 0) i++;
			if(list[j][1] == 0) j--;
			
		}

		
		System.out.println(curr);
		out.write(curr + "\n");
		out.close();


	}	
	
	static int compare(int[] a, int[] b)
	{
		if(b[0] == a[0]) return a[1] - b[1];
		else return a[0] - b[0];
	}
}
