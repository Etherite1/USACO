
import java.io.*;
import java.util.*;

public class whereami {
	
	static String[] road;
	static int n;

	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("whereami.in"));
		FileWriter out = new FileWriter("whereami.out");
		
		n = Integer.parseInt(in.readLine());
		road = in.readLine().split("");

		for(int i = 1; i < n; i++)
			if(find(i)) 
			{
				out.write(((i) + "\n"));
				break;
			}
		
		out.close();
	}
	
	static boolean find(int k)
	{
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		
		for(int i = 0; i < n; i++)
		{
			String curr = "";
			if(i + k > n) break;
			for(int j = i; j < i + k; j++)
			{
				curr += road[j];
			}
			if(!map.containsKey(curr)) map.put(curr, 1);
			else map.put(curr, map.get(curr) + 1);
			
		}
		
		for(String key : map.keySet())
		{
			if(map.get(key) > 1) return false;
		}
		return true;
	}

}
