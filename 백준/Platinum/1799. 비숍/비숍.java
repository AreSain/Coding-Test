import java.io.*;
import java.util.*;

public class Main {
	public static int[] dx = { 1, 1 }; // 오른쪽 위, 오른쪽 아래
	public static int[] dy = { -1, 1 };
	public static int answer = 0, N, topX, bottomX;
	public static int[][] map;
	public static int[] top, bottom;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] input = br.readLine().split(" ");
		N = Integer.parseInt(input[0]);

		map = new int[N][N];
		top = new int[2 * N - 1];
		bottom = new int[2 * N - 1];

		for (int i = 0; i < N; i++) {
			String[] temp = br.readLine().split(" ");
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(temp[j]);
			}
		}

		roop(0, 0, 0, 0); // 흑
		int blackMax = answer;
		answer = 0;
		roop(0, 0, 0, 1); // 백
		int whiteMax = answer;

		// 결과 출력
		bw.write(blackMax + whiteMax + "");
		bw.flush();
	}

	public static void roop(int y, int x, int count, int color) {
		if (y >= N) { // 끝났을 때
			if (count > answer)
				answer = count;
			return;
		}

		// 현재 칸의 색 확인
		if ((y + x) % 2 != color) {
			// 다음 칸으로 이동
			if (x + 1 >= N)
				roop(y + 1, 0, count, color);
			else
				roop(y, x + 1, count, color);
			return;
		}

		if (map[y][x] == 0 || check(y, x) == false) {
			if (x + 1 >= N)
				roop(y + 1, 0, count, color);
			else
				roop(y, x + 1, count, color);
		} else {
			top[topX] = 1;
			bottom[bottomX] = 1;
			int tempTX = topX, tempBX = bottomX;

			if (x + 1 >= N)
				roop(y + 1, 0, count + 1, color);
			else
				roop(y, x + 1, count + 1, color);

			top[tempTX] = 0;
			bottom[tempBX] = 0;

			if (x + 1 >= N)
				roop(y + 1, 0, count, color);
			else
				roop(y, x + 1, count, color);
		}
	}

	public static boolean check(int y, int x) {
		int distanceToTop = y; // 현재 위치에서 오른쪽 위까지
		topX = x + distanceToTop;

		// 아래쪽 끝점 계산
		int distanceToBottom = N - 1 - y; // 현재 위치에서 오른쪽 아래까지
		bottomX = x + distanceToBottom;

		if (topX >= 2 * N - 1 || bottomX >= 2 * N - 1 || top[topX] == 1 || bottom[bottomX] == 1) {
			return false;
		}
		return true;
	}
}
