import java.util.Scanner;

public class Main {
    public static int N, min = Integer.MAX_VALUE;
	public static int[][] map;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
		map = new int[N][N];
		boolean[] visited = new boolean[N];

        for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = sc.nextInt();
			}
        }

		startAndLink(visited, 0, 0);

		System.out.println(min);
    }

	public static void startAndLink(boolean[] visited, int turn, int people) {
		if (people == N / 2) {
            check(visited);
            return;
        }

		for (int i = turn; i < N; i++) {
			visited[i] = true;
			startAndLink(visited, i + 1, people + 1);
			visited[i] = false;
		}
    }

	public static void check(boolean[] visited) {
		int start = 0;
		int link = 0;

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
                if (visited[i] && visited[j]) {
                    start += map[i][j];
                    start += map[j][i];
                } else if (!visited[i] && !visited[j]) {
                    link += map[i][j];
                    link += map[j][i];
                }
            }
		}

		int diff = Math.abs(start - link);
		min = Math.min(min, diff);
    }
}
