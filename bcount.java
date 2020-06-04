
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class bcount {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(new File("bcount.in")));
		FileWriter bw = new FileWriter(new File("bcount.out"));
		
		String[] a = br.readLine().split(" ");
		int n = Integer.valueOf(a[0]);
		int q = Integer.valueOf(a[1]);
		
		int[][] psums = new int[n + 1][3];
		for(int i = 1; i < n + 1; i++)
		{
			psums[i][0] = psums[i - 1][0];
			psums[i][1] = psums[i - 1][1];
			psums[i][2] = psums[i - 1][2];
			psums[i][Integer.valueOf(br.readLine()) - 1]++;
		}
		
		for(int i = 0; i < q; i++)
		{
			a = br.readLine().split(" ");
			int b = Integer.valueOf(a[0]) - 1;
			int c = Integer.valueOf(a[1]);
			
			int h = psums[c][0] - psums[b][0];
			int g = psums[c][1] - psums[b][1];
			int j = psums[c][2] - psums[b][2];
			bw.write(h + " " + g + " " + j + "\n");

		}

		bw.close();
		br.close();
		
	}

}
