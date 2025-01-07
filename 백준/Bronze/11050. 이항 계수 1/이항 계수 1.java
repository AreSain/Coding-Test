import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String temp = br.readLine();
		String[] input = temp.split(" ");
		int N = Integer.parseInt(input[0]);
		int K = Integer.parseInt(input[1]);

		int high = Math.max(N, K);

		int[] arr = dp(high);
		int answer = 0;

		if (K == 0)
			answer = 1;
		else
			answer = (arr[N] / arr[N - K]) / arr[K];
		bw.write(answer + "");
		bw.flush();
	}

	public static int[] dp(int high) {
		int[] arr = new int[high + 2];
		arr[0] = 1;
		arr[1] = 1;
		arr[2] = 2;
		for (int i = 3; i < high + 1; i++) {
			arr[i] = i * arr[i - 1];
		}
		return arr;
	}
}