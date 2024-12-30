import java.util.HashSet;

class Solution {
	public static int[][] map, visited;
	public static int[] value;
	public static int[] dx = {0, 0, -1, 1};
	public static int[] dy = {-1, 1, 0, 0};
	public static int mapValue = 1, row, col;

	public int solution(int[][] land) {
		int answer = 0;

		row = land.length;
		col = land[0].length;
		map = new int[row][col];
		visited = new int[row][col];
		value = new int[row * col];

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (land[i][j] == 1 && visited[i][j] == 0){
					bfs(land, i, j, 1);
					mapValue++;
				}
			}
		}

		for (int i = 0; i < col; i++) {
			HashSet<Integer> set = new HashSet<>();
			for (int j = 0; j < row; j++) {
				set.add(map[j][i]);
			}
			int temp = 0;
			for (int s : set) {
				temp += value[s];
			}
			if (temp > answer) {
				answer = temp;
			}
		}
		return answer;
	}

	public static void bfs(int[][] land, int y, int x, int num) {
		if (y < 0 || y >= row || x < 0 || x >= col || visited[y][x] == 1 || land[y][x] == 0)
			return;

		visited[y][x] = 1;
		map[y][x] = mapValue;
		value[mapValue]++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			bfs(land, ny, nx, num + 1);
		}
	}
}