
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class highcard {

	static int largest = 0;

	public static void main(String[] args) throws Exception 
	{
		BufferedReader br = new BufferedReader(new FileReader(new File("highcard.in")));
		FileWriter bw = new FileWriter(new File("highcard.out"));
		
		int n = Integer.valueOf(br.readLine());
		
		ArrayList<Integer> bessie = new ArrayList<Integer>();
		ArrayList<Integer> elsie = new ArrayList<Integer>();
		boolean[] elsievis = new boolean[n * 2 + 1];
		for(int i = 0; i < n; i++)
		{
			int a = Integer.valueOf(br.readLine());
			elsievis[a] = true;
		}
		
		for(int i = 1; i < n * 2 + 1; i++)
		{
			if(elsievis[i]) elsie.add(i);
			else bessie.add(i);
		}
		
//		boolean[] vis = new boolean[n * 2];	
//		find(bessie, elsie, n, vis);
		
//		for(int i = 0; i < bessie.size(); i++) 
//		{
//			if(bessie.get(i) < elsie.get(0)) 
//			{
//				bessie.remove(i);
//				i++;
//			}
//		}

//		if(bessie.get(bessie.size() - 1) < elsie.get(0)) {}
//		else
//		{
//			for(int ecard : elsie)
//			{
//				if(bessie.get(bessie.size() - 1) < ecard) {continue;}
//				
//				for(int i = 0; i < bessie.size(); i++)
//				{
//					int bcard = bessie.get(i);
//					if(bcard > ecard)
//					{
//						largest++;
//						bessie.remove(Integer.valueOf(bcard));
//						i++;
//						break;
//					}
//				}
//			}
//		}
		
		int bdex = 0;
		int edex = 0;
		while(bdex < n && edex < n)
		{
			if(bessie.get(bdex) > elsie.get(edex))
			{
				largest++;
				bdex++;
				edex++;
			}
			else bdex++;
		}
		
		System.out.println(largest);
		bw.write(largest + "\n");
		bw.close();
		br.close();
		
	}
}
	
//	static void find(ArrayList<Integer> bessie, ArrayList<Integer> elsie, int n, boolean[] vis)
//	{
//		for(int i = 0; i < n; i++)
//		{
//			if(vis[bessie.get(i)]) continue;
//			vis[bessie.get(i)] = true;
//			if(bessie.get(i) > elsie.get(i)) current++;
//			find(bessie, elsie, n, vis);
//			
//		}
//		if(current > largest) largest = current;
//		current--;
//		return;
//	}
//
//}
