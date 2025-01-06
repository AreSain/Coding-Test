import java.util.*;


public class Main {
	public static int n;
	public static String[] arr;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		sc.nextLine();

		HashSet<String> set = new HashSet<>();

		for (int i = 0; i < n; i++) {
			set.add(sc.nextLine());
		}

		arr = new String[set.size()];
		set.toArray(arr);
		Arrays.sort(arr, customComparator);

		for(String s : arr) {
			System.out.println(s);
		}
	}

	public static Comparator<String> customComparator = new Comparator<String>() {
		@Override
		public int compare(String s1, String s2) {
			if (s1.length() != s2.length())
				return s1.length() - s2.length();
			for (int i = 0; i < s1.length(); i++) {
				if (s1.charAt(i) != s2.charAt(i))
					return s1.charAt(i) - s2.charAt(i);
			}
			return 0;
		}
	};
}