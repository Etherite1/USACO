package everything;

import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class preface {
	static HashMap<String, Integer> numerals = new HashMap<String, Integer>();
	
	
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("C:\\temp\\preface.in"));
		FileWriter bw = new FileWriter(new File("C:\\temp\\preface.out"));
		
		int n = in.nextInt();
		
		numerals.put("I", 1);
		numerals.put("V", 5);
		numerals.put("X", 10);
		numerals.put("L", 50);
		numerals.put("C", 100);
		numerals.put("D", 500);
		numerals.put("M", 1000);
		ArrayList<String> prefaces = new ArrayList<String>();

		for(int i = 1; i <= n; i++)
		{
			prefaces.add(compute(i));
		}
		
		// after, loop through prefaces and compute how many of each there are
	}
	
	static String compute(int i)
	{
		String rnum = "";
		
		
		return rnum;
	}

}
