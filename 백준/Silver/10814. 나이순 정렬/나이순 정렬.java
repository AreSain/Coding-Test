import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String temp = br.readLine();
		int N = Integer.parseInt(temp);
		People[] arr = new People[N];

		for(int i = 0; i < N; i++) {
			temp = br.readLine();
			String[] info = temp.split(" ");
			arr[i] = new People();
			arr[i].age = Integer.parseInt(info[0]);
			arr[i].name = info[1];
			arr[i].priority = i;
		}

		Arrays.sort(arr, customComparator);

		for (People p : arr) {
			bw.write(p.age + " " + p.name + '\n');
		}
		bw.flush();
	}

	public static Comparator<People> customComparator = new Comparator<People>() {
		@Override
		public int compare(People s1, People s2) {
			if (s1.age != s2.age) {
				return s1.age - s2.age;
			} else {
				return s1.priority - s2.priority;
			}
		}
	};

	static class People {
		public int age;
		public String name;
		public int priority;
	}
}