import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.LinkedList;

public class revegetate 
{
	static int[] pastures;
	static LinkedList<Integer>[] s, d;
	static int n, m;
	static boolean ok = true;
	
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("revegetate.in"));
		FileWriter out = new FileWriter("revegetate.out");
		
		String[] temp = in.readLine().split(" ");
		n = Integer.parseInt(temp[0]);
		m = Integer.parseInt(temp[1]);
		
		s = new LinkedList[n];
		d = new LinkedList[n];
		pastures = new int[n];
		
		for(int i = 0; i < n; i++)
		{
			s[i] = new LinkedList<Integer>();
			d[i] = new LinkedList<Integer>();
		}
		
		for(int i = 0; i < m; i++)
		{
			temp = in.readLine().split(" ");
			if(temp[0].equals("S")) 
			{
				s[Integer.parseInt(temp[1]) - 1].add(Integer.parseInt(temp[2]) - 1);
				s[Integer.parseInt(temp[2]) - 1].add(Integer.parseInt(temp[1]) - 1);
			}
			else
			{
				d[Integer.parseInt(temp[1]) - 1].add(Integer.parseInt(temp[2]) - 1);
				d[Integer.parseInt(temp[2]) - 1].add(Integer.parseInt(temp[1]) - 1);
			}
		}
		
		int fin = 0;
		
		for(int i = 0; i < pastures.length; i++)
		{
			if(pastures[i] == 0) 
			{
				search(i, 1);
				fin++;
			}
		}
		if(!ok) out.write("0\n");
		else
		{
			out.write("1");
			for(int i = 0; i < fin; i++) out.write("0");
			out.write("\n");
		}
		out.close();

	}
	
	static void search(int a, int curr)
	{
		pastures[a] = curr;
		for(int j : s[a])
		{
			if(pastures[j] > 0 && pastures[j] != curr) ok = false;
			if(pastures[j] == 0) search(j, curr);
		}

		for(int j : d[a])
		{
			if(pastures[j] > 0 && pastures[j] == curr) ok = false;
			if(pastures[j] == 0)
			{
				if(curr == 1) search(j, 2);
				else search(j, 1);
			}
		}
	}
}


