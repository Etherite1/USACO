import java.io.*;
import java.util.*;


public class reduce 
{

	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("reduce.in"));
		FileWriter out = new FileWriter(new File("reduce.out"));
		
		int n = in.nextInt();
		int[][] cows = new int[n][2];
		int[][] cows2 = new int[n][2];
		ArrayList<int[]> largestx = new ArrayList<int[]>();
		ArrayList<int[]> smallestx = new ArrayList<int[]>();
		ArrayList<int[]> largesty = new ArrayList<int[]>();
		ArrayList<int[]> smallesty = new ArrayList<int[]>();

		
		for(int i = 0; i < n; i++)
		{
			int a = in.nextInt();
			int b = in.nextInt();
			cows[i] = new int[] {a, b};
			cows2[i] = new int[] {a, b};
		}
		
		Arrays.sort(cows2, (a, b) -> Double.compare(a[0], b[0]));
		

		for(int i = 0; i < 4; i++) //smallest x values
		{
			smallestx.add(cows2[i]);
		}

		for(int i = n - 4; i < n; i++) //largest x values
		{
			largestx.add(cows2[i]);
		}
		Arrays.sort(cows2, (a, b) -> Double.compare(a[1], b[1]));
		
		
		for(int i = 0; i < 4; i++)
		{
			smallesty.add(cows2[i]);
		}
		for(int i = n - 4; i < n; i++) //largest y values
		{
			largesty.add(cows2[i]);
		}
		List<int[]> allcows = new LinkedList<int[]>(Arrays.asList(cows));
		
		System.out.println();
		
		int smallest = Integer.MAX_VALUE;

		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				for(int k = 0; k < 4; k++)
				{
					for(int l = 0; l < 4; l++)
					{
						boolean[] temp = new boolean[4];
						for(int a = 0; a < allcows.size(); a++)
						{
							try
							{
								if(Arrays.equals(allcows.get(a), smallestx.get(i)) && allcows.size() > n - 3) 
								{
									allcows.remove(a);
									temp[0] = true;
								}
							}
							catch(Exception IndexOutOfBounds) {}
							try
							{
								if(Arrays.equals(allcows.get(a), largestx.get(j)) && allcows.size() > n - 3) 
								{
									allcows.remove(a);
									temp[1] = true;
								}
							}
							catch(Exception IndexOutOfBounds) {}
							try
							{
								if(Arrays.equals(allcows.get(a), smallesty.get(k)) && allcows.size() > n - 3) 
								{
									allcows.remove(a);
									temp[2] = true;
								}
							}
							catch(Exception IndexOutOfBounds) {}
							try
							{
								if(Arrays.equals(allcows.get(a), largesty.get(l)) && allcows.size() > n - 3) 
								{
									allcows.remove(a);
									temp[3] = true;
								}
							}
							catch(Exception IndexOutOfBounds) {}
						}
						
						
						int small = rect(allcows);
						if(small < smallest) 
							smallest = small;
						
						if(temp[0]) allcows.add(smallestx.get(i));
						if(temp[1]) allcows.add(largestx.get(j));
						if(temp[2]) allcows.add(smallesty.get(k));
						if(temp[3]) allcows.add(largesty.get(l));
						
						
					}
				}
			}
		}
		
		out.write(smallest + "\n");
		out.close();
		in.close();
		System.out.println(smallest);
	}
	
	static int rect(List<int[]> allcows)
	{
		int smallx = Integer.MAX_VALUE;
		int smally = Integer.MAX_VALUE;
		int largex = 0;
		int largey = 0;
		
		for(int[] i : allcows)
		{
			if(i[0] < smallx) smallx = i[0];
			if(i[0] > largex) largex = i[0];
			if(i[1] < smally) smally = i[1];
			if(i[1] > largey) largey = i[1];
		}
		
		return ((largex - smallx) * (largey - smally));
	}

}
