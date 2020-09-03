
import java.io.*;
import java.util.*;

public class gymnastics {
	
	static int n, k;
	static int[][] cows = new int[10][20];

	public static void main(String[] args) throws Exception 
	{
		// TODO Auto-generated method stub
		Scanner in = new Scanner(new File("gymnastics.in"));
		FileWriter out = new FileWriter("gymnastics.out");
		k = in.nextInt();
		n = in.nextInt();
		for (int i = 0; i < k; i++)
			for (int j = 0; j < n; j++)
				cows[i][j] = in.nextInt();
		
		int ans = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				if (better(i, j)) ans++;
			}
		}
		
		System.out.println(ans);
		out.write(ans + "\n");
		out.close();
	}	
	
	static boolean better(int a, int b)
	{
		for (int i = 0; i < k; i++)
		{
			int ascore = 0;
			int bscore = 0;
			for(int j = 0; j < n; j++)
			{
				if(cows[i][j] == a) ascore = j;
				if(cows[i][j] == b) bscore = j;
			}
			if(ascore > bscore) return false;
		}
		return true;
	}

}
