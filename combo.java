/*
ID: xuhumph1
LANG: JAVA
TASK: combo
*/


import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class combo {
	
	public static ArrayList<Integer> all = new ArrayList<Integer>();

	public static void main(String[] args) throws Exception {
		String filename = "combo.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);

		String filename2 = "combo.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		int n = Integer.valueOf(br.readLine());
		String temp = br.readLine();
		String[] johncombo = temp.split(" ");
		temp = br.readLine();
		String[] mastercombo = temp.split(" ");
		
		
		for(int i = 1; i <= n; i++) {
			all.add(i);
		}
		all.add(0, n);
		all.add(0, n - 1);
		all.add(1);
		all.add(2);
		int complete = 0;
		
		if(n < 5) {
			complete = (int) Math.pow(n, 3);
		}
		else {
			ArrayList<String> johngenned = generator(johncombo);
			ArrayList<String> mastergenned = generator(mastercombo);
			ArrayList<String> newarr = new ArrayList();
			newarr.addAll(johngenned);
			newarr.addAll(mastergenned);
			
			ArrayList<String> finalresult = new ArrayList<String>();
			for(int i = 0; i < newarr.size(); i++) {
				String abc = newarr.get(i);
				System.out.println(abc);
				if(i == 61 || i == 155) {
					System.out.println();
				}
				if(!finalresult.contains(abc)) {
					finalresult.add(abc);
				}
				else {
					continue;
				}
			}

			complete = finalresult.size();
		}
		myread2.write(String.valueOf(complete) + "\n");
		myread2.close();
		br.close();
	}
	
	public static ArrayList generator(String[] combo) {
		ArrayList possibles = new ArrayList();
		int a = 0;
		int b = 0;
		int c = 0;
		for(int i = -2; i <= 2; i++) {
			int idxof = all.indexOf(Integer.valueOf(combo[0]));
			try {
				a = all.get(Integer.valueOf(idxof) + i);
				}
			catch(Exception IndexOutOfBounds) {
				a = all.get(secondIndex(all, Integer.valueOf(combo[0])) + i);
			}
			for(int j = -2; j <= 2; j++) {
				int jdxof = all.indexOf(Integer.valueOf(combo[1]));
				try {
					b = all.get(Integer.valueOf(jdxof) + j);
					}
				catch(Exception IndexOutOfBounds) {
					b = all.get(secondIndex(all, Integer.valueOf(combo[1])) + j);
				}
				for(int k = -2; k <= 2; k++) {
					int kdxof = all.indexOf(Integer.valueOf(combo[2]));
					try {
						c = all.get(Integer.valueOf(kdxof) + k);
						}
					catch(Exception IndexOutOfBounds) {
						c = all.get(secondIndex(all, Integer.valueOf(combo[2])) + k);
					}
					possibles.add(String.valueOf(a) + " " + String.valueOf(b) + " " + String.valueOf(c));
				}
			}
		}
		
		
		return possibles;
	}
	
	public static int secondIndex(ArrayList input, int find) {
		int times = 0;
		int i = 0;
		for(i = 0; i < input.size(); i++) {
			if(String.valueOf(input.get(i)).equals(String.valueOf(find))) {
				times += 1;
			}
			if(times == 2) {
				return i;
			}
		}
		return i;
	}

}
