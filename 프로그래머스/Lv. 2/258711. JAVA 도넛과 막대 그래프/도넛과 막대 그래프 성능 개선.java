import java.util.Arrays;
import java.util.HashMap;

class Solution {
	public static int vertex, donut = 0, bar = 0, eight = 0, count = 0, length, mapSize;

	public int[] solution(int[][] edges) {
		length = edges.length;
		int[] answer = new int[4];

		for (int[] edge : edges) {
			mapSize = Math.max(mapSize, Math.max(edge[0], edge[1]));
		}
		mapSize++;
		vertex = findVertex(edges);

		int[] to = new int[mapSize];
		int[] from = new int[mapSize];

		Arrays.fill(to, -1);
		Arrays.fill(from, -1);

		for (int[] edge : edges) {
			int start = edge[0];
			int end = edge[1];

			if (to[end] == -1) {
				to[end] = 0;
				from[end] = 0;
			} // 갈 수 있다면 0으로 초기화
			if (start != vertex && to[start] == -1) {
				to[start] = 0;
				from[start] = 0;
			}

			if (start != vertex) {
				to[start]++;
				from[end]++;
			}
		}

		solve(to, from);

		answer[0] = vertex;
		answer[1] = donut;
		answer[2] = bar;
		answer[3] = eight;

		return answer;
	}

	public static int findVertex(int[][] edges) {
		int[] to = new int[mapSize];
		int[] from = new int[mapSize];
		int index = 0;

		for (int i = 0; i < length; i++) {
			to[edges[i][0]]++;
			from[edges[i][1]]++;
		}

		for (int i = 1; i < mapSize; i++) {
			if (count < to[i] && from[i] == 0) {
				count = Math.max(count, to[i]); // 정점에서 뻗어나간 개수 count 는 그래프의 개수와 같다.
				index = i;
			}
		}

		return index;
	}

	public static void solve(int[] to, int[] from) {
		for (int i = 1; i < mapSize; i++) {
			if (vertex == i)
				continue;
			if ((to[i] == 0 && from[i] == 1) || (to[i] == 0 && from[i] == 0)) {
				bar++; // to 0 get 1 = 막대가 끝날때 && 막대가 1칸일 경우.
			} else if (to[i] == 2 && from[i] == 2) {
				eight++; // 가는거 두개 오는거 두개 = 8자 그래프
			}
		}

		donut = count - bar - eight;
	}
}