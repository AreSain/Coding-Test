import java.util.*;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while(true) {
			int temp = sc.nextInt();
			if (temp == 0)
				break;

			StringBuilder sb = new StringBuilder();

			sb.append(temp);

			for (int i = 0; i < sb.length(); i++) {
				if (sb.charAt(i) != sb.charAt(sb.length() - 1 - i)) {
					System.out.println("no");
					break;
				}
				if (i == sb.length() / 2) {
					System.out.println("yes");
					break;
				}
			}
		}
	}
}