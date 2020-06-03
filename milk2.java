/*
ID: xuhumph1
LANG: JAVA
TASK: milk2
*/

//package everything;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class milk2 {

	public static void main(String[] args) throws Exception {
		String filename = "milk2.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);
		String filename2 = "milk2.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		List<String> a = new ArrayList<>();
		int b = Integer.valueOf(br.readLine());
		
		for(int i = 0; i < b; i++) {
			a.add(br.readLine());
		}
		List<String[]> c = new ArrayList();
		ArrayList<int[]> d = new ArrayList();
		
 		for(int i = 0; i < a.size(); i++) {
			c.add(a.get(i).split(" "));
		}
 		
 		for(int i = 0; i < c.size(); i++) {
 			int[] arr = new int[2];
 			arr[0] = Integer.valueOf(c.get(i)[0]);
 			arr[1] = Integer.valueOf(c.get(i)[1]);
 			d.add(arr);
 		}
 		
 		Collections.sort(d, new Comparator<int[]>() {
 	         public int compare(int[] a, int[] b) {
 	              if(a[0] - b[0]==0) //if equals
 	              {
 	                  return a[1]-b[1];//recompare 
 	              }
 	              else
 	                  return a[0]-b[0];
 	         }
 	    });
 		
 		if(d.size() == 1) {
 			int largest = d.get(0)[1] - d.get(0)[0];
 			int smallest = 0;
 			myread2.write(largest + " " + smallest +"\n");
 	 		br.close();
 	 		myread2.close();
 		}
 		else {

 		int idx1 = 0;
 		int idx2 = 1;
 		int[] replacement = new int[2];
 		int size = d.size();
 		for(int i = 0; i < d.size() - 1; i++) 
 		{
// 			if(i == 27)
// 			{
// 				System.out.println("here");
// 			}
 			if( i >= d.size() - 1) {
 				break;
 			}
 			if(contains(d.get(i), d.get(i + 1))) {
 				d.remove(i + 1); 
 				i -= 1;
 			}
 				
 			
 			else if(overlapping(d.get(i), d.get(i + 1))) {
 				try {
 					replacement[0] = d.get(i)[0];
 	 				replacement[1] = d.get(i + 1)[1];
 	 				d.remove(i);
 	 				d.remove(i);
 	 				int[] newint = new int[2];
 	 				newint[0] = replacement[0];
 	 				newint[1] = replacement[1];
 	 				d.add(i, newint);
 	 				i -= 1;
 				}
 				catch(Exception IndexOutOfBounds) {
 					break;
 				}
 				
 			}
 		}
 		
 		for(int i = 0; i < d.size(); i++) {
 			if(d.get(i)[0] < 500) {
 				System.out.println("");
 			}
 		}
 		
 		Collections.sort(d, new Comparator<int[]>() {
	         public int compare(int[] a, int[] b) {
	              if(a[0] - b[0]==0) //if equals
	              {
	                  return a[1]-b[1];//recompare 
	              }
	              else
	                  return a[0]-b[0];
	         }
	    });
 		
 		
 		int largest = -1;
 		size = d.size();
 		for(int i = 0; i < size; i++) {
 			if(d.get(i)[1] - d.get(i)[0] > largest) {
 				largest = d.get(i)[1] - d.get(i)[0];
 			}
 		}

 		int smallest = 0;
 		for(int i = 0; i < d.size() - 1; i++) {
 			if(d.get(i + 1)[0] - d.get(i)[1] > smallest) {
 				smallest = d.get(i + 1)[0] - d.get(i)[1];
 				if(smallest == 1294) {
 					System.out.println("");
 				}
 			}
 		}
 		

		myread2.write(largest + " " + smallest +"\n");
 		br.close();
 		myread2.close();
 		
 		}}

 		
		
	
	
	public static boolean contains(int[] ipt1, int[] ipt2) {
		if(ipt1[0] < ipt2[0] && ipt1[1] >= ipt2[1]) {
			return true;
		
		}
		else {
			return false;
		}
	}
	
	public static boolean overlapping(int[] ipt1, int[] ipt2) {
		if (ipt1[1] >= ipt2[0]) {
			return true;
		}
		else if(ipt1[0] == ipt2[0]) return true;
		else {
			return false;
		}
	}
	
//		public static ArrayList<int[]> sorted(ArrayList<int[]> ipt) {
//			ArrayList<int[]> opt = new ArrayList<int[]>();
//			int min = -1;
//			for(int i = 0; i < ipt.size(); i++) {
//				for(int j = i + 1; j < ipt.size() - i - 1; i++) {
//					if(ipt.get(i)[0] > ipt.get(j)[0]) {
//						int[] temp = ipt.get(i);
//						ipt.set(i, ipt.get(j));
//						ipt.set(j, temp);
//					}
//					else if(ipt.get(i)[0] == ipt.get(j)[0]) {
//						if(ipt.get(i)[1] > ipt.get(j)[1]) {
//							int[] temp = ipt.get(i);
//							ipt.set(i, ipt.get(j));
//							ipt.set(j, temp);
//						}
//					}
//				}
//				
//			}
//			
//			return ipt;
//		}

}



