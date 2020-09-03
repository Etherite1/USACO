/*
ID: xuhumph1
LANG: JAVA
TASK: friday
*/

//package everything;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.LinkedHashMap;
import java.util.Map;

public class friday {
	
	public static String[] daysOfWeek = new String[7];
	public static int day = 1;
	public static int month = 1;
	public static int year = 1900;
	public static String dayOfWeek = "monday";
	
	
	public static void main(String[] args) throws Exception {
		String filename = "friday.in";
		File file = new File(filename);
		FileReader myread = new FileReader(file);
		BufferedReader br = new BufferedReader(myread);
		String filename2 = "friday.out";
		File file2 = new File(filename2);
		FileWriter myread2 = new FileWriter(file2);
		
		String read = br.readLine();
		int n = Integer.valueOf(read);
		
		Map<String, Integer> numOfThirteenths = new LinkedHashMap<String, Integer>();
		numOfThirteenths.put("saturday", 0);
		numOfThirteenths.put("sunday", 0);
		numOfThirteenths.put("monday", 0);
		numOfThirteenths.put("tuesday", 0);
		numOfThirteenths.put("wednesday", 0);
		numOfThirteenths.put("thursday", 0);
		numOfThirteenths.put("friday", 0);
		
		daysOfWeek[0] = "monday";
		daysOfWeek[1] = "tuesday";
		daysOfWeek[2] = "wednesday";
		daysOfWeek[3] = "thursday";
		daysOfWeek[4] = "friday";
		daysOfWeek[5] = "saturday";
		daysOfWeek[6] = "sunday";
		
		while(year <= 1900 + n - 1) {
			if(day == 31 && month == 12 && year == 1900 + n - 1) {
				break;
			}
			dayAdder();
			if (thirteenthChecker(day, dayOfWeek) == true) {
				numOfThirteenths.replace(dayOfWeek, numOfThirteenths.get(dayOfWeek) + 1);
			}
			else if(day == 13) {
				try{
					numOfThirteenths.replace(dayOfWeek, numOfThirteenths.get(dayOfWeek) + 1);
				}                
				catch(Exception NullPointerException) {
					continue;       
				}
			}
			
		}
		
		String temp = "";
		for (Map.Entry<String,Integer> entry : numOfThirteenths.entrySet())  
	           temp += (+ entry.getValue() + " "); 	
		
		temp = temp.substring(0, temp.length() - 1);
		temp += '\n';
		
		myread2.write(temp);
		myread2.close();
		br.close();
	}
	

	
	public static boolean leapYearTester(int year) {
		if( year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		
		if(year % 4 == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	
	public static boolean thirteenthChecker(int day, String weekday) {
		if(day == 13 && weekday == "friday") {
			return true;
		}
		else {
			return false;
		}
	}
	
	public static int index(String[] a, String b){
		for(int i = 0; i < a.length; i ++) {
			if (a[i].equals(b)){
				return i;
			}
		}
		
		return -1;
	}
	
	public static returned dayAdder() {
		String[] months = new String[12];
		months[0] = "january";
		months[1] = "february";
		months[2] = "march";
		months[3] = "april";
		months[4] = "may";
		months[5] = "june";
		months[6] = "july";
		months[7] = "august";
		months[8] = "september";
		months[9] = "october";
		months[10] = "november";
		months[11] = "december";
		
		Map<String, Integer> daysInMonth = new LinkedHashMap<String, Integer>();
		daysInMonth.put("january", 31);
		daysInMonth.put("february", 28);
		daysInMonth.put("march", 31);
		daysInMonth.put("april", 30);
		daysInMonth.put("may", 31);
		daysInMonth.put("june", 30);
		daysInMonth.put("july", 31);
		daysInMonth.put("august", 31);
		daysInMonth.put("september", 30);
		daysInMonth.put("october", 31);
		daysInMonth.put("november", 30);
		daysInMonth.put("december", 31);

		Map<String, Integer> leapyeardaysInMonth = new LinkedHashMap<String, Integer>();
		leapyeardaysInMonth.put("january", 31);
		leapyeardaysInMonth.put("february", 29);
		leapyeardaysInMonth.put("march", 31);
		leapyeardaysInMonth.put("april", 30);
		leapyeardaysInMonth.put("may", 31);
		leapyeardaysInMonth.put("june", 30);
		leapyeardaysInMonth.put("july", 31);
		leapyeardaysInMonth.put("august", 31);
		leapyeardaysInMonth.put("september", 30);
		leapyeardaysInMonth.put("october", 31);
		leapyeardaysInMonth.put("november", 30);
		leapyeardaysInMonth.put("december", 31);
		
		if (leapYearTester(year) == true){
			if (day == 31 && month == 12) {
				day = 1;
				month = 1;
				year += 1;
			}
			else if (day == leapyeardaysInMonth.get(months[month - 1])) {
				day = 1;
				month += 1;
			}
			else {
				day += 1;
			}
			try {
				dayOfWeek = daysOfWeek[index(daysOfWeek, dayOfWeek) + 1];
			}
			catch (Exception IndexOutOfBounds) {
				dayOfWeek = daysOfWeek[0];
			}}
			
		else {
			if (day == 31 && month == 12) {
				day = 1;
				month = 1;
				year += 1;
			}
			else if(day == daysInMonth.get(months[month - 1])) {
				day = 1;
				month += 1;
			}
			else {
				day += 1;	
			}
			
		try{
			dayOfWeek = daysOfWeek[index(daysOfWeek, dayOfWeek)  + 1];
		}
		catch (Exception IndexOutOfBounds) {
			dayOfWeek = daysOfWeek[0];
		}
	}
	
		returned r = new returned(day, month, year, dayOfWeek);
	
		return r;
}
	
static class returned {
	public int day;
	public int month;
	public int year;
	public String dayOfWeek;
	
	public returned(int d, int m, int y, String dow){
		day = d;
		month = m;
		year = y;
		dayOfWeek = dow;
	}
}}
	

