import java.util.*;
import java.io.*;

public class meetings 
{

	static int[][] cows;
	static int n, l;
	
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new FileReader("meetings.in"));
		FileWriter out = new FileWriter("meetings.out");
		
		n = in.nextInt();
		l = in.nextInt();
		
		cows = new int[n][3];
		ArrayList<Integer> left = new ArrayList<Integer>();
		ArrayList<Integer> right = new ArrayList<Integer>();
		ArrayList<int[]> all = new ArrayList<int[]>();
		int t = 0;
		
		for(int i = 0; i < n; i++)
		{
			cows[i][0] = in.nextInt();
			cows[i][1] = in.nextInt();
			cows[i][2] = in.nextInt();
		}
		
		Arrays.sort(cows, (a, b) -> Double.compare(a[1], b[1]));	
		
		for(int i = 0; i < n; i++)
		{
			if(cows[i][2] == -1) left.add(i);
			else right.add(i);
		}
		
		for(int i = 0; i < left.size(); i++)
			all.add(new int[] {cows[left.get(i)][1], cows[i][0]});
		
		for(int i = 0; i < right.size(); i++)
			all.add(new int[] {l - cows[right.get(i)][1], cows[left.size() + i][0]});
		
		all.sort((a, b) -> Double.compare(a[0], b[0]));
		
		int tmp = 0;
		for(int i = 0; i < n; i++) tmp += cows[i][0];
		
		for(int i = 0; i < n; i++)
		{
			tmp -= 2 * all.get(i)[1];
			if(tmp <= 0)
			{
				t = all.get(i)[0];
				break;
			}
		}

		
//		int meetings = 0;
//		Queue<Integer> r = new LinkedList<Integer>();
//		for(int i = 0; i < n; i++)
//		{
//			if(cows[i][2] == -1) 
//			{
//				while(!r.isEmpty() && r.peek() + 2 * t < cows[i][1]) r.poll();
//				meetings += r.size();
//			}
//			else r.add(cows[i][1]);
//		}
//		System.out.println(meetings);
//		
//		int weight = 0;
//		for(int[] cow : cows) weight += cow[0];
//		int t = 0;
//		int temp = 0;
//		for(int i = 0; i < n; i++)
//		{
//			temp += cows[i][0];
//			if(temp >= weight / 2)
//			{
//				t = cows[i][3];
//				break;
//			}
//		}
		
//		System.out.println(find(t));
		out.write(find(t) + "\n");
		out.close();
		
		
	}
	
	static int find(int t)
	{
		ArrayList<Integer> left = new ArrayList<Integer>();
		ArrayList<Integer> right = new ArrayList<Integer>();
		int le, r;
		
		int meetings = 0;
		
		for(int[] cow : cows)
		{
			if(cow[2] == 1) right.add(cow[1]);
			else left.add(cow[1]);
		}
		Collections.sort(left);
		Collections.sort(right);		
		for(int cow : right)
		{
			int low = 0;
			int high = left.size();
	
			while(high - low > 1)
			{
	 			int mid = (low + high) / 2;
				if(left.get(mid) > cow + 2 * t) high = mid;
				else low = mid;
			}
			
			System.out.println(high);
			r = low;
			
			low = 0;
			high = left.size();
			
			while(high - low > 1)
			{
				int mid = (low + high) / 2;
				if(left.get(mid) < cow) low = mid;
				else high = mid;
			}
			if(left.get(low) >= cow) low--;
			
			System.out.println(low);
			le = low;
			
			meetings += r - le;
			
		}
		return meetings;
	}
	

}
