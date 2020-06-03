
/*
ID: xuhumph1
LANG: JAVA
TASK: dualpal
*/



import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;

public class dualpal {
	
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
	
	public static boolean isPalindrome(String s) {
		String result = new StringBuffer(s).reverse().toString();
		if(s.equals(result)) {
			return true;
		}
		else {
			return false;
		}
	}

	public static void main(String[] args) throws Exception {
		String filename = "dualpal.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);

		String filename2 = "dualpal.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		
		String input = br.readLine();
		
		String[] a = input.split(" ");
		int n = Integer.valueOf(a[0]);
		int s = Integer.valueOf(a[1]) + 1;
		
		int temp = 0;
		ArrayList numbers = new ArrayList();
		int times = 0;
		
		while(temp < n) {
			for(int base = 2; base <= 10; base++) {
				String converted = (String) baseConversion(String.valueOf(s), 10, base);
				if(isPalindrome(converted)) {
					times++;
					if(times == 2) {
						numbers.add(s);
						temp += 1;
						break;
					}
					else {
						continue;
					}
				}
			}
			times = 0;
			s += 1;
			
		}
		
		for(int i = 0; i < numbers.size(); i++) {
			myread2.write(numbers.get(i) + "\n");
		}
		
		myread2.close();
		br.close();
}}