import java.io.*;
import java.util.*;

public class cownomics 
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("C:\\temp\\cownomics.in"));
		FileWriter bw = new FileWriter(new File("cownomics.out"));
		
		String[] a = in.readLine().split(" ");
		int n = Integer.parseInt(a[0]);
		int m = Integer.parseInt(a[1]);
		
		HashMap<String, String> spotty = new HashMap<String, String>();
		
		for(int i = 0; i < n; i++)
		{
			String[] curr = in.readLine().split("");
			for(int j = 0; j < m; j++)
			{
				for(int k = 0; k < m; k++)
				{
					if(j == k) continue;
					for(int l = 0; l < m; l++)
					{
						if(k == l) continue;
						spotty.put(String.valueOf(j) + String.valueOf(k) + String.valueOf(l), curr[j] + curr[k] + curr[l]);
					}
				}
			}
		}
		
		System.out.println();
	
	}

}
