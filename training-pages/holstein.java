/*
ID: xuhumph1
LANG: JAVA
PROB: holstein
 */
import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class holstein 
{
	static int g;
	static int v;
	static ArrayList<int[]> pos = new ArrayList<int[]>();
	static int counter = 0;
	
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("holstein.in"));
		FileWriter bw = new FileWriter(new File("holstein.out"));
		
		v = in.nextInt();
		int[] vitamins = new int[v];
		
		for(int i = 0; i < v; i++)
		{
			vitamins[i] = in.nextInt();
		}
		
		g = in.nextInt();
		int[][] feeds = new int[g][v];
		
		for(int i = 0; i < g; i++)
			for(int j = 0; j < v; j++)
				feeds[i][j] = in.nextInt();
		

		int[] permsarr = new int[g];
		for(int i = 0; i < g; i++)
			permsarr[i] = i;
		
		
		
		for(int len = 1; len <= g; len++)
		{
			ArrayList<int[]> temp = genperms(len, permsarr);
			for(int[] i : temp)
				if(enough(i, feeds, vitamins)) pos.add(i);
		}
		
		
		bw.write(String.valueOf(pos.get(0).length));
		for(int i : pos.get(0)) 
			bw.write(" " + (i + 1));
		
		bw.write("\n");
		bw.close();
		in.close();
		
	}
	
	static ArrayList<int[]> genperms(int k, int[] input)
	{       
		ArrayList<int[]> subsets = new ArrayList<>();

		int[] s = new int[k];                  // here we'll keep indices 
		                                       // pointing to elements in input array

		if (k <= input.length) {
		    // first index sequence: 0, 1, 2, ...
		    for (int i = 0; (s[i] = i) < k - 1; i++);  
		    subsets.add(getSubset(input, s));
		    for(;;) {
		        int i;
		        // find position of item that can be incremented
		        for (i = k - 1; i >= 0 && s[i] == input.length - k + i; i--); 
		        if (i < 0) {
		            break;
		        }
		        s[i]++;                    // increment this item
		        for (++i; i < k; i++) {    // fill up remaining items
		            s[i] = s[i - 1] + 1; 
		        }
		        subsets.add(getSubset(input, s));
		    }
		}

		return subsets;
		// generate actual subset by index sequence
		
	}
	
	static int[] getSubset(int[] input, int[] subset) {
	    int[] result = new int[subset.length]; 
	    for (int i = 0; i < subset.length; i++) 
	        result[i] = input[subset[i]];
	    return result;
	}
	
	
	//TODO: Generate all combinations looping from size 1 to size g of array [1, 2, ... , g]. 
	//Calculate health this way, and if healthy then add to pos.
	
	
	
	static boolean enough(int[] path, int[][] feeds, int[] vitamins)
	{
		int[] temp = new int[v];
//		for(int i = 0; i < v; i++)
//		{
//			temp[i] += feeds[path.get(i)][i];
//		}
		for(int i = 0; i < path.length; i++)
			for(int j = 0; j < feeds[i].length; j++)
				temp[j] += feeds[path[i]][j];
		
		for(int i = 0; i < temp.length; i++)
			if(temp[i] >= vitamins[i]) continue;
			else return false;
			
		return true;
	}
}
