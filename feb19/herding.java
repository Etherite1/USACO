import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class herding 
{

	static int n;
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("herding.in"));
		FileWriter out = new FileWriter("herding.out");
		
		n = Integer.parseInt(in.readLine());
		
		int[] cows = new int[n];
		for(int i = 0; i < n; i++)
			cows[i] = Integer.parseInt(in.readLine());
		
		Arrays.sort(cows);
		
		int max = Math.max(cows[n - 2] - cows[0], cows[n - 1] - cows[1]) - (n - 2);
		
		out.write(min(cows) + "\n" + max + "\n");
		out.close();
	}
	
	static int min(int[] cows)
	{
		if(cows[n - 2] - cows[0] == n - 2 && cows[n - 1] - cows[n - 2] > 2) return 2;
		if(cows[n - 1] - cows[1] == n - 2 && cows[1] - cows[0] > 2) return 2;
		int temp = 0;
		int large = 0;
		for(int i = 0; i < n; i++)
		{
			while(temp < n - 1 && cows[temp + 1] - cows[i] <= n - 1) temp++;
			large = Math.max(large, temp - i + 1);
		}
		
		return n - large;
	}

}
