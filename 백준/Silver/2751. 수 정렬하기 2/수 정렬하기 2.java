import java.util.*;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		ArrayList<Integer> list = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			list.add(sc.nextInt());
		}

		list.sort(customComparator);

		for(int i : list) {
			System.out.println(i);
		}
	}

	public static Comparator<Integer> customComparator = new Comparator<Integer>() {
		@Override
		public int compare(Integer i1, Integer i2) {
			return i1 - i2;
		}
	};
}