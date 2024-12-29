import static java.util.Arrays.*;
import java.util.Arrays;

class Solution {
	public static int[] goat, playerA;
	public static int maxWin = 0, n, diceIndex = 0;
	public int[] solution(int[][] dice) {
		n = dice.length;
		goat = new int[n / 2];
		playerA = new int[n / 2];
		roop(playerA, dice, 0, new boolean[n]);

		Arrays.sort(goat);
		return goat;
	}

	public static void roop(int[] playerA, int[][] dice, int turn, boolean[] used) {
		if (turn == n / 2) {
			solve(dice, Arrays.copyOf(playerA, playerA.length));
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!used[i] && (turn == 0 || playerA[turn - 1] < i)) {
				used[i] = true;
				playerA[turn] = i;
				roop(playerA, dice, turn + 1, used);
				used[i] = false;
			}
		}
	}

	public static void solve(int[][] dice, int[] playerA) {
		int[] playerADiceResult = new int[(int)Math.pow(6, n / 2)];
		int[] playerBDiceResult = new int[(int)Math.pow(6, n / 2)];
		diceIndex = 0;
		rollAllDice(dice, playerA, 0, 0, playerADiceResult);

		int[] playerB = new int[n / 2];
		boolean[] used = new boolean[n];
		for (int i = 0; i < playerA.length; i++) {
			used[playerA[i]] = true;
		}
		int idx = 0;
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				playerB[idx++] = i;
			}
		}

		diceIndex = 0;
		rollAllDice(dice, playerB, 0, 0, playerBDiceResult);

		sort(playerADiceResult);
		sort(playerBDiceResult);

		int win = 0;
		for (int i = 0; i < playerADiceResult.length; i++) {
			int playerBIndex = findBIndex(playerBDiceResult, playerADiceResult[i]);
			win += playerBIndex;
		}

		if (win > maxWin) {
			maxWin = win;
			for (int i = 0; i < n / 2; i++) {
				goat[i] = playerA[i] + 1;
			}
		}
	}

	public static void rollAllDice(int[][] dice, int[] player, int turn, int currentSum, int[] results) {
		if (turn == n / 2) {
			results[diceIndex] = currentSum;
			diceIndex++;
			return;
		}
		for (int i = 0; i < 6; i++) {
			rollAllDice(dice, player, turn + 1, currentSum + dice[player[turn]][i], results);
		}
	}

	public static int findBIndex(int[] playerBDiceResult, int AResult) {
		int left = 0, right = (int)Math.pow(6, n / 2);
		while (left < right) {
			int mid = (left + right) / 2;
			if (AResult > playerBDiceResult[mid]) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return left;
	}
}
