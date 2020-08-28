
import java.util.*;
import java.io.*;

public class measurement {


	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("measurement.in"));
		FileWriter out = new FileWriter("measurement.out");
		
		String[] s = in.readLine().split(" ");
		int n = Integer.parseInt(s[0]);
		int g = Integer.parseInt(s[1]);
		
		HashMap<Integer, Integer> cows = new HashMap<>();
		HashSet<Integer> largest = new HashSet<>();
		
		int[][] entries = new int[n][3];
		for(int i = 0; i < n; i++)
		{
			s = in.readLine().split(" ");
			int date = Integer.parseInt(s[0]);
			int id = Integer.parseInt(s[1]);
			String change = s[2];
			
			largest.add(id);
			cows.put(id, g);
			entries[i][0] = date;
			entries[i][1] = id;
			entries[i][2] = Integer.parseInt(change);
		}
		
		Arrays.sort(entries, (a, b) -> Double.compare(a[0], b[0]));
		
		int times = 0;
		
		// don't have to check if delta output is 0
		
		int count = 0;
		for(int[] i : entries)
		{
			count++;
			int old = cows.get(i[1]);
			int neww = cows.get(i[1]) + i[2];
			cows.put(i[1], neww);
			if(neww > old) // more production after change
			{
				if(largest.size() == 1 && largest.contains(i[1])) 
					continue;
				for(int j : largest)
				{
					if(neww > cows.get(j)) //more production than other cows
					{
						times++;
						largest.clear();
						largest.add(i[1]);
//						for(int h : largest) out.write(h + " ");
//						out.write("\n");
					}
					else if(neww == cows.get(j)) // same production as other cows
					{
						times++;
						largest.add(i[1]);
//						for(int h : largest) out.write(h + " ");
//						out.write("\n");
					}
					break;
				}
			}
			else //less production after change
			{
				if(largest.size() == 1 && largest.contains(i[1])) // largest number is only current id
				{
					boolean flag = false;
					for(int key : cows.keySet())
					{
						if(key == i[1]) continue;
						if(neww < cows.get(key)) 
						{
							flag = true;
							break;
						}
					}
					if(!flag) continue;
					times++;
					largest.clear();
					int tempmax = 0;
					for(int key : cows.keySet()) //second largest id
						tempmax = Math.max(tempmax, cows.get(key));
					for(int key : cows.keySet())
						if(cows.get(key) == tempmax) largest.add(key);
					
//					for(int j : largest) out.write(j + " ");
//					out.write("\n");
				}
				else if(largest.contains(i[1])) // current id no longer in largest list
				{
					times++;
					largest.remove(i[1]);
//					for(int j : largest) out.write(j + " ");
//					out.write("\n");
				}
			}
			

		}
	//		out.write("count: " + count + "\n");
	//		for (int key : cows.keySet())
	//		{
	//		   out.write(key + " " + cows.get(key) + ", ");
	//		}
	//		
	//		out.write('\n');
	//		for(int j : largest) out.write(j + " ");
	//		out.write('\n');
		System.out.println(times);

		
		out.write(times + "\n");
		out.close();
		in.close();
	}
}

	



