import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] input = br.readLine().split(" ");
		int A = Integer.parseInt(input[0]);
		int B = Integer.parseInt(input[1]);
		int C = Integer.parseInt(input[2]);

		long result = modular(A, B, C);

		bw.write(result + "\n");
		bw.flush();
	}

	private static long modular(int A, int B, int C) {
		if (B == 0)
			return 1;
		long mid = modular(A, B / 2, C);
		mid = (mid * mid) % C;
		if (B % 2 != 0)
			mid = (mid * A) % C;
		return mid;
	}
}
