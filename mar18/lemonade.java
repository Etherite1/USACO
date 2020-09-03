import java.io.*;
import java.util.*;

public class lemonade 
{

	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new FileReader("C:\\temp\\lemonade.in"));
		FileWriter out = new FileWriter("lemonade.out");
		
		int n = in.nextInt();
		
		Integer[] cows = new Integer[n];
		for(int i = 0; i  < n; i++)
		{
			cows[i] = in.nextInt();
		}

		Arrays.sort(cows);
		
		int cownum = 0;
		
		for(int i = 0; i < n; i++)
		{
			if(cows[i] <= cownum) cownum++;
		}
		
		System.out.println(cownum);
		
//		out.write(cownum + "\n");
//		out.close();
//		in.close();
	}

}
