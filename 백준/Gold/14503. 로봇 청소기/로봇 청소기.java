import java.util.Scanner;

public class Main {
    public static int count = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N, M;
        N = sc.nextInt();
        M = sc.nextInt();

        int x, y, d;
        y = sc.nextInt();
        x = sc.nextInt();
        d = sc.nextInt();


        int[][] map = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                map[i][j] = sc.nextInt();
        }

        roop(map, N, M, x, y, d);

        System.out.println(count);
    }

    static public void roop(int[][] map, int N, int M, int x, int y, int d) {
        int[] dx = {0, 1, 0, -1};
        int[] dy = {-1, 0, 1, 0};

        if (map[y][x] == 0) { // 2를 청소된 칸이라고 생각함.
            map[y][x] = 2;
            count++;
        }

        int flag = 0;

        for (int i = 0; i < 4; i++) { // 사방향이 청소 완이거나 벽인지 확인
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (map[ny][nx] != 0) {
                flag++;
            }
        }

        if (flag == 4) { // 사방향이 청소 완이거나 벽인 경우
            int back = (d + 2) % 4;
            int nx = x + dx[back];
            int ny = y + dy[back];

            if (map[ny][nx] == 1) { // 뒤가 벽이면 끝
                return;
            } else { // 방향 유지
                roop(map, N, M, nx, ny, d);
            }
        } else { // 갈 수 있는 곳이 있을경우 왼쪽으로 고개를 돌림
            int left = (d + 3) % 4;
            int nx = x + dx[left];
            int ny = y + dy[left];

            if (map[ny][nx] == 0) {
                roop(map, N, M, nx, ny, left); // 고개 돌린채로 앞으로 감
            } else {
                roop(map, N, M, x, y, left); // 고개 돌린채로 가만있음
            }
        }
    }
}
