package everything;

/*
ID: xuhumph1
LANG: JAVA
PROB: milk3

 */


import java.io.*;
import java.util.*;

public class milk3 {
	
	static int sizeA;
	static int sizeB;
	static int sizeC;
	static ArrayList<Integer> possible = new ArrayList<Integer>();
	static boolean[][][] visited = new boolean[21][21][21];

	public static void main(String[] args) throws Exception{

		FileReader myread = new FileReader(new File("C:\\temp\\milk3.in"));
		BufferedReader br = new BufferedReader(myread);
		FileWriter bw = new FileWriter(new File("C:\\temp\\milk3.out"));
		
		String a = br.readLine();
		String[] aa = a.split(" ");
		sizeA = Integer.valueOf(aa[0]);
		sizeB = Integer.valueOf(aa[1]);
		sizeC = Integer.valueOf(aa[2]);
		
		
		
		search(0, 0, sizeC);
		
		Collections.sort(possible);
		
		String current = "";
		for(int i = 0; i < possible.size(); i++) current += possible.get(i) + " ";
		bw.write(current.substring(0, current.length() - 1));
		bw.write("\n");
		br.close();
		bw.close();

	}
	
	public static void search(int a, int b, int c) 
	{
		if(visited[a][b][c]) return;
		
		visited[a][b][c] = true;
		if(a == 0) possible.add(c);
		
		//a to b
		if(a + b <= sizeB) search(0, a + b, c);
		else search(a - (sizeB - b), sizeB, c);
		
		//b to a
		if(b + a <= sizeA) search(b + a, 0, c);
		else search(sizeA, b - (sizeA - a), c);
		
		//a to c
		if(a + c <= sizeC) search(0, b, a + c);
		else search(a - (sizeC - c), b , sizeC);
		
		//c to a
		if(c + a <= sizeA) search(c + a, b, 0);
		else search(sizeA, b, c - (sizeA - a));
		
		//b to c
		if(b + c <= sizeC) search(a, 0, b + c);
		else search(a, b - (sizeC - c), sizeC);
		
		//c to b
		if(c + b <= sizeB) search(a, c + b, 0);
		else search(a, sizeB, c - (sizeB - b));
	}

}
