import java.util.*;

public class Main {
	public static int x, y, answer = 64;
	public static char map[][];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		y = sc.nextInt();
		x = sc.nextInt();
		sc.nextLine();

		// n개의 줄 입력 받기
		map = new char[y][x];
		for (int i = 0; i < y; i++) {
			String line = sc.nextLine();
			for (int j = 0; j < x; j++) {
				map[i][j] = line.charAt(j);
			}
		}

		findBetterChess();

		System.out.println(answer);
	}

	public static void findBetterChess() {
		for (int i = 0; i < y - 7; i++) {
			for (int j = 0; j < x - 7; j++) { // 갈 수 있는 곳
				checkChessBoard(i, j);
			}
		}
	}

	public static void checkChessBoard(int i, int j) {
		int firstBlack = 0;
		int firstWhite = 0;
		for (int a = i; a < i + 8; a++) {
			for (int b = j; b < j + 8; b++) {
				if (((a + b) % 2) == 0) { // 합이 짝수인 곳에서
					if (map[a][b] == 'W') { // 하얀색이면 검은색 count를 올림
						firstBlack++;
					} else {
						firstWhite++;
					}
				} else {
					if (map[a][b] == 'B') {
						firstBlack++;
					} else {
						firstWhite++;
					}
				}
			}
		}

		if (answer > firstBlack)
			answer = firstBlack;
		if (answer > firstWhite)
			answer = firstWhite;
	}
}