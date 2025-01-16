import java.io.*;
import java.util.*;

public class Main {
	static long N, M, flag = 0;
	static Deque<Long> deque = new ArrayDeque<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] input = br.readLine().split(" ");
		N = Long.parseLong(input[0]);
		M = Long.parseLong(input[1]);

		int ans = 1;
		deque.add(N);
		int count = 1;

		while (true) {
			if (N == M) {
				bw.write(ans + "");
				break;
			}
			count = bfs(count);
			ans++;
			if (count == 0) {
				bw.write(-1 + "");
				break;
			}
			for (long n : deque) {
				if (n == M) {
					bw.write(ans + "");
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		bw.flush();
	}

	public static int bfs(int count) {
		for (int i = 0; i < count; i++) {
			long now = deque.pop();
			long left = now * 10 + 1;
			long right = now * 2;

			if (left <= M)
				deque.addLast(left);
			if (right <= M)
				deque.addLast(right);
		}
		return deque.size();
	}
}