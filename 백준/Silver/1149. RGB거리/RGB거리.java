import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] input = br.readLine().split(" ");
		int N = Integer.parseInt(input[0]);
		int[][] map = new int[N][3];

		for (int i = 0; i < N; i++) {
			String[] temp = br.readLine().split(" ");
			for (int j = 0; j < 3; j++) {
				map[i][j] = Integer.parseInt(temp[j]);
			}
		}

		int[][] dp = new int[N][3];
		dp[0][0] = map[0][0];
		dp[0][1] = map[0][1];
		dp[0][2] = map[0][2];

		for (int i = 1; i < N; i++) {
			dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + map[i][0];
			dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + map[i][1];
			dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + map[i][2];
		}

		int answer = Math.min(dp[N - 1][0], Math.min(dp[N - 1][1], dp[N - 1][2]));
		bw.write(answer + "");
		bw.flush();
	}
}
