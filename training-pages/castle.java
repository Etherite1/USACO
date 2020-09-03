
/*
ID: xuhumph1
LANG: JAVA
PROB: castle

 */


import java.io.File;
import java.io.FileWriter;
import java.util.*;
import java.util.Map.Entry;
import java.util.stream.Collectors;
public class castle {
	static int numofrooms = 0;
	static int largestroom = 0;
	static String line4 = "";
	static int n;
	static int m;
	static ArrayList<String[]> line4s = new ArrayList<String[]>();
	static int anotherlargestroom;
	static ArrayList<ArrayList<int[]>> components = new ArrayList<ArrayList<int[]>>();

	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(new File("castle.in"));
		FileWriter bw = new FileWriter(new File("castle.out"));
		
		
		m = in.nextInt();
		n = in.nextInt();
		
		LinkedList<int[]> edges[][] = new LinkedList[n][m];
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				edges[i][j] = new LinkedList<int[]>();
			}
		}
		
		int[][] allwalls = new int[n][m];
		
		long start = System.nanoTime();
		//all adjacencies whilst removing walls
		for(int y = 0; y < n; y++)
			for(int x = 0; x < m; x++)
			{
				int current = in.nextInt();
				String[] walls = roomnumbers(current);
				allwalls[y][x] = current;

				if(!Arrays.asList(walls).contains("w") && !(x - 1 < 0))
					edges[y][x].add(new int[] {y, x-1});
				
				if(!Arrays.asList(walls).contains("e") && !(x + 1 >= m))
					edges[y][x].add(new int[] {y, x + 1});

				if(!Arrays.asList(walls).contains("n") && !(y - 1 < 0))
					edges[y][x].add(new int[] {y - 1, x});

				if(!Arrays.asList(walls).contains("s") && !(y + 1 >= n))
					edges[y][x].add(new int[] {y + 1, x});

			}
		long end = System.nanoTime();
		System.out.println(end - start + "        break");
		
		start = System.nanoTime();
		allrooms(edges);
		bw.write(numofrooms + "\n" + anotherlargestroom + "\n");
		
		part2(edges, allwalls);
		
		for(String[] a: line4s)
		{
			if(Integer.valueOf(a[1]) > largestroom) largestroom = Integer.valueOf(a[1]);
		}
		
		ArrayList<String[]> largest = new ArrayList<String[]>();
		
//		for (Map.Entry<String,Integer> entry : line4s.entrySet())  
//			if(Integer.valueOf(entry.getValue().toString()) == largestroom) largest.add(new String[] {(String) entry.getKey(), String.valueOf(entry.getValue())});
		
		for(String[] a: line4s)
			if(Integer.valueOf(a[1]) == largestroom) largest.add(a);

	    int tempy = 0;
	    int tempx = 51;
	    String tempdirec = "";

	    for(int i = 0; i < largest.size(); i++)
	    {
	    	String[] temp = largest.get(i)[0].split(" ");
	    	if(Integer.valueOf(temp[1]) < tempx)
	    	{
	    		tempx = Integer.valueOf(temp[1]);
	    		tempy = Integer.valueOf(temp[0]);
	    		tempdirec = temp[2];
	    	}
	    	else if (Integer.valueOf(temp[1]) == tempx)
	    	{
	    		if(Integer.valueOf(temp[0]) > tempy)
		    	{
		    		tempy = Integer.valueOf(temp[0]);
		    		tempdirec = temp[2];
		    	}
	    		else if (Integer.valueOf(temp[0]) == tempy)
	    		{
	    			if(temp[2].equals("N") && tempdirec.equals("E")) 
	    			{
	    				tempdirec = "N";
	    			}
	    		}
	    	}
	    }

	    
		
		end = System.nanoTime();
		System.out.println(end - start);
		
		bw.write(largestroom + "\n" + tempy + " " + tempx + " " + tempdirec + "\n");
		System.out.println(largestroom + "\n" + tempy + " " + tempx + " " + tempdirec + "\n");
//		System.out.println(sameComponent(new int[] {0,0}, new int[] {3, 3}));
		
		
//		end = System.nanoTime();
//		System.out.println(end - start);
		bw.close();
		in.close();
	}


	
	static void allrooms(LinkedList<int[]>[][] edges)
	{
		boolean[][] visited = new boolean[n][m];
		visited[0][0] = true;
		int[] start = new int[] {0, 0};
		numOfRooms(visited, edges, start);
		
		while(true)
		{
			int[] a = notVisited(visited);
			if (a[0] != -1)
			{
				numOfRooms(visited, edges, a);
			}
			else break;
		}

	}
	
	static void oneroom(LinkedList<int[]>[][] edges, int y, int x)
	{
		boolean[][] visited = new boolean[n][m];
		visited[y][x] = true;
		int[] start = new int[] {y, x};
		numOfRooms(visited, edges, start);
	}
	
	static void part2(LinkedList<int[]>[][] edges, int[][] allwalls)
	{
		long start = System.nanoTime();
		for(int y = 0; y < allwalls.length; y++)
			for(int x = 0; x < allwalls[y].length; x++)
			{
				String[] walls = roomnumbers(allwalls[y][x]);
				for(String wall : walls)
				{
					int old = largestroom;
					if(wall.equals("e") && !(x + 1 >= m) )
					{
						edges[y][x].add(new int[] {y, x + 1});
						edges[y][x + 1].add(new int[] {y, x});
						oneroom(edges, y, x);
						edges[y][x].remove(edges[y][x].size() - 1);
						edges[y][x + 1].remove(edges[y][x + 1].size() - 1);
						
						if(!(old > largestroom))
							line4s.add(new String[] {(y + 1) + " " + (x + 1) + " E", String.valueOf(largestroom)});
					}
					else if(wall.equals("n") && !(y - 1 < 0))
					{						
						edges[y][x].add(new int[] {y - 1, x});
						edges[y - 1][x].add(new int[] {y, x});
						oneroom(edges, y, x);
						edges[y][x].remove(edges[y][x].size() - 1);
						edges[y - 1][x].remove(edges[y - 1][x].size() - 1);

						if(!(old > largestroom))
							line4s.add(new String[] {(y + 1) + " " + (x + 1) + " N", String.valueOf(largestroom)});
					}
					
				}
			}
		long end = System.nanoTime();
		System.out.println(end - start);
	}
	
	static void numOfRooms(boolean[][] visited, LinkedList<int[]>[][] adj, int[] start)
	{
		int tlr = 1;  //templargestroom
		
		Queue<int[]> queue = new LinkedList<int[]>();
		queue.add(start);
		visited[start[0]][start[1]] = true;
		while(queue.size() > 0)
		{
			for(int[] adjnode: adj[queue.peek()[0]][queue.peek()[1]])
			{
				if(visited[adjnode[0]][adjnode[1]]) continue;
				visited[adjnode[0]][adjnode[1]] = true;
				queue.add(adjnode);
				tlr++;
			}
			queue.poll();
		}
		numofrooms++;
		
		if(tlr > anotherlargestroom)
			anotherlargestroom = tlr;

		largestroom = tlr;

		return;
	}
	
//	static boolean sameComponent(int[] start, int[] target)
//	{
//		int a = 0;
//		outerloop:
//		for(int i = 0; i < components.size(); i++)
//		{
//			for(int j = 0; j < components.get(i).size(); j++)
//			{
//				int[] temp = components.get(i).get(j);
//				if(start[0] == temp[0] && start[1] == temp[1]) 
//				{
//					a = i;
//					break outerloop;
//				}
//			}
//		}
//		
//		for(int i = 0; i < components.get(a).size(); i++)
//		{
//			int[] temp = components.get(a).get(i);
//			if(target[0] == temp[0] && target[1] == temp[1]) 
//			{
//				return true;
//			}
//		}
//		
//		return false;
//	}
//	
//	static void componentCalc(boolean[][] visited, LinkedList<int[]>[][] adj, int[] start)
//	{
//		ArrayList<int[]> component = new ArrayList<int[]>();
//		Queue<int[]> queue = new LinkedList<int[]>();
//		queue.add(start);
//		component.add(start);
//		visited[start[0]][start[1]] = true;
//		while(queue.size() > 0)
//		{
//			for(int[] adjnode: adj[queue.peek()[0]][queue.peek()[1]])
//			{
//				if(visited[adjnode[0]][adjnode[1]]) continue;
//				visited[adjnode[0]][adjnode[1]] = true;
//				queue.add(adjnode);
//				component.add(adjnode);
//			}
//			queue.poll();
//		}
//		
//		components.add(component);
//		return;
//	}
//	
	static int[] notVisited(boolean[][] visited)
	{
		for(int x = 0; x < visited.length; x++)
			for(int y = 0; y < visited[x].length; y++)
			{
				if(!visited[x][y]) 
					return new int[] {x, y};
			}
		
		return new int[] {-1, -1};
	}
	
	//finds wall directions of input numbers
	static String[] roomnumbers(int n)
	{
		String temp = "";
		while(n > 0)
		{
			if(n - 8 >= 0)
			{
				n-=8;
				temp += "s";
			}
			else if(n - 4 >= 0)
			{
				n-=4;
				temp += "e";
			}
			else if(n - 2 >= 0)
			{
				n-=2;
				temp += "n";
			}
			else if(n - 1 >= 0)
			{
				n-=1;
				temp += "w";
			}
		}
		
		return temp.split("");	
	}

}
