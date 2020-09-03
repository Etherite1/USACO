/*
ID: xuhumph1
LANG: JAVA
TASK: transform
*/



import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class transform {

	public static void main(String[] args) throws Exception {
		String filename = "transform.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);
		String filename2 = "transform.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		int numOfLines = Integer.valueOf(br.readLine());
		ArrayList<String> a = new ArrayList<String>();
		for(int i = 0; i < numOfLines * 2; i++) {
			a.add(br.readLine());
		}
		
		ArrayList<String[]> start = new ArrayList<String[]>();
		for(int i = 0; i < numOfLines; i ++) {
			start.add(a.get(i).split(""));
		}
		
		ArrayList<String[]> end = new ArrayList<String[]>();
		for(int i = numOfLines; i < numOfLines * 2; i ++) {
			end.add(a.get(i).split(""));
		}
		
		ArrayList<String> newstart = new ArrayList<String>();
		ArrayList<String> newend = new ArrayList<String>();
		
		for(int i = 0; i < numOfLines; i++) {
			for(int j = 0; j < numOfLines; j++) {
				newstart.add(start.get(i)[j]);
			}
		}
		
		for(int i = 0; i < numOfLines; i++) {
			for(int j = 0; j < numOfLines; j++) {
				newend.add(end.get(i)[j]);
			}
		}
		myread2.write(main(newstart, numOfLines, newend) + "\n");
		myread2.close();
		br.close();
		
	}
	public static String[] split(String word) {
		return word.split("");
	}
	
	@SuppressWarnings("unchecked")
	public static boolean rotate90(ArrayList start, int numOfLines, ArrayList end, int times) {
		ArrayList newList = new ArrayList();
		int temp = numOfLines - 1;
		while(temp >= 0) {
			for(int i = start.size() - 1; i > -1; i += -1 * numOfLines) {
				newList.add(start.get(i - temp));
			}
			temp -= 1;
		}
		if(times == 1) {
			if(compare(newList, end)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (times == 2) {
			if(rotate90(newList, numOfLines, end, 1)) {
				return true;
			}
			else {
				return false;
			}
			
		}
		else if(times == 3) {
			if(rotate90(newList, numOfLines, end, 2)) {
				return true;
			}
			else {
				return false;
			}
		}
		
		return false;
	}
	

public static boolean reflect(ArrayList start, int numOfLines, ArrayList end) {

	ArrayList lst = new ArrayList();
	int temp = 0;
	while(temp < numOfLines * numOfLines) {
		for(int i = numOfLines - 1; i >= 0; i --) {
			lst.add(start.get(i + temp));
		}
		
		temp += numOfLines;
	}
	temp = 0;

	if(compare(lst, end)) {
		return true;
	}
	else {
		return false;
	}
}

public static ArrayList reflectreturnlist(ArrayList start, int numOfLines, ArrayList end) {
	ArrayList lst = new ArrayList();
	int temp = 0;
	while(temp < numOfLines * numOfLines) {
		for(int i = numOfLines - 1; i >= 0; i --) {
			lst.add(start.get(i + temp));
		}
		
		temp += numOfLines;
	}
	temp = 0;
	
	return lst;
}
	
public static boolean combo(ArrayList start, int numOfLines, ArrayList end) {
	ArrayList lst = reflectreturnlist(start, numOfLines, end);
	boolean a = rotate90(lst, numOfLines, end, 1);
	boolean b = rotate90(lst, numOfLines, end, 2);
	boolean c = rotate90(lst, numOfLines, end, 3);
	if(a || b || c) {
		return true;
	}
	else { 
		return false;
	}
}

public static String main(ArrayList start, int numOfLines, ArrayList end) {
	if (rotate90(start, numOfLines, end, 1)) {
        return "1";}
	else if (rotate90(start, numOfLines, end, 2) )
        return "2";
	else if(rotate90(start, numOfLines, end, 3))
        return "3";
    else if(reflect(start, numOfLines, end))
        return "4";
    else if(combo(start, numOfLines, end))
        return "5";
    else if(compare(start, end)) {
    return "6";}
    else {
        return "7";
}}
	
public static boolean compare(ArrayList a, ArrayList b) {
	
		
	for(int i = 0; i < a.size(); i++) {
		try {
			
		if (a.get(i).equals(b.get(i))){
			continue;
		}
		else {return false;}
		}
		catch(Exception IndexOutOfBounds) {
			break;
		}
	}
	return true;
}
	
		

}
