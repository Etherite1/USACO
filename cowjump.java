
import java.util.*;
import java.io.*;


public class cowjump 
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("C:\\temp\\cowjump.in"));
		FileWriter out = new FileWriter("cowjump.out");
		
		int n = Integer.parseInt(in.readLine());
		event[] events = new event[2 * n];
		int[][][] arr = new int[n][2][2];
		for(int i = 0; i < n; i++)
		{
			String[] x = in.readLine().split(" ");
			int[] a = new int[] {Integer.parseInt(x[0]), Integer.parseInt(x[1]), Integer.parseInt(x[2]), Integer.parseInt(x[3])}; 
			arr[i] = new int[][] {{a[0], a[1]}, {a[2], a[3]}};
			
			boolean left = false;
			if(a[0] == a[2]) 
			{
				if(a[3] > a[1]) 
				{
					events[2 * i] = new event(a[0], a[1], true, i);
					events[2 * i + 1] = new event(a[2], a[3], false, i);
				}
				else
				{
					events[2 * i] = new event(a[0], a[1], false, i);
					events[2 * i + 1] = new event(a[2], a[3], true, i);
				}
			}
			else if(a[0] < a[2])
			{
				events[2 * i] = new event(a[0], a[1], true, i);
				events[2 * i + 1] = new event(a[2], a[3], false, i);
			}
			else
			{
				events[2 * i] = new event(a[0], a[1], false, i);
				events[2 * i + 1] = new event(a[2], a[3], true, i);
			}
		}
		
		Arrays.sort(events);
		TreeSet<event> all = new TreeSet<event>();
		ArrayList<Integer> pos = new ArrayList<Integer>();
		
		for(int i = 0; i < events.length; i++)
		{
			if(events[i].left) 
			{
				all.add(events[i]);
				int eventi = events[i].idx;
				int higheri = -1;
				int loweri = -1;
				try 
				{
					higheri = all.higher(events[i]).idx;
				}
				catch(Exception NullPointerException) {}
				try
				{
					loweri = all.lower(events[i]).idx;
				}
				catch(Exception NullPointerException) {}
				if(higheri != -1)
				{
					if(intersect(arr[eventi][0], arr[eventi][1], arr[higheri][0], arr[higheri][1])) 
					{
						for(int j = i; j < events.length; j++)
						{
							int ji = events[j].idx;
							if(intersect(arr[eventi][0], arr[eventi][1], arr[ji][0], arr[ji][1]))
								break;
						}
						pos.add(eventi);
					}
				}
				else if(loweri != -1)
				{
					if(intersect(arr[eventi][0], arr[eventi][1], arr[loweri][0], arr[loweri][1])) 
					{
						for(int j = i; j < events.length; j++)
						{
							int ji = events[j].idx;
							if(intersect(arr[eventi][0], arr[eventi][1], arr[ji][0], arr[ji][1]))
								break;
						}
						pos.add(eventi);
					}
				}
			}
			else all.remove(events[i]);
		}
		
		System.out.println();
		
		out.close();
		in.close();

	}
	
	static int orientation(int[] p, int[] q, int[] r) {
	    double val = (q[1] - p[1]) * (r[0] - q[0])
	            - (q[0] - p[0]) * (r[1] - q[1]);

	    if (val == 0.0)
	        return 0; // colinear
	    return (val > 0) ? 1 : 2; // clock or counterclock wise
	}
	
	public static boolean intersect(int[] p1, int[] q1, int[] p2, int[] q2) {

	    int o1 = orientation(p1, q1, p2);
	    int o2 = orientation(p1, q1, q2);
	    int o3 = orientation(p2, q2, p1);
	    int o4 = orientation(p2, q2, q1);

	    if (o1 != o2 && o3 != o4)
	        return true;

	    return false;
	}
	
	

}

class event implements Comparable<event>
{
	int x, y, idx;
	boolean left;
	
	public event(int xx, int yy, boolean l, int i)
	{
		x = xx;
		y = yy;
		left = l;
		idx = i;
	}

	public int compareTo(event a) {
		if(x == a.x) return y - a.y;
		return x - a.x;
	}
}
