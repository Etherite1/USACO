
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;

public class hps {
	static int n;
	static int largest = 0;

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new FileReader(new File("hps.in")));
		FileWriter bw = new FileWriter(new File("hps.out"));
		n = Integer.valueOf(br.readLine());
		
		String[] fj = new String[n];
		for(int i = 0; i < n; i++)
			fj[i] = br.readLine();
		
		String[] choices =  new String[] {"H", "P", "S"};
		
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(i == j) continue;
				numOfWins(choices[i], choices[j], fj);
				numOfWins(choices[j], choices[i], fj);
			}
		}

		bw.write(largest + "\n");
		bw.close();
		br.close();
	}
	
	static void numOfWins(String a, String b, String[] fj)
	{
		String[] bessie = new String[n];
		int numofwins = 0;
		Arrays.fill(bessie, a);
		
		for(int i = 0; i < n; i++) if(compare(fj[i], bessie[i])) numofwins++;
		
		for(int i = 0; i < n; i++)
		{
			boolean old = compare(fj[i], bessie[i]);
 			bessie[i] = b;
			if(compare(fj[i], bessie[i]) && old == false) 
			 {
				numofwins++;
				if(numofwins > largest) 
					largest = numofwins;	
			}
			else if(old == true) 
				{
					numofwins--;
					if(numofwins > largest) 
						largest = numofwins;
				}
		}
	}
	
	static boolean compare(String fj, String bessie)
	{
		if(bessie.equals(fj)) return false;
		if(bessie.equals("H") && fj.equals("P")) return false;
		if(bessie.equals("H") && fj.equals("S")) return true;
		if(bessie.equals("S") && fj.equals("P")) return true;
		if(bessie.equals("S") && fj.equals("H")) return false;
		if(bessie.equals("P") && fj.equals("H")) return true;
		if(bessie.equals("P") && fj.equals("S")) return false;
		
		return false;
	}

}