package everything;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class moobuzz {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		String filename = "C:\\temp\\moobuzz.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);

		String filename2 = "C:\\temp\\moobuzz.out";
		File file2 = new File(filename2);
		FileWriter bw = new FileWriter(file2);
		
		int input = Integer.valueOf(br.readLine());
		int output = fast(input);
		
//		System.out.println(output);
		bw.write(output + "\n");
		br.close();
		bw.close();
	}
	
	static int slow(int a) 
	{
		int i = 0;
		boolean isNum = false;
		int ticker = 1;
 		while(i < a)
		{
			isNum = isNumber(ticker);
			if(isNum && i == a - 1) return ticker;
			else if(isNum) i++;
			ticker++;
		}
		return -1;
	}
	

	static int fast(int a)
	{
		int[] d = new int[] {1,2,4,7,8,11,13,14};
		int remainder = (a - 1) % 8;
		int r = (a - 1) / 8 * 15;
		return r + d[remainder];
	}
	
	static boolean isNumber(int a)
	{
		return(!((a % 3 == 0) || (a % 5 == 0)));
	}

}
