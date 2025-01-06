https://www.acmicpc.net/problem/2751

## 틀린 이유

customComparator를 만들어서 시간초과가 났다.
혹시 몰라서 bufferReader와 bufferWriter를 사용하여 입출력에서 최적화를 했고, 원시타입으로 하기 위해 배열을 사용해서 값 비교 오버헤드를 줄여서 통과했다.