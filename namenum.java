/*
ID: xuhumph1
LANG: JAVA
TASK: namenum
*/



import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;


import java.util.HashMap;

public class namenum {
	
	public static HashMap<String, String[]> numberLetters = new HashMap<>();

	public static void main(String[] args) throws Exception {
		String filename = "namenum.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);
		
		String dictpath = "dict.txt";
		File dictfile = new File(dictpath);
		FileReader dictfilereader = new FileReader(dictfile);
		BufferedReader br2 = new BufferedReader(dictfilereader);
		
		String filename2 = "namenum.out";
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
		
		
		ArrayList a = mn(dict, input);
		if(a.size() == 0) {
			myread2.write("NONE\n");
		}
		else {
			for(int i = 0; i < a.size(); i++) {
				myread2.write(a.get(i) + "\n");
			}
		}
		
		br.close();
		myread2.close();
		
	}
	
	public static String converttonum(String name) {
		HashMap<String, String> numberLetters = new HashMap<String, String>();
		numberLetters.put("A", "2");
		numberLetters.put("B", "2");
		numberLetters.put("C", "2");
		numberLetters.put("D", "3");
		numberLetters.put("E", "3");
		numberLetters.put("F", "3");
		numberLetters.put("G", "4");
		numberLetters.put("H", "4");
		numberLetters.put("I", "4");
		numberLetters.put("J", "5");
		numberLetters.put("K", "5");
		numberLetters.put("L", "5");
		numberLetters.put("M", "6");
		numberLetters.put("N", "6");
		numberLetters.put("O", "6");
		numberLetters.put("P", "7");
		numberLetters.put("R", "7");
		numberLetters.put("S", "7");
		numberLetters.put("T", "8");
		numberLetters.put("U", "8");
		numberLetters.put("V", "8");
		numberLetters.put("W", "9");
		numberLetters.put("X", "9");
		numberLetters.put("Y", "9");
		
		String str = "";
		for(int i = 0; i < name.length(); i++) {
				String string = String.valueOf(name.charAt(i));
				str += numberLetters.get(string);

		}
		
		return str;
		
	}
	
	public static ArrayList mn(ArrayList dict, String number) {
		ArrayList possiblenames = new ArrayList();
		for(int i = 0; i < dict.size(); i++) {
			
			if(converttonum((String) dict.get(i)).equals(number)) {
				possiblenames.add(dict.get(i));
			}
		}
		
		return possiblenames;
	}
	
}
		

		