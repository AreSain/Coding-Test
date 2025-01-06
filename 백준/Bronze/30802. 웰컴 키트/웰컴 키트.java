import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		String temp = br.readLine();
		String[] input = temp.split(" ");
		int[] arr = new int[6];
		for (int i = 0; i < 6; i++) {
			arr[i] = Integer.parseInt(input[i]);
		}
		temp = br.readLine();
		input = temp.split(" ");
		int t = Integer.parseInt(input[0]);
		int p = Integer.parseInt(input[1]);

		int ans = 0;
		for (int i = 0; i < 6; i++) {
			if ((arr[i] % t) == 0) {
				ans += arr[i] / t;
			} else {
				ans += arr[i] / t + 1;
			}
		}
		bw.write(ans + "\n");
		bw.write(N / p + " " + N % p);
		bw.flush();
	}
}