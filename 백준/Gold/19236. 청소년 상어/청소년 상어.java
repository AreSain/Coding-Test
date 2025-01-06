import java.util.*;

public class Main {
	public static int[][] fish = new int[4][4];
	public static int[][] ways = new int[4][4];
	public static int[] fishInfo = new int[17];

	// 1부터 순서대로 ↑, ↖, ←, ↙, ↓, ↘, →, ↗
	// ↗, ↑, ↖, ←, ↙, ↓, ↘, →
	public static int[] dx = {1, 0, -1, -1, -1, 0, 1, 1};
	public static int[] dy = {-1, -1, -1, 0, 1, 1, 1, 0};
	public static int answer = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				fish[i][j] = sc.nextInt();
				ways[i][j] = sc.nextInt() % 8;
				fishInfo[fish[i][j]] = i * 4 + j;
			}
		}

		int sharkEat = fish[0][0];
		fishInfo[fish[0][0]] = -1;
		fish[0][0] = 0;


		roop(0, 0, ways[0][0], sharkEat);
		
		System.out.println(answer);
	}

	public static void roop(int y, int x, int sharkWay, int sharkEat) {
		int[][] fishCopy = new int[4][4];
		int[][] waysCopy = new int[4][4];
		int[] fishInfoCopy;

		for (int i = 0; i < 4; i++) {
			fishCopy[i] = fish[i].clone();
			waysCopy[i] = ways[i].clone();
		}
		fishInfoCopy = fishInfo.clone();

		if (sharkEat > answer) {
			answer = sharkEat;
		}

		// 물고기 이동
		fishInfo = moveFish(y, x);

		for (int i = 1; i <= 3; i++) {
			int nx = x + dx[sharkWay] * (i);
			int ny = y + dy[sharkWay] * (i);

			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) {
				continue;
			} // 범위 밖으로 넘어갈 경우

			if (fish[ny][nx] == 0) {
				continue;
			} // 물고기가 없는 경우

			int fishInfoTemp = fishInfo[fish[ny][nx]];
			int fishTemp = fish[ny][nx];

			fishInfo[fish[ny][nx]] = -1;
			fish[ny][nx] = 0;

			roop(ny, nx, ways[ny][nx], sharkEat + fishTemp);
			// 잡아먹은거 복구
			fish[ny][nx] = fishTemp;
			fishInfo[fish[ny][nx]] = fishInfoTemp;
		}

		// 물고기 이동 복구
		for (int i = 1; i < 17; i++) {
			fishInfo[i] = fishInfoCopy[i];
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				fish[i][j] = fishCopy[i][j];
				ways[i][j] = waysCopy[i][j];
			}
		}
	}

	public static int[] moveFish(int sharkY, int sharkX) {
		int[] moveFish = fishInfo.clone();

		for (int i = 1; i <= 16; i++) {
			if (moveFish[i] == -1) {
				continue;
			}

			for (int j = 0; j < 8; j++) {
				int x = moveFish[i] % 4;
				int y = moveFish[i] / 4;

				int nx = x + dx[(ways[y][x] + j) % 8];
				int ny = y + dy[(ways[y][x] + j) % 8];

				if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || (nx == sharkX && ny == sharkY)) {
					continue;
				}

				if (fish[ny][nx] == 0) { // 빈칸
					fish[ny][nx] = i;
					fish[y][x] = 0;

					ways[ny][nx] = (ways[y][x] + j) % 8;
					moveFish[i] = ny * 4 + nx;
				} else { // 다른 물고기가 있는 경우
					int temp = fish[ny][nx];
					fish[ny][nx] = i;
					fish[y][x] = temp;

					int wayTemp = ways[ny][nx];
					ways[ny][nx] = (ways[y][x] + j) % 8;
					ways[y][x] = wayTemp;

					moveFish[fish[ny][nx]] = ny * 4 + nx;
					moveFish[fish[y][x]] = y * 4 + x;
				}
				break;
			}
		}
		return moveFish;
	}
}
