package everything;

import java.io.*;
import java.util.*;

public class citystate {

	public static void main(String[] args) throws Exception {
		String filename = "C:\\temp\\citystate.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);

//		String filename2 = "citystate.out";
//		File file2 = new File(filename2);
//		FileWriter bw = new FileWriter(file2);

		
		int n = Integer.valueOf(br.readLine());
		
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		
		for(int i = 0; i < n; i++)
		{
			String[] iptarr = br.readLine().split(" ");
			if(iptarr[0].substring(0, 2).equals(iptarr[1])) 
				continue;
			String current = iptarr[0].substring(0, 2) + iptarr[1];
			if(!map.containsKey(current))
				map.put(current, 0);

			map.put(current, map.get(current) + 1);
			
		}
		
		int temp = 0;
		
		for(String key : map.keySet())
		{
			String rev = key.substring(2) + key.substring(0, 2);
			if(map.containsKey(rev))
			{
				int abc =(map.get(key) * map.get(rev));
				System.out.println(map.get(key) + " " + map.get(rev));
				temp += abc;
			}
		}
		
		temp/=2;
		
//		bw.write(temp + "\n");
//		bw.close();
		br.close();
	}

}
