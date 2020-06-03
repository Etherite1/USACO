/*
ID: xuhumph1
LANG: JAVA
TASK: beads
*/

//package everything;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

public class brokennecklace {
	public static void main(String[] args) throws Exception{
		String filename = "beads.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);
		String filename2 = "beads.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		String read = br.readLine();
		String beads = br.readLine();
		
		myread2.write((String.valueOf(checker(beads)) + "\n"));
		myread2.close();
		br.close();
	}
	
	public static String firstIsWChecker(String[] lst, int idx) {
		try {
			if(lst[idx] == "w") {
				return firstIsWChecker(lst, idx + 1);
			}
			else{
				return lst[idx];
			}
		}
		catch(Exception IndexOutOfBounds) {
			return lst[idx];
		}
	}
	
	public static int count(String[] lst) {
		int reps = 0;
		int idx = 0;
		String firstone = firstIsWChecker(lst, 0);
		try {
			while(lst[idx].equals(firstone) || lst[idx].equals("w")) {
				idx += 1;
				reps += 1;
			}
		}
		catch(Exception IndexOutOfBounds) {
			return reps;
		}
		return reps;
	}
	
	public static int checker(String beads) {
		beads += beads;
		ArrayList<String> lst = new ArrayList<String>();
		for(int i = 0; i < beads.length(); i++) {
			lst.add(String.valueOf(beads.charAt(i)));
		}
		for(int i = 0; i < lst.size(); i++) {
			String one = lst.get(i);
			if (one == "\n" || one == " "){
				lst.remove(i);
			}
		}
		beads = String.join("", lst);
		int oldMax = 0;
		int idx = beads.length() - 1;
		if (beads == new String(new char[beads.length()]).replace("\0", String.valueOf(beads.charAt(0)))) {
			oldMax = beads.length() / 2;
			return (int) oldMax;
		}
		
		while(idx > 0) {
			String beginningtoidx = beads.substring(0, idx);
			String idxtoen = beads.substring(idx);
			String beginningtoidx2 = new StringBuilder(beginningtoidx).reverse().toString();
			
			String[] beginningtoidx1 = beginningtoidx2.split("");
			String[] idxtoend1 = idxtoen.split("");	
			int a = count(beginningtoidx1);
			int b = count(idxtoend1);
			int current = a + b;
			if(current > oldMax) {
				oldMax = current;
			}
			idx -= 1;
		}
		
		if (oldMax > beads.length() / 2) {
			oldMax = beads.length() / 2;
		}
		return (int) oldMax;
	}
}
