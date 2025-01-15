import java.io.*;

public class Main {
	static int[] mapCol;
	static int N, ans;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] input = br.readLine().split(" ");
		N = Integer.parseInt(input[0]);

		mapCol = new int[N];

		backTracking(0);

		bw.write(ans + "");
		bw.flush();
	}

	public static void backTracking(int index) {
		if (index == N) {
			ans++;
			return;
		}

		for (int i = 0; i < N; i++) {
			mapCol[index] = i;
			if (check(index) == true) {
				backTracking(index + 1);
			}
		}
	}

	public static boolean check(int index) {
		for (int i = 0; i < index; i++) {
			// index 가로 mapCol[index] 세로 (index, mapCol[index])
			if (mapCol[index] == mapCol[i] || // 세로가 같을경우 안됨.
				index - i == Math.abs(mapCol[index] - mapCol[i])) {
				// 가로의 차이와 세로의 차이가 같을경우 대각선상에 있음. / 와 \를 구별하기위해 절댓값 사용
				return false;
			}
		}
		return true;
	}
}