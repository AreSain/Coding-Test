import java.util.*;
import java.io.*;

class Pointer {
	public int x;
	public int y;

	public Pointer(int i, int j) {
		this.y = i;
		this.x = j;
	}
}

class Main {
	public static int n, m, answer = 100000;
	public static int[] open;
	public static ArrayList<Pointer> chicken, house;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String input = br.readLine();
		String[] temp = input.split(" ");

		n = Integer.parseInt(temp[0]);
		m = Integer.parseInt(temp[1]);

		chicken = new ArrayList<>();
		house = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			input = br.readLine();
			temp = input.split(" ");
			for (int j = 0; j < n; j++) {
				int tmp = Integer.parseInt(temp[j]);
				if (tmp == 1) {
					house.add(new Pointer(i, j));
				} else if (tmp == 2) {
					chicken.add(new Pointer(i, j));
				}
			}
		}
		open = new int[chicken.size()];
		backtracking(0, 0);

		bw.write(answer + "");
		bw.flush();
	}

	public static void backtracking(int index, int size) {
		if (size == m) {
			answer = Math.min(answer, calculate());
			return ;
		}

		for (int i = index; i < chicken.size(); i++) {
			open[i] = 1;
			backtracking(i + 1, size + 1);
			open[i] = 0;
		}
	}

	public static int calculate() {
		int response = 0;

		for (int i = 0; i < house.size(); i++) {
			int distence = 100000;
			for (int j = 0; j < chicken.size(); j++) {
				if (open[j] == 1) {
					int temp = Math.abs(house.get(i).x - chicken.get(j).x) + Math.abs(house.get(i).y - chicken.get(j).y);
					distence = Math.min(distence, temp);
				}
			}
			response += distence;
		}

		return response;
	}
}