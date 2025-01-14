import java.io.*;

class Main {
	static int N, M;
	static int[][] map;
	static int[][] dp;
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] input = br.readLine().split(" ");
		N = Integer.parseInt(input[0]);
		M = Integer.parseInt(input[1]);
		map = new int[N][N];

		for (int i = 0; i < N; i++) {
			input = br.readLine().split(" ");
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(input[j]);
			}
		}

		dp = dpMap();

		for (int i = 0; i < M; i++) {
			solve(br.readLine().split(" "));
		}

		bw.flush();
	}

	public static void solve(String[] input) throws IOException {
		int x1, x2, y1, y2, ans = 0;

		y1 = Integer.parseInt(input[0]) - 1;
		x1 = Integer.parseInt(input[1]) - 1;
		y2 = Integer.parseInt(input[2]) - 1;
		x2 = Integer.parseInt(input[3]) - 1;

		for (int i = x1; i <= x2; i++) {
			if (y1 == 0) {
				ans += dp[y2][i];
			} else {
				ans += dp[y2][i] - dp[y1 - 1][i];
			}
		}

		bw.write(ans + "\n");
	}

	public static int[][] dpMap() {
		int[][] dpMap = new int[N][N];

		for (int i = 0; i < N; i++) {
			dpMap[0][i] = map[0][i];
		}

		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dpMap[i][j] = dpMap[i - 1][j] + map[i][j];
			}
		}

		return dpMap;
	}
}
