/*
TASK: ride
LANG: JAVA

 */
import java.io.*;
//import java.io.BufferedReader;
//import java.io.FileReader;

public class ride {

	public static void main(String[] args) throws Exception 
	{
		// TODO Auto-generated method stub
//		String file = "C:\\Users\\xuyu2\\Desktop\\java\\yourrideishere\\ride.in\"";
		String filename = "ride.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);
		String filename2 = "ride.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		String line1 = br.readLine();
		String line2 = br.readLine();
		
		String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int sum1 = 1;
		int sum2 = 1;
	
		
		for(int i = 0; i < line1.length(); i++) {
			sum1 *= (1 + alphabet.indexOf(line1.charAt(i)));
		}
		
		for(int i = 0; i < line2.length(); i++) {
			sum2 *= (1 + alphabet.indexOf(line2.charAt(i)));
		}
		
		if (sum1 % 47 == sum2 % 47) {
			myread2.write("GO\n");
		}
		else {
			myread2.write("STAY\n");
		}
		
		myread2.close();
		
	}}

//		File file = new File("C:\\temp\\ride.in");
//		
//		
//		
		
	

