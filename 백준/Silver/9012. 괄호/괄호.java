import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String temp = br.readLine();
		int N = Integer.parseInt(temp);

		String[] arr = new String[N];

		for (int i = 0; i < N; i++) {
			arr[i] = br.readLine();
		}

		ArrayDeque<Character> deque = new ArrayDeque<>();

		for (String s : arr) {
			int fail = 0;
			for (int i = 0; i < s.length(); i++) {
				StringBuilder sb = new StringBuilder();
				sb.append(s);
				if (sb.charAt(i) == ')') {
					if (deque.isEmpty()) {
						fail++;
						break;
					}
					if (deque.removeFirst() != '(') {
						fail++;
						break;
					}
				} else {
					deque.addFirst(sb.charAt(i));
				}
			}
			if (deque.isEmpty() && fail == 0) {
				bw.write("YES\n");
			} else {
				bw.write("NO\n");
			}
			deque.clear();
		}
		bw.flush();
	}
}