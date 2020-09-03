
/*
ID: xuhumph1
LANG: JAVA
TASK: barn1
*/



import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class barn1 {

	public static void main(String[] args) throws Exception{
		String filename = "barn1.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);

		String filename2 = "barn1.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		String inputed = br.readLine();
		ArrayList<Integer> stalls = new ArrayList<Integer>();
		String[] inputed1 = inputed.split(" ");
		int maxboards = Integer.valueOf(inputed1[0]);
		int totalstalls = Integer.valueOf(inputed1[1]);
		int occupiedstalls = Integer.valueOf(inputed1[2]);
		
		int[] input = new int[Integer.valueOf(inputed1[2])];
		for(int i = 0; i < occupiedstalls; i++) {
			input[i] = Integer.valueOf(br.readLine());
		}
		Arrays.sort(input);
		
		
		int total = 0;
		ArrayList gaps = new ArrayList();
		total += input[0] - 1;
		for(int i = 0; i < input.length - 1; i++) {
			if(input[i + 1] - input[i] == 1) {
				continue;
			}
			else {
				gaps.add(input[i + 1] - input[i] - 1);
			}
		}
		total += totalstalls - input[input.length -1];
		Collections.sort(gaps, Collections.reverseOrder());

		
		for(int i = 0; i < maxboards - 1; i++) {
			try{
				total += (int) gaps.get(i);
			}
			catch(Exception IndexOutOfBounds) {
				break;
			}
		}
		
		br.close();
		myread2.write((totalstalls - total) + "\n");
		myread2.close();
	}

}
