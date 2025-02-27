import java.util.*;
import java.io.*;

class Main {
	public static int n, m;
	public static int[][] map;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String input = br.readLine();
		String[] temp = input.split(" ");
		n = Integer.parseInt(temp[0]);
		input = br.readLine();
		temp = input.split(" ");
		m = Integer.parseInt(temp[0]);

		map = new int[n + 1][n + 1];

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (i == j)
					map[i][j] = 0;
				else
					map[i][j] = 10000000;
			}
		}

		for (int i = 0; i < m; i++) {
			input = br.readLine();
			temp = input.split(" ");
			int a = Integer.parseInt(temp[0]);
			int b = Integer.parseInt(temp[1]);
			int c = Integer.parseInt(temp[2]);

			map[a][b] = Math.min(c, map[a][b]);
		}

		floydWarshall();

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (map[i][j] == 10000000)
					map[i][j] = 0;
				if (j != n)
					bw.write(map[i][j] + " ");
				else
					bw.write(map[i][j] + "");
			}
			if (i != n)
				bw.write("\n");
			else
				;
			bw.flush();
		}
	}

	public static void floydWarshall() {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				for (int k = 1; k < n + 1; k++) {
					map[j][k] = Math.min(map[j][k], map[j][i] + map[i][k]);
				}
			}
		}
	}
}