

import java.util.*;
import java.io.*;


public class shuffle {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("shuffle.in"));
		FileWriter out = new FileWriter("shuffle.out");
		HashSet<Integer> set = new HashSet<Integer>();
		int n = Integer.parseInt(in.readLine());
		String[] s = in.readLine().split(" ");
		HashMap<Integer, Integer> map = new HashMap<>();
		for(int i = 0; i < n; i++)
		{
			map.put(i, Integer.parseInt(s[i]) - 1);
		}
		
		while(true)
		{
			set.clear();
			for(int i : map.values()) set.add(i);
			
			boolean flag = false;
			
			HashSet<Integer> removeset = new HashSet<>();
			for(int i : map.keySet()) 
				if(!set.contains(i)) 
				{
					removeset.add(i);
					flag = true;
				}
			
			for(int i : removeset) map.remove(i);
			
			if(!flag) break;
		}
		System.out.println(map.size());
		
		out.write(map.size() + "\n");
		out.close();
	}

	static void solve() {

	}

}
