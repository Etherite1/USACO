import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class paintbarn {

	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("paintbarn.in"));
		FileWriter out = new FileWriter("paintbarn.out");
		String[] temp = in.readLine().split(" ");
		int n = Integer.parseInt(temp[0]);
		int k = Integer.parseInt(temp[1]);
		
		int[][] field = new int[1001][1001];
		
		for(int j = 0; j < n; j++)
		{
			temp = in.readLine().split(" ");
			int a = Integer.parseInt(temp[0]);
			int b = Integer.parseInt(temp[1]);
			int c = Integer.parseInt(temp[2]);
			int d = Integer.parseInt(temp[3]);
			
			for(int i = a; i < c; i++)
			{
				field[i][b]++;
				field[i][d]--;
			}
		}
		
		
		int fin = 0;
		for(int i = 0; i < 1000; i++)
		{
			for(int j = 0; j < 1000; j++)
			{
				if(field[i][j] == k) fin++;
				field[i][j + 1] += field[i][j];
			}
		}
		
		out.write(fin + "\n");
		out.close();
	}

}
