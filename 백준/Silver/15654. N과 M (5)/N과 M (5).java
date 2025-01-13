import java.util.*;
import java.io.*;

public class Main {
	static int[] arr;
	static int n, m;
	static boolean[] visited;
	static int[] ans;
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

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
		bw.flush();
	}

	public static void backTracking(int turn) throws IOException {
		if (turn == m) {
			for (int i = 0; i < m; i++){
				bw.write(ans[i] + " ");
			}
			bw.append("\n");
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