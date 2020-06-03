

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;

/*
ID: xuhumph1
LANG: JAVA
TASK: skidesign
*/

public class skidesign {

	public static void main(String[] args) throws Exception {
		String filename = "skidesign.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);

		String filename2 = "skidesign.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		ArrayList<Integer> hills = new ArrayList<Integer>();
		int numhills = Integer.valueOf(br.readLine());
		for(int i = 0; i < numhills; i++) {
			hills.add(Integer.valueOf(br.readLine()));
		}
		
		Collections.sort(hills);
		
		int price = 0;
		int finalprice = Integer.MAX_VALUE;
		
		for(int i = 0; i < 1000; i++) {

			int idx1 = i;
			int idx2 = i + 17;
			if(idx1 == 44) {
				System.out.println();
			}
			
			for(int j = 0; j < numhills; j++) {
				if(hills.get(j) >= idx1 && hills.get(j) <= idx2) {
					continue;
				}
				else {
					if(hills.get(j) < idx1) {
						price += (int) Math.pow(idx1 - hills.get(j), 2);
					}
					if(hills.get(j) > idx2) {
						price += (int) Math.pow(idx2 - hills.get(j), 2);
					}
				}
			}
			if(price < finalprice) {
				finalprice = price;
			}
			price = 0;
			
		}
		
		
		
		myread2.write(finalprice + "\n");
		myread2.close();
		br.close();
	}

}
