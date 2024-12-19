import static java.lang.Math.max;
import static java.util.Arrays.sort;
class Solution {
    public int answer = -1, maxSize = 0;
    public static int rows;
    public static int cols;
    public int solution(int[] mats, String[][] park) {
        rows = park.length;
        cols = park[0].length;
        Boolean[][] visited = new Boolean[rows][cols];
        int flag = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                visited[i][j] = false;
            }
        }
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                if (park[y][x].equals("-1")) {
                    int temp = finding(park, visited, x, y);
                    maxSize = max(maxSize, temp);
                    flag = 0;
                }
            }
        }
        sort(mats);
        for (int i = mats.length - 1; i >= 0; i--) {
            if (mats[i] <= maxSize) {
                answer = mats[i];
                break;
            }
        }
        return answer;
    }
    public static int finding(String[][] park, Boolean[][] visited, int x, int y) {
        int tempSize = 0;
        while (true) {
            for (int i = tempSize; i >= 0; i--) {
                for (int j = tempSize; j >= 0; j--) {
                    if (y + i >= rows || x + j >= cols)
                        return tempSize;
                    if (!park[y + i][x + j].equals("-1") && visited[y + i][x + j] != true)
                        return tempSize;
                    else
                        visited[y + i][x + j] = true;
                }
            }
            tempSize++;
        }
    }
}