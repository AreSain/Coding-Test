import java.util.*;
import java.io.*;

public class Main {
	static int[] arr;
	static int n, m;
	static boolean[] visited;
	static int[] ans;
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static LinkedHashSet<String> set = new LinkedHashSet<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);

		arr = new int[n];
		ans = new int[n];
		visited = new boolean[n];

		input = br.readLine().split(" ");
		for (int i = 0; i < n; i++){
			arr[i] = Integer.parseInt(input[i]);
		}
		Arrays.sort(arr);

		backTracking(0);
		for (String s : set){
			bw.write(s);
		}
		bw.flush();
	}

	public static void backTracking(int turn) throws IOException {
		if (turn == m) {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < m; i++){
				sb.append(ans[i] + " ");
			}
			sb.append("\n");
			set.add(sb.toString());
			return;
		}
		for (int i = 0; i < n; i++){
			if (!visited[i]){
				visited[i] = true;
				ans[turn] = arr[i];
				backTracking(turn + 1);
				visited[i] = false;
			}
		}
	}
}