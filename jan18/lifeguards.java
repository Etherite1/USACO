
import java.util.*;
import java.io.*;

public class lifeguards {
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader(new File("lifeguards.in")));
		FileWriter out = new FileWriter(new File("lifeguards.out"));
		
		int n = Integer.parseInt(in.readLine());
		
		int[][] arr = new int[n][2];
		for(int i = 0; i < n; i++)
		{
			String[] s = in.readLine().split(" ");
			arr[i][0] = Integer.parseInt(s[0]);
			arr[i][1] = Integer.parseInt(s[1]);
		}
		Arrays.sort(arr, (a, b) -> Double.compare(a[0], b[0]));
		
		
		
		PriorityQueue<Event> pq = new PriorityQueue<>();
		for(int i = 0; i < n; i++)
		{
			pq.add(new Event(true, arr[i][0], i));
			pq.add(new Event(false, arr[i][1], i));
		}
		HashSet<Integer> uniqued = new HashSet<>();
		int currsegs = 0;
		int left = 0;
		ArrayList<Integer> uniquesegs = new ArrayList<Integer>();
		int currid = 0;
		while(!pq.isEmpty())
		{
			Event curr = pq.poll();
			if(curr.l)
			{
				if(currsegs == 0) 
				{
					left = curr.x;
					currid = curr.id;
				}
				else if(currsegs == 1)
				{
					uniquesegs.add((curr.x) - left);
					uniqued.add(currid);
					currid = curr.id;
				}
				currsegs++;
			}
			else
			{
				if(currsegs == 2) 
				{
					left = curr.x;
				}
				else if(currsegs == 1)
				{
					uniquesegs.add(curr.x - left);
					uniqued.add(currid);
				}
				currsegs--;
			}

		}

		for(int i = 0; i < n; i++)
		{
			pq.add(new Event(true, arr[i][0], i));
			pq.add(new Event(false, arr[i][1], i));
		}
		
		int count = 0;
		left = pq.peek().x;
		int numsegs = 0;
		while(!pq.isEmpty())
		{
			Event curr = pq.poll();
			if(numsegs == 0) left = curr.x;
			if(curr.l) numsegs++;
			else numsegs --;
			if(numsegs == 0)
			{
				count += curr.x - left;
			}
		}
		
		Collections.sort(uniquesegs);
		
		if(uniqued.size() < n) out.write(count + "\n");
		else out.write((count - uniquesegs.get(0) + "\n"));
		System.out.println(uniqued.size() < n? count : (count - uniquesegs.get(0)));

		out.close();
		
	}
	
	static class Event implements Comparable<Event>
	{
		boolean l;
		int x;
		int id;
		
		public Event(boolean left, int coord, int idd)
		{
			x = coord;
			l = left;
			id = idd;
		}
		
		public int compareTo(Event other)
		{
			return x - other.x;
		}
	}
	
}





