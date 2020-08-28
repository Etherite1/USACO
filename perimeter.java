import java.io.*;
import java.util.*;
public class perimeter 
{
	
	static int n;
	static long timing = 0;
	static long timing2 = 0;
	static ArrayList<int[]> largeid = new ArrayList<int[]>();

	public static void main(String[] args) throws Exception
	{
		long start = System.nanoTime();
		BufferedReader br = new BufferedReader(new FileReader("perimeter.in"));
		FileWriter bw = new FileWriter(new File("perimeter.out"));
		
		n = Integer.valueOf(br.readLine());
		
		int[][] product = new int[n][n];
		LinkedList<int[]> edges[][] = new LinkedList[n][n];
		
		for(int i = 0; i < n; i++)
		{
			String[] temp = br.readLine().split("");
			for(int j = 0; j < n; j++)
			{
				if(temp[j].equals("#")) product[i][j] = 1;
				edges[i][j] = new LinkedList<int[]>();
			}
		}


		for(int x = 0; x < n; x++)
			for(int y = 0; y < n; y++)
			{
				if(product[x][y] == 0) continue;
				if(x - 1 >= 0) 
					if(product[x - 1][y] == 1)
						edges[x][y].add(new int[] {x - 1, y});
				if(x + 1 < n) 
					if(product[x + 1][y] == 1)
						edges[x][y].add(new int[] {x + 1, y});
				if(y - 1 >= 0)
					if(product[x][y - 1] == 1)
						edges[x][y].add(new int[] {x, y - 1});
				if(y + 1 < n)
					if(product[x][y + 1] == 1)
						edges[x][y].add(new int[] {x, y + 1});
			}

		int[] ret = find(product, edges);
		
		
		bw.write(ret[0] + " " + ret[1] + "\n");
		bw.close();
		
		System.out.println(ret[0] + " " + ret[1]);
		long end = System.nanoTime();
		System.out.println(end - start);
	}
	
	static int[] find(int[][] product, LinkedList<int[]> edges[][]) 
	{
		int[][] id = new int[n][n];
		
		long areastart = System.nanoTime();
		int area = bfs(product, edges, id);
		long areaend = System.nanoTime();
		long peristart = System.nanoTime();
		int perimeter = findperi(edges, id);
		long periend = System.nanoTime();
		
		System.out.println("area: " + (areaend - areastart) + ", perimeter: " + (periend - peristart));
		System.out.println("just search: " + timing);
		
		return new int[] {area, perimeter};
	}
	
	static int findperi(LinkedList<int[]> edges[][], int[][] id)
	{
		boolean[][] visited = new boolean[n][n];

		for(int i = 0; i < largeid.size(); i++)
			if(largeid.get(i)[1] < largeid.get(largeid.size() - 1)[1]) 
			{
				largeid.remove(i);
				i--;
			}
		
		HashSet<Integer> largeids = new HashSet<Integer>();
		for(int[] i : largeid) largeids.add(i[0]);
		
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		for(int x = 0; x < n; x++)
		{
			for(int y = 0; y < n; y++)
			{
				if(!largeids.contains(id[x][y]) || visited[x][y]) continue;
				visited[x][y] = true;
				if(!map.containsKey(id[x][y])) map.put(id[x][y], 0);
				map.put(id[x][y], map.get(id[x][y]) + (4 - edges[x][y].size()));
			}
		}
		
		int smallest = Integer.MAX_VALUE;
		
		for(int key : map.keySet())
		{
			if(map.get(key) < smallest) smallest = map.get(key);
		}
		
		return smallest;
		
	}
	
	static int bfs(int[][] product, LinkedList<int[]> edges[][], int[][] id)
	{
		Queue<int[]> q = new LinkedList<int[]>();
		boolean[][] visited = new boolean[n][n];
		int largest = -1;
		int idnum = 0;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(visited[i][j] || product[i][j] == 0) 
					continue;
				
				int[] start = new int[] {i, j};
				int temparea = 1;
				idnum++;
				q.add(start);
				id[start[0]][start[1]] = idnum;
				visited[start[0]][start[1]] = true;
				
				long stt = System.nanoTime();
				
				while(!q.isEmpty())
				{
					int[] temp = q.poll();
					for(int[] adjnode : edges[temp[0]][temp[1]])
					{
						if(visited[adjnode[0]][adjnode[1]]) continue;
						visited[adjnode[0]][adjnode[1]] = true;
						q.add(adjnode); 
						temparea++;
						id[adjnode[0]][adjnode[1]] = idnum;
					}
				}
				
				long end = System.nanoTime();
				timing += (end - stt);
				
				if(temparea >= largest) 
				{
					largest = temparea;
					largeid.add(new int[] {idnum, temparea});
				}
			}
		}
		
		return largest;
	}
}

