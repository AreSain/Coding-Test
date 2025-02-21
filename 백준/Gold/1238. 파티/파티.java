import java.util.*;
import java.io.*;

class Main {
	public static int n, m, x;
	public static int[][] map, reverseMap;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());

		map = new int[n + 1][n + 1];
		reverseMap = new int[n + 1][n + 1];

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			map[a][b] = c;
			reverseMap[b][a] = c;
		}

		int[] toTown = dijkstra(map);
		int[] fromTown = dijkstra(reverseMap);

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = Math.max(ans, toTown[i] + fromTown[i]);
		}

		bw.write(ans + "");
		bw.flush();
	}

	static int[] dijkstra(int[][] inputMap) {
		int[] dp = new int[n + 1];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[x] = 0;

		PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o.cost));
		pq.add(new Node(x, 0));

		while (!pq.isEmpty()) {
			Node cur = pq.poll();
			int now = cur.index;

			for (int i = 1; i <= n; i++) {
				if (inputMap[now][i] > 0 && dp[i] > dp[now] + inputMap[now][i]) {
					dp[i] = dp[now] + inputMap[now][i];
					pq.add(new Node(i, dp[i]));
				}
			}
		}

		return dp;
	}

	static class Node {
		int index, cost;
		public Node(int index, int cost) {
			this.index = index;
			this.cost = cost;
		}
	}
}
