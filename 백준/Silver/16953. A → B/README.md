https://www.acmicpc.net/problem/16953

## 설명

처음에 int 배열로 작성하고, 맨 앞자리가 맞을 때 마다 연산값으로 뒷자리를 맞추는 풀이를 생각했기 때문에 푸는데 시간이 굉장히 오래걸렸다.

첫 발상은

``` java
앞자리를 맞춥니다.
1 -> 2
count 2
2 -> 2
count 2 + 5
와 같은 방법으로
뒷자리에 올 수 있는 경우는
7777777보다 작으면서 값이 맞는 경우를 백트래킹하려했는데 망했다.
```

그래서 근처에 자문을 구한 결과, 그래프로 생각하고 풀으라는 방법을 들었고, bfs로 문제를 푼 이후 이론을 설명들었다.
상태 공간 탐색이라는 이론이 있었고, 사실 경우의 수를 다 따져 그래프로 탐색한다고 생각했다.