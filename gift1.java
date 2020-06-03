/*
ID: xuhumph1
LANG: JAVA
TASK: gift1
 */


//package everything;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedHashMap;
import java.util.Map;


public class gift1 {
		public static void main(String[] args) throws Exception {
			String filename = "gift1.in";
			File file = new File(filename);
			FileReader myread = new FileReader(file);
			
			ArrayList<String> result = new ArrayList<>();
			 
			try (BufferedReader br = new BufferedReader(myread)) {
			    while (br.ready()) {
			        result.add(br.readLine());
			    }
			}
			
			String filename2 = "gift1.out";
			File file2 = new File(filename2);
			FileWriter myread2 = new FileWriter(file2);
			 
			
			int numofnames = Integer.parseInt(result.get(0));
			Map<String, Integer> money = new LinkedHashMap<String, Integer>();
			for (int i = 1; i < numofnames + 1; i++) {
				money.put(result.get(i), 0);
			}
			
			int idx = 0;
			idx += 1 + numofnames;
			
			String giver = "";
			int moneygiven = 0;
			int amtofpeople = 0;
			String bigstring = "";
			String[] bigarray = new String[2];
			int amounttopeople = 0;
			String currentreceiver = "";
			
			
			
			while (true){
				try {
				giver = result.get(idx);
				bigstring = result.get(idx + 1);
				bigarray = bigstring.split(" ", 2);
				amtofpeople = Integer.parseInt(bigarray[1]);
				moneygiven = Integer.parseInt(bigarray[0]);
				try {
				amounttopeople = moneygiven / amtofpeople;
				}
				
				catch(Exception ArithmeticException){
					idx += 2;
					continue;
				}
				for (int i = 0; i < amtofpeople; i++) {
					currentreceiver = result.get(idx + i + 2);
					money.replace(currentreceiver, money.get(currentreceiver) + amounttopeople);
				}
				
				money.replace(giver, money.get(giver) - (amounttopeople * amtofpeople));
				
				idx += 2 + amtofpeople;}
			
				catch(Exception IndexOutOfBoundsException) {
					break;
				}
			}
			
			for (Map.Entry<String,Integer> entry : money.entrySet())  
		           myread2.write(entry.getKey() + " "+ entry.getValue() + "\n"); 	
			
			myread2.close();

			
		}
	
}
