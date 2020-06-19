import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class bbreeds {
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader(new File("bbreeds.in")));
		FileWriter bw = new FileWriter(new File("bbreeds.out"));
		String[] input = br.readLine().split("");
		
		int x = 2;
		
		for(int i = 0; i < input.length; i++)
			if(input[i].equals("("))
				for(int j = i; j < input.length; j++)
				{
					if(input[j].equals(")")) x++;
				}
		x = x % 2012;
		
		bw.write(x + "\n");
		bw.close();
		br.close();
		
	}
	
	static boolean balanced(String input)
	{
		int[][] list = new int[input.length()][2];
		String[] ipt = input.split("");
		if(ipt[0].equals("(")) list[0][0]++;
		else 
		{
			list[0][0]++;
		}
		
		for(int i = 1; i < ipt.length; i++)
		{
			list[i][0] = list[i - 1][0];
			list[i][1] = list[i - 1][1];
			if(ipt[i].equals("(")) list[i][0]++;
			else list[i][1]++;
			
			if(list[i][1] > list[i][0])
			{
				return false;
			}
		}
		if(list[list.length - 1][1] != list[list.length - 1][0]) return false;
		else return true;
	}
	
//	static boolean bothbal(String input)
//	{
//		
//	}
	
	
}
