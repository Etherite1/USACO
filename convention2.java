

import java.util.*;
import java.io.*;

public class convention2 {

	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new FileReader("convention2.in"));
		FileWriter out = new FileWriter("convention2.out");
		
		int n = Integer.parseInt(in.readLine());
		
		Cow[] cows = new Cow[n];
		
		for(int i = 0; i < n; i++)
		{
			String[] x = in.readLine().split(" ");
			cows[i] = new Cow(Integer.parseInt(x[0]), Integer.parseInt(x[1]), i);
		}
		
		Arrays.sort(cows, (a, b) -> compare(a, b));
		
		PriorityQueue<Cow> pq = new PriorityQueue<Cow>();
		ArrayList<Long> waits = new ArrayList<Long>();
		
		pq.add(cows[0]);
		long t = cows[0].a;
		int curridx = 1;
		while(true)
		{
			while(!pq.isEmpty())
			{
				Cow curr = pq.poll();
				if(t - curr.a > 0) waits.add(t - curr.a);
				t += curr.t;
				if(curridx == n) break;
				else
				{
					while(cows[curridx].a <= t)
					{
						pq.add(cows[curridx]);
						if(curridx + 1 == n) 
						{
							curridx++;
							break;
						}
						else curridx++;
					}
				}
			}
			if(curridx == n) break;
			pq.add(cows[curridx]);
			t = cows[curridx].a;
			curridx++;
		}
		
		Collections.sort(waits);
		Collections.reverse(waits);
		
		if(waits.size() == 0) out.write("0\n");
		else
		{
			out.write(waits.get(0) + "\n");
		}
		out.close();
		in.close();
		
	}
	
	static int compare(Cow a, Cow b)
	{
		if(a.a == b.a) return a.idx - b.idx;
		else return a.a - b.a;
	}

	
}

class Cow implements Comparable<Cow>
{
	int a, t, idx, wait;
	
	public Cow(int ai, int ti, int i)
	{
		a = ai;
		t = ti;
		idx = i;
		wait = 0;
	}
	
	public int compareTo(Cow other)
	{
		return idx - other.idx;
	}
}



