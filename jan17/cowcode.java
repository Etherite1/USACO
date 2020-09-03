import java.io.*;
import java.util.*;

public class cowcode {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("cowcode.in")));
		FileWriter bw = new FileWriter(new File("cowcode.out"));
		String[] ipt = br.readLine().split(" ");
		String orig = ipt[0];
		long n = Long.valueOf(ipt[1]);

		bw.write(find(orig, n) + "\n");
		bw.close();
		br.close();
		
//		System.out.println(find("COW", 8));
	}
	
	static char find(String a, long index)
	{
		if(index <= a.length()) return a.charAt((int) index - 1);
		long len = a.length();
		while(len < index) len *= 2;
		if(index == (len / 2) + 1) return find(a, index - 1);
		return find(a, index - (len / 2) - 1);
		
		
	}
}
