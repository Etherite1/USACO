package everything;
import java.awt.List;

/*
ID: xuhumph1
LANG: JAVA
TASK: wormhole
*/



import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;


public class wormhole{
	
	public static int N, MAX_N = 12;
	public static int[] X = new int[MAX_N + 1], Y = new int[MAX_N + 1];
	public static int[] partner = new int[MAX_N + 1];
	public static int[] next_on_right = new int[MAX_N + 1];
	
	public static boolean cycle_exists()
	{
	  for (int start=1; start<=N; start++) {
	    // does there exist a cylce starting from start
	    int pos = start;
	    for (int count=0; count<N; count++)
	      pos = next_on_right[partner[pos]];
	    if (pos != 0) return true;
	  }
	  return false;
	}
	
	public static int solve() 
	{
	  // find first unpaired wormhole
	  int i, total=0;
	  for (i=1; i<=N; i++) 
	    if (partner[i] == 0) break;

	  // everyone paired?
	  if (i > N) {
	    if (cycle_exists()) return 1;
	    else return 0;
	  }

	  // try pairing i with all possible other wormholes j
	  for (int j=i+1; j<=N; j++)
	    if (partner[j] == 0) {
	      // try pairing i & j, let recursion continue to 
	      // generate the rest of the solution
	      partner[i] = j;
	      partner[j] = i;
	      total += solve();
	      partner[i] = partner[j] = 0;
	    }
	  return total;
	}
	
	public static void main(String[] args) throws Exception
	{

		String filename = "C:\\temp\\wormhole.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);

		String filename2 = "C:\\temp\\wormhole.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		N = Integer.valueOf(br.readLine());
		
		for (int i=1; i<=N; i++) // set next_on_right[i]...
		    for (int j=1; j<=N; j++)
		      if (X[j] > X[i] && Y[i] == Y[j]) // j right of i...
			if (next_on_right[i] == 0 ||
			    X[j]-X[i] < X[next_on_right[i]]-X[i])
			  next_on_right[i] = j;
		
		for(int i = 1; i <= N; i++) 
		{
			
			String temp = br.readLine();
			String[] temp2 = temp.split(" ");
			X[i] = Integer.valueOf(temp2[0]);
			Y[i] = Integer.valueOf(temp2[1]);
		}
		
		myread2.write(String.valueOf(solve()) + "\n");
		myread2.close();
		br.close();
		


	}
	
}	
