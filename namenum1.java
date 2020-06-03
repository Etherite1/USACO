/*
ID: xuhumph1
LANG: JAVA
TASK: namenum
*/

package everything;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;

public class namenum {
	
	public static HashMap<String, String[]> numberLetters = new HashMap<>();

	public static void main(String[] args) throws Exception {
		String filename = "C:\\temp\\namenum.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);
		
		String dictpath = "C:\\temp\\dict.txt";
		File dictfile = new File(dictpath);
		FileReader dictfilereader = new FileReader(dictfile);
		BufferedReader br2 = new BufferedReader(dictfilereader);
		
		String filename2 = "C:\\temp\\namenum.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		
		String input = br.readLine();
		String[] anumber = input.split("");
		ArrayList<String> dict = new ArrayList<String>();
		for(int i = 0; i < 4617; i++) {
			String abc = br2.readLine();
			if(abc.length() == input.length()) {
				dict.add(abc);
			}
			
		}
		
		numberLetters.put("2", new String[] {"A", "B", "C"});
		numberLetters.put("3", new String[] {"D", "E", "F"});
		numberLetters.put("4", new String[] {"G", "H", "I"});
		numberLetters.put("5", new String[] {"J", "K", "L"});
		numberLetters.put("6", new String[] {"M", "N", "O"});
		numberLetters.put("7", new String[] {"P", "R", "S"});
		numberLetters.put("8", new String[] {"T", "U", "V"});
		numberLetters.put("9", new String[] {"W", "X", "Y"});
		
		
		ArrayList possible = mn(anumber, dict);
		if(possible.size() == 0) {
			myread2.write("NONE\n");
		}
		else {
			for(int i = 0; i < possible.size(); i++) {
				myread2.write(possible.get(i) + "\n");
			}
		}
		
		br.close();
		myread2.close();
		br2.close();
	}
	
	public static ArrayList mn(String[] number, ArrayList dict) {
		ArrayList allnames = new ArrayList();
		for(int i = 0; i < Math.pow(3,  number.length); i++) {
			allnames.add(new ArrayList());
		}
		int exponent = number.length - 1;
		int digitinnumber = 0;
		int letterinnumberletterlist = 0;
		int index1 = 0;
		int index2 = (int) Math.pow(3,  exponent);
		int temp = (int) Math.pow(3, exponent);
		
		
		long startTime = System.nanoTime();
		while(exponent >= 0) {
			for(int j = 0; j < 3 * Math.pow(3,  number.length - 1 - exponent); j++) {
				for(int i = index1; i < index2; i++) 
				{
					String temppp = number[digitinnumber];
					String[] a = numberLetters.get(temppp);
					if(letterinnumberletterlist >= 3) {
						letterinnumberletterlist = 0;
					}

					String[] a2 = numberLetters.get(number[digitinnumber]);
//						allnames.replace(a, letterinnumberletterlist;
					ArrayList b = (ArrayList) allnames.get(i);
					String added = a2[letterinnumberletterlist];
					b.add(added);
					allnames.set(i, b);
				}
				
				index1 += temp;
				index2 += temp;
				letterinnumberletterlist += 1;
				
			}
			exponent -= 1;
			index1 = 0;
			index2 = (int) Math.pow(3, exponent);
			temp = (int) Math.pow(3, exponent);
			digitinnumber += 1;
			letterinnumberletterlist = 0;
		}
		
		long endTime = System.nanoTime();
		System.out.println(endTime - startTime);

		
		ArrayList<String> allnames2 = new ArrayList<String>();
		ArrayList possiblenames = new ArrayList();
		
		startTime = System.nanoTime();
		for(int i = 0; i < allnames.size(); i++) {
			ArrayList b = (ArrayList) allnames.get(i);
			String c = String.join("", b);
			allnames2.add(c);
		}
		endTime = System.nanoTime();
		System.out.println(endTime - startTime);
		
		startTime = System.nanoTime();
		for(int i = 0; i < allnames.size(); i++) {
			String iname = allnames2.get(i);
			for(int j = 0; j < dict.size(); j++) {
				String jname = (String) dict.get(j);
				if(jname.length() > number.length) {
					continue;
				}
				else {
					if(iname.equals(jname)) {
						possiblenames.add(iname);
					}
				}
			}
		}
		endTime = System.nanoTime();
		System.out.println(endTime - startTime);
		
		return possiblenames;
	}

}
