import java.io.*;
import java.util.*;

public class haybales 
{

	public static void main(String[] args) throws Exception 
	{
		Scanner in = new Scanner(new File("haybales.in"));
		FileWriter out = new FileWriter(new File("haybales.out"));
		
		int n = in.nextInt();
		int q = in.nextInt();
		
		int[] bales = new int[n];
		for(int i = 0; i < n; i++)
		{
			bales[i] = in.nextInt();
		}
		Arrays.sort(bales);
		for(int i = 0; i < q; i++)
		{
			int a = in.nextInt();
			int b = in.nextInt();
//			if(a == 4) 
//				System.out.println();
			if(a > bales[bales.length - 1]) 
			{
				out.write("0\n");
//				System.out.print("0\n");
				continue;
			}
			else if(b > bales[bales.length - 1]) b = bales[bales.length - 1];
			
 			if(b < bales[0]) 
			{
				out.write("0\n");
				System.out.print("0\n");
				continue;
			}
			else if (a < bales[0]) a = bales[0];
			
			int[] temp = find(a, b, bales);
			out.write((temp[1] - temp[0] + 1) + "\n");
//			System.out.print((temp[1] - temp[0] + 1) + "\n");
		}
		
//		int bales[] = new int[] {3, 6, 9, 12, 15, 21, 24};

//		find(7, 16, bales);
		
		in.close();
		out.close();
	}
	
	static int[] find(int start, int end, int[] bales)
	{
		/*
		int low = 0;
		int high = n;
		
		while(high - low > 1) {
			// 0 1 2 3 4 5 6 7 .... 
			// T T T T T T T .... T F F F F F F F 
			// F F F F F F F F F 
			// want to find the last index i such that check(i) = T
			// loop invariant
			// low -> T, high -> F
			int mid = (low + high)/2;
			if(check(mid) == T) low = mid;
			else high = mid;
		}
		if(check(low) == F) // degenerate case (all falses)
		// high = low + 1
		// low is answer
		
		// 2 3 7 9 10
		// find the smallest number greater than start = 5
		// F F T T T
		
		*/
		
		int[] ret = new int[2];
		
		int l = 0;
		int r = bales.length - 1;
		while(true) // bin search to find smallest val in bales >= start
		{
			int mid = (l + r) / 2;
			if(l > r) 
			{
				ret[0] = l;
				break;
			}
			if(bales[mid] == start)
			{
				ret[0] = mid;
				break;
			}
			
			if(start < bales[mid])
			{
				r = mid - 1;
			}
			else if(start > bales[mid]) 
			{
				l = mid + 1;
			}
		}
		
		l = 0;
		r = bales.length - 1;
		while(true) // bin search to find largest val in bales <= start
		{
			
			int mid = (l + r) / 2;
			if(l > r) 
			{
				ret[1] = r;
				break;
			}
			if(bales[mid] == end)
			{
				ret[1] = mid;
				break;
			}
			if(end < bales[mid])
			{
				r = mid - 1;
			}
			else if(end > bales[mid]) 
			{
				l = mid + 1;
			}
		}
		
		return ret;
		
	}

}
