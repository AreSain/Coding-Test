https://www.acmicpc.net/problem/1018

## 실수한 점

전역변수로 x, y를 선언하고, int x = sc.nextInt(), y = sc.nextInt();로 초기화 해버려서 지역 변수가 되어버리는 실수를 했다.
당연히 다른 메서드에서 부른 x, y는 값이 바뀌지 않아 0이어서 for문이 돌지 않는 상황이 있었다.