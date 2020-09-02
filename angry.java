


import java.util.*;
import java.io.*;


public class angry {

	static int n, k;
	static int[] arr;
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("angry.in"));
		FileWriter out = new FileWriter("angry.out");
		
		String[] s = in.readLine().split(" ");
		n = Integer.parseInt(s[0]);
		k = Integer.parseInt(s[1]);
		
		arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = Integer.parseInt(in.readLine());
		Arrays.sort(arr);
		
		int l = 0, r = n - 1;
		
		while(l < r - 1)
		{
			int mid = (l + r) / 2;
			if(find(mid))
			{
				r = mid;
			}
			else l = mid;
		}
		out.write(r + "\n");
		out.close();
	}
	
	static boolean find(int r)
	{
		int curridx = 0;
		for(int i = 0; i < k; i++)
		{
			int idx = curridx;
			while(true)
			{
				if(idx == arr.length) return true;
				if(arr[idx] - arr[curridx] <= 2 * r) 
				{
					idx++;
				}
				else 
				{
					curridx = idx;
					break;
				}
			}
		}
		return false;
	}


}
