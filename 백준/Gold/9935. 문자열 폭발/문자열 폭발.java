import java.io.*;
import java.util.*;

public class Main {
	static String input, bomb;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		input = br.readLine();
		bomb = br.readLine();

		StringBuilder in = new StringBuilder();
		int bombLength = bomb.length();

		for (int i = 0; i < input.length(); i++) {
			in.append(input.charAt(i));

			if (in.length() >= bombLength) {
				boolean match = true;

				for (int j = 0; j < bombLength; j++) {
					if (in.charAt(in.length() - bombLength + j) != bomb.charAt(j)) {
						match = false;
						break;
					}
				}

				if (match) {
					in.delete(in.length() - bombLength, in.length());
				}
			}
		}

		if (in.length() == 0) {
			bw.write("FRULA");
		} else {
			bw.write(in.toString());
		}
		bw.flush();
	}
}
