import java.util.*;

class Solution {
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        
        while (true) {
            if (check(wallet, bill))
                break ;
            fold(wallet, bill);
            answer++;
        }
        return answer;
    }
    
    public void fold(int[] wallet, int[] bill) {
        if (bill[0] > bill[1])
            bill[0] /= 2;
        else
            bill[1] /= 2;
    }
    
    public boolean check(int[] wallet, int[] bill) {
        if ((bill[0] <= wallet[0]) && (bill[1] <= wallet[1]))
            return true;
        else if ((bill[1] <= wallet[0]) && (bill[0] <= wallet[1]))
            return true;
        else
            return false;
    }
}