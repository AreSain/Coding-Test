import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int answer = 0;
		String[] input = br.readLine().split(" ");
		int N = Integer.parseInt(input[0]);
		int M = Integer.parseInt(input[1]);

		input = br.readLine().split(" ");
		int temp = Integer.parseInt(input[0]);
		UnionFind uf = new UnionFind(N + 1);

		String[][] inputList = new String[M][];
		for (int i = 0; i < M; i++) {
			inputList[i] = br.readLine().split(" ");
		}

		for (String[] in : inputList) {
			int n = Integer.parseInt(in[0]);
			for (int i = 1; i < n; i++) {
				uf.union(Integer.parseInt(in[i]), Integer.parseInt(in[i + 1]));
			}
		}

		HashSet<Integer> set = new HashSet<>();
		for (int i = 1; i < temp + 1; i++) {
			set.add(uf.find(Integer.parseInt(input[i])));
		}

		for (String[] in : inputList) {
			int n = Integer.parseInt(in[1]);

			if (!set.contains(uf.find(n))) {
				answer++;
			}
		}

		bw.write(answer + "");
		bw.flush();
	}

	static class UnionFind {
		private int[] parent;

		public UnionFind(int count) {
			this.parent = new int[count];
			for (int i = 0; i < count; i++) {
				parent[i] = -1;
			}
		}

		public int find(int n) {
			if (parent[n] < 0)
				return n;
			else
				return parent[n] = find(parent[n]);
		}

		public void union(int n1, int n2) {
			n1 = find(n1);
			n2 = find(n2);

			if (n1 == n2) // 같은 그룹
				return;

			if (n1 <= n2) { // 큰 그룹에 루트노드에 작은 그룹의 루트노드가 병합
				parent[n1] += parent[n2];
				parent[n2] = n1;
			} else {
				parent[n2] += parent[n1];
				parent[n1] = n2;
			}
		}

		public void debug() {
			for (int i = 1; i < parent.length; i++) {
				System.out.print(parent[i] + " ");
			}
			System.out.println();
		}
	}
}