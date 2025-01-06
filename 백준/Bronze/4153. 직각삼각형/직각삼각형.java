import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		while(true) {
			String temp = br.readLine();
			String[] input = temp.split(" ");
			int a = Integer.parseInt(input[0]);
			int b = Integer.parseInt(input[1]);
			int c = Integer.parseInt(input[2]);

			if (a == 0 && b == 0 && c == 0)
				break;

			int[] arr = {a, b, c};
			Arrays.sort(arr);

			if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) {
				bw.write("right\n");
			} else {
				bw.write("wrong\n");
			}
			bw.flush();
		}
	}
}