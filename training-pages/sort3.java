/*
ID: xuhumph1
LANG: JAVA
PROB: sort3
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class sort3 {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new FileReader(new File("sort3.in")));
		FileWriter bw = new FileWriter(new File("sort3.out"));
		
		int n = in.nextInt();
		int swaps = 0;
		
		int[] seq = new int[n];
		int numofones = 0;
		int numoftwos = 0;
		int numofthrees = 0;
		for(int i = 0; i < n; i++)
		{
			seq[i] = in.nextInt();
			if(seq[i] == 1) numofones++;
			if(seq[i] == 2) numoftwos++;
			if(seq[i] == 3) numofthrees++;
		}
		
		int[] bucket1 = new int[numofones];
		int[] bucket2 = new int[numoftwos];
		int[] bucket3 = new int[numofthrees];
		
		for(int i = 0; i < numofones; i++)
			bucket1[i] = seq[i];
		
		for(int i = numofones; i < numofones + numoftwos; i++)
			bucket2[i - numofones] = seq[i];
		
		for(int i = numofones + numoftwos; i < n; i++)
			bucket3[i - numofones - numoftwos] = seq[i];
		
		boolean temp = false;
		
		for(int i = 0; i < bucket1.length; i++)
		{
			if(bucket1[i] == 3) 
			{
				for(int j = 0; j < bucket3.length; j++)
				{
					if(bucket3[j] == 1)
					{
						bucket1[i] = 1;
						bucket3[j] = 3;
						swaps++;
						temp = true;
						break;
					}
				}
				if(!temp)
				{
					for(int j = 0; j < bucket2.length; j++)
					{
						if(bucket2[j] == 1)
						{
							bucket1[i] = 1;
							bucket2[j] = 3;
							swaps++;
							break;
						}
					}
				}
			}
			
			temp = false;
		}
		
		for(int i = 0; i < bucket1.length; i++)
		{
			if(bucket1[i] == 2) 
			{
				for(int j = 0; j < bucket2.length; j++)
				{
					if(bucket2[j] == 1)
					{
						bucket1[i] = 1;
						bucket2[j] = 2;
						swaps++;
						temp = true;
						break;
					}
				}
				if(!temp)
				{
					for(int j = 0; j < bucket3.length; j++)
					{
						if(bucket3[j] == 1)
						{
							bucket1[i] = 1;
							bucket3[j] = 2;
							swaps++;
							break;
						}
					}
				}
			}
			
			temp = false;
		}
		
		for(int i = 0; i < bucket2.length; i++)
		{
			if(bucket2[i] == 3) 
			{
				for(int j = 0; j < bucket3.length; j++)
				{
					if(bucket3[j] == 2)
					{
						bucket2[i] = 2;
						bucket3[j] = 3;
						swaps++;
						break;
					}
				}
			}
		}
		
		
		bw.write(swaps + "\n");
		System.out.println(swaps);
		bw.close();
		in.close();
	}
	
}
