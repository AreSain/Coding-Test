import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] input = br.readLine().split(" ");
		int N = Integer.parseInt(input[0]);
		int M = Integer.parseInt(input[1]);

		input = br.readLine().split(" ");
		int L = Integer.parseInt(input[0]);
		int[] people = new int[N + 1];
		for (int i = 0; i < L; i++) {
			people[Integer.parseInt(input[i + 1])]++;
		}

		int answer = 0;
		String[][] inputList = new String[M][];
		for (int i = 0; i < M; i++) {
			inputList[i] = br.readLine().split(" ");
		}
		for (String[] in : inputList) {
			checking(in, people);
		}
		for (String[] in : inputList) {
			answer += calculator(in, people);
		}


		bw.write(answer + "");
		bw.flush();
	}

	public static void checking(String[] input, int[] people) {
		int n = Integer.parseInt(input[0]);
		for (int i = 1; i < n + 1; i++) {
			if (people[Integer.parseInt(input[i])] > 0) {
				for (int j = 1; j < n + 1; j++) {
					people[Integer.parseInt(input[j])]++;
				}
				return;
			}
		}
	}

	public static int calculator(String[] input, int[] people) {
		int n = Integer.parseInt(input[0]);
		for (int i = 1; i < n + 1; i++) {
			if (people[Integer.parseInt(input[i])] > 0) {
				return 0;
			}
		}
		return 1;
	}
}