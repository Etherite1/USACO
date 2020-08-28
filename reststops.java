import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class reststops {

	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new FileReader("reststops.in"));
		FileWriter out = new FileWriter("reststops.out");
		
		int l = in.nextInt();
		int n = in.nextInt();
		int rf = in.nextInt();
		int rb = in.nextInt();
		
		int[][] stops = new int[n][2];
		for(int i = 0; i < n; i++)
		{
			int x = in.nextInt();
			int y = in.nextInt();
			stops[i] = new int[] {x, y};
		}
		
		Arrays.sort(stops, (a, b) -> Double.compare(b[0], a[0]));
		
		ArrayList<int[]> all = new ArrayList<int[]>();
		int large = 0;
		for(int[] i : stops)
		{
			if(i[1] > large)
			{
				all.add(i);
				large = i[1];
			}
		}
		
		Collections.reverse(all);
		
		long fj = 0;
		long b = 0;
		long tu = 0;
		
		int stopnum = 0;
		for(int i = 0; i < l; i++)
		{
			fj += rf;
			b += rb;
			if(stopnum >= all.size()) break;
			if(i + 1 == all.get(stopnum)[0])
			{
				tu += (fj - b) * all.get(stopnum)[1];
				b = fj;
				stopnum++;
			}
		}
		
		System.out.println(tu);
		out.write(tu + "\n");
		out.close();
		in.close();

	}

}
