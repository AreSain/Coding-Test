import java.util.HashMap;

class Solution {
	public static int vertex, donut = 0, bar = 0, eight = 0, count = 0, length, mapSize;

	public int[] solution(int[][] edges) {
		length = edges.length;
		int[] answer = new int[4];

		HashMap<Integer, Integer> to = new HashMap<>();
		HashMap<Integer, Integer> from = new HashMap<>();

		for (int[] edge : edges) {
			mapSize = Math.max(mapSize, Math.max(edge[0], edge[1]));
		}
		mapSize++;
		vertex = findVertex(edges);

		for (int i = 1; i < mapSize; i++) {
			to.put(i, -1);
			from.put(i, -1);
		}
		for (int i = 0; i < length; i++) {
			if (edges[i][0] != vertex) {
				to.put(edges[i][0], 0);
				from.put(edges[i][0], 0);
			}
			to.put(edges[i][1], 0);
			from.put(edges[i][1], 0);
		}

		for (int i = 0; i < length; i++) {
			if (edges[i][0] == vertex)
				continue;
			to.put(edges[i][0], to.get(edges[i][0]) + 1);
			from.put(edges[i][1], from.get(edges[i][1]) + 1);
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

	public static void solve(HashMap<Integer, Integer> to, HashMap<Integer, Integer> from) {
		for (int i = 1; i < mapSize; i++) {
			if (vertex == i || to.get(i) == -1 || from.get(i) == -1)
				continue;
			if ((to.get(i) == 0 && from.get(i) == 1) || (to.get(i) == 0 && from.get(i) == 0)) {
				bar++; // to 0 get 1 = 막대가 끝날때 && 막대가 1칸일 경우.
			} else if (to.get(i) == 2 && from.get(i) == 2) {
				eight++; // 가는거 두개 오는거 두개 = 8자 그래프
			}
		}

		donut = count - bar - eight;
	}
}