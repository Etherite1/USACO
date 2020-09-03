import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class clumsy {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(new File("clumsy.in")));
		FileWriter bw = new FileWriter(new File("clumsy.out"));
		
		int swaps = 0;
		
		String input = br.readLine();
		
		int[][] list = new int[input.length()][2];
		String[] ipt = input.split("");
		if(ipt[0].equals("(")) list[0][0]++;
		else 
			{
			list[0][0]++;
			swaps++;
			}
		
		for(int i = 1; i < ipt.length; i++)
		{
			list[i][0] = list[i - 1][0];
			list[i][1] = list[i - 1][1];
			if(ipt[i].equals("(")) list[i][0]++;
			else list[i][1]++;
			
			if(list[i][1] > list[i][0])
			{
				int temp = list[i][1];
				list[i][1] = list[i][0];
				list[i][0] = temp;
				swaps++;		
			}
		}
		if(list[list.length - 1][0] != list[list.length - 1][1])
		{
			swaps += ((list[list.length - 1][0] - list[list.length - 1][1]) / 2);
		}
		
		bw.write(swaps + "\n");
		bw.close();
		System.out.println(swaps);
		br.close();
	}

}
