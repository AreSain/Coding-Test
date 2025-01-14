import java.io.*;

class Main {
	static int N, ans = 0;
	static int[] map, dp;
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] input = br.readLine().split(" ");
		N = Integer.parseInt(input[0]);
		map = new int[N];
		dp = new int[N];

		input = br.readLine().split(" ");
		for (int i = 0; i < N; i++) {
			map[i] = Integer.parseInt(input[i]);
		}

		dp[0] = 1;

		solve();

		for (int i = 0; i < N; i++) {
			if (ans < dp[i]) {
				ans = dp[i];
			}
		}
		bw.write(ans + "");
		bw.flush();
	}

	public static void solve() {
		for (int i = 0; i < N; i++) {
			dp[i] = 1;

			for (int j = 0; j < i; j++) {
				if (map[j] < map[i] && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
}
