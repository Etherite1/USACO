import java.util.*;
import java.io.*;

public class homework 
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("homework.in"));
		FileWriter out = new FileWriter("homework.out");
		
		int n = Integer.parseInt(in.readLine());
		String[] a = in.readLine().split(" ");
		int[] scores = new int[n];
		int[] mins = new int[n];
		for(int i = 0; i < n; i++)
			scores[i] = Integer.parseInt(a[i]);
		
		long total = 0;
		int min = 10001;
		double avg = 0;
		
		for(int i = 0; i < n; i++)
			total += scores[i];
		
		for(int i = n - 1; i >= 0; i--)
		{
			if(scores[i] < min)
			{
				min = scores[i];
				mins[i] = scores[i];
			}
			else
			{
				mins[i] = min;
			}
		}
		
		System.out.println();
		
		ArrayList<double[]> all = new ArrayList<double[]>();
//		if(total / scores.length > avg) all.add(new double[] {total / scores.length, scores.length});
		
		for(int i = 0; i < n - 1; i++)
		{
			if(((double)total - mins[i]) / (n - i - 1) >= avg && i != 0)
			{
				avg = ((double)total - mins[i]) / (n - i - 1);
				all.add(new double[] {avg, i});
			}
			total -= scores[i];
			
		}
		
		Collections.sort(all, (b, c) -> Double.compare(b[0], c[0]));
		
		ArrayList<Double> fin = new ArrayList<Double>();
		double temp = all.get(all.size() - 1)[0];
		for(int i = 0; i < all.size(); i++)
		{
			if(all.get(i)[0] == temp) fin.add(all.get(i)[1]);
		}
		
		for(double i : fin)
		{
			out.write((int) i + "\n");
		}
		out.close();
		
	}

}
