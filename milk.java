/*
ID: xuhumph1
LANG: JAVA
TASK: milk
*/


import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Map;
import java.util.TreeMap;

public class milk {

	public static void main(String[] args) throws Exception {
		String filename = "milk.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);

		String filename2 = "milk.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		String input = br.readLine();
		int unitsNeeded = Integer.valueOf(input.split(" ")[0]);

		ArrayList all = new ArrayList();
		
		for(int i = 0; i < Integer.valueOf(input.split(" ")[1]); i++){
			all.add(br.readLine().split(" "));
		}
		
		TreeMap<Integer, Integer> prices = new TreeMap();
		for(int i = 0; i < all.size(); i++) {
			String[] ab = (String[]) all.get(i);
			int[] a = new int[2];
			a[0] = Integer.valueOf(ab[0]);
			a[1] = Integer.valueOf(ab[1]);
			if(prices.containsKey(a[0])) {
				int abc = prices.get(a[0]);
				int huh = abc + a[1];
				prices.put(a[0], huh);
			}
			else {
				prices.put(a[0], a[1]);
			}
		}
		
		int finalprice = 0;
		
		for(Map.Entry<Integer,Integer> entry : prices.entrySet()) {
			int price = entry.getKey();
			int units = entry.getValue();
				  
			if(units > unitsNeeded) {
					  finalprice += price * unitsNeeded;
					  unitsNeeded = 0;
					  break;
			}
			else {
				finalprice += price * units;
				unitsNeeded -= units;
			}}
		

	
		
		
		
		myread2.write(finalprice + "\n");
		myread2.close();
		br.close();

}}


