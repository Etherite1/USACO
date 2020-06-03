
/*
ID: xuhumph1
LANG: JAVA
TASK: crypt1
*/



import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.lang.reflect.Array;
import java.util.Arrays;

public class crypt1 {

	public static void main(String[] args) throws Exception{
		String filename = "crypt1.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);

		String filename2 = "crypt1.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		br.readLine();
		String input = br.readLine();
		
		String[] a = input.split(" ");
		
//		int[] nums = new int[a.length];
//		for (int i = 0; i < nums.length; i++){
//			nums[i] = Integer.parseInt(a[i]); 
//		}
		
		int total = 0;
		
		for(int i = 100; i < 1000; i++) {
			if(allcontains(String.valueOf(i), a)) {
				for(int j = 10; j < 100; j++) {
					if((i * j) > 9999){
						break;
					}
					
					if(allcontains(String.valueOf(j), a)) {
					
						String aten = String.valueOf(String.valueOf(j).charAt(0));
						String aone = String.valueOf(String.valueOf(j).charAt(1));
						
						int tempten = Integer.valueOf(aten);
						int tempone = Integer.valueOf(aone);
						
						int tens = i * tempten;
						int ones = i * tempone;
						int finalresult = tens * 10 + ones;
						
						if(allcontains(String.valueOf(tens), a)) {
							if(allcontains(String.valueOf(ones), a) && String.valueOf(ones).length() < 4) {
								if(allcontains(String.valueOf(finalresult), a)) {
									total++;
								}
								else {
									continue;
								}
							}
							else {
								continue;
							}
						}
						else {
							continue;
						}
					
					
				}
				else {
					continue;
				}
			}	
		}	
		else {
			continue;
		}
		
		
	}
		myread2.write(total + "\n");
		myread2.close();
		br.close();
}
	public static boolean allcontains(String str, String[] a) {
		String[] b = str.split("");
		for(int idx = 0; idx < b.length; idx++) {
			if(Arrays.asList(a).contains(b[idx])) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
		
	}
	
}