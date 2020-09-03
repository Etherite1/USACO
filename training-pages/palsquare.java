
/*
ID: xuhumph1
LANG: JAVA
TASK: palsquare
*/



import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;


import java.util.HashMap;

public class palsquare {
	
	public static String baseConversion(String number, int sBase, int dBase) 
	{ 
		// Parse the number with source radix  
		// and return in specified radix(base) 
		String a = Integer.toString(Integer.parseInt(number, sBase), dBase);
		String b  = "";
		for(int i = 0; i < a.length(); i++) {
			if(a.charAt(i) == 'a') {
				b += "A";
			}
			else if (a.charAt(i) == 'b') {
				b += "B";
			}
			else if (a.charAt(i) == 'c') {
				b += "C";
			}
			else if (a.charAt(i) == 'd') {
				b += "D";
			}
			else if (a.charAt(i) == 'e') {
				b += "E";
			}
			else if (a.charAt(i) == 'f') {
				b += "F";
			}
			else if (a.charAt(i) == 'g') {
				b += "G";
			}
			else if (a.charAt(i) == 'h') {
				b += "H";
			}
			else if (a.charAt(i) == 'i') {
				b += "I";
			}
			else {
				b += a.charAt(i);
			}
			
		}
		return b; 
	} 

	public static void main(String[] args) throws Exception {
		String filename = "palsquare.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);

		String filename2 = "palsquare.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		int base = Integer.valueOf(br.readLine());
		
		ArrayList<String> numbers = new ArrayList<String>();
		
		
		for(int i = 1; i <= 300; i++) {
			int a = (int) Math.pow(i, 2);
			String converted = (String) baseConversion(String.valueOf(a), 10, base);
			String result = new StringBuffer(converted).reverse().toString();
			if(converted.equals(result)) {
				numbers.add((String) baseConversion(String.valueOf(i), 10, base) + " " + converted);
			}
		}
		
		for(int i = 0; i < numbers.size(); i++) {
			myread2.write(numbers.get(i) + "\n");
		}
		
		myread2.close();
		br.close();
}}
