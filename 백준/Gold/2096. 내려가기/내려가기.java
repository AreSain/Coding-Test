import java.util.*;
import java.io.*;

class Main {
	public static int n, answerMin = 100000, answerMax = 0;
	public static int[][] map, dpMin, dpMax;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String input = br.readLine();
		String[] temp = input.split(" ");

		n = Integer.parseInt(temp[0]);
		map = new int[n][3];
		dpMin = new int[n + 1][3];
		dpMax = new int[n + 1][3];


		for (int i = 0; i < n; i++) {
			input = br.readLine();
			temp = input.split(" ");
			for (int j = 0; j < 3; j++) {
				int tmp = Integer.parseInt(temp[j]);
				map[i][j] = tmp;
			}
		}

		dpMinRoop();
		dpMaxRoop();

		answerMax = Math.max(dpMax[n][0], Math.max(dpMax[n][1], dpMax[n][2]));
		answerMin = Math.min(dpMin[n][0], Math.min(dpMin[n][1], dpMin[n][2]));

		bw.write( answerMax+ " " + answerMin);
		bw.flush();
	}

	public static void dpMinRoop() {
		dpMin[1][0] = map[0][0];
		dpMin[1][1] = map[0][1];
		dpMin[1][2] = map[0][2];

		for (int i = 1; i < n; i++) {
			dpMin[i + 1][0] = Math.min(dpMin[i][0], dpMin[i][1]) + map[i][0];
			dpMin[i + 1][1] = Math.min(Math.min(dpMin[i][0], dpMin[i][1]), dpMin[i][2]) + map[i][1];
			dpMin[i + 1][2] = Math.min(dpMin[i][1], dpMin[i][2]) + map[i][2];
		}
	}

	public static void dpMaxRoop() {
		dpMax[1][0] = map[0][0];
		dpMax[1][1] = map[0][1];
		dpMax[1][2] = map[0][2];

		for (int i = 1; i < n; i++) {
			dpMax[i + 1][0] = Math.max(dpMax[i][0], dpMax[i][1]) + map[i][0];
			dpMax[i + 1][1] = Math.max(Math.max(dpMax[i][0], dpMax[i][1]), dpMax[i][2]) + map[i][1];
			dpMax[i + 1][2] = Math.max(dpMax[i][1], dpMax[i][2]) + map[i][2];
		}
	}
}