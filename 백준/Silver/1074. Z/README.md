# [Silver I] Z - 1074 

[문제 링크](https://www.acmicpc.net/problem/1074) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

분할 정복, 재귀

### 제출 일자

2023년 11월 26일 14:54:13

### 문제 설명

<p>한수는 크기가 2<sup>N</sup> × 2<sup>N</sup>인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.</p>

<p style="text-align:center"><img alt="" src="https://u.acmicpc.net/21c73b56-5a91-43aa-b71f-9b74925c0adc/Screen%20Shot%202020-12-02%20at%208.09.46%20AM.png" style="width: 100px; height: 99px;"></p>

<p>N > 1인 경우, 배열을 크기가 2<sup>N-1</sup> × 2<sup>N-1</sup>로 4등분 한 후에 재귀적으로 순서대로 방문한다.</p>

<p>다음 예는 2<sup>2</sup> × 2<sup>2</sup> 크기의 배열을 방문한 순서이다.</p>

<p style="text-align:center"><img alt="" src="https://u.acmicpc.net/adc7cfae-e84d-4d5c-af8e-ee011f8fff8f/Screen%20Shot%202020-12-02%20at%208.11.17%20AM.png" style="width: 250px; height: 252px;"></p>

<p>N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.</p>

<p>다음은 N=3일 때의 예이다.</p>

<p style="text-align:center"><img alt="" src="https://u.acmicpc.net/d3e84bb7-9424-4764-ad3a-811e7fcbd53f/Screen%20Shot%202020-12-30%20at%2010.50.47%20PM.png" style="width: 533px; height: 535px;"></p>

### 입력 

 <p>첫째 줄에 정수 N, r, c가 주어진다.</p>

### 출력 

 <p>r행 c열을 몇 번째로 방문했는지 출력한다.</p>

 ### 풀이

 <p>사각형의 크기를 바탕으로 사각형의 변의 길이를 구한다.</p>

 <p>원하는 좌표인 r, c의 값이 현재 사분면 안에 있으면 <strong>왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래</strong> 순서대로 재귀함수를 호출한다.</p>

 <p>재귀함수 탈출 조건 = 변의 길이가 0이 될때</p>

 <p>만약 범위 안에 없을경우 변의 길이 * 변의 길이(사각형 안의 원소 개수)를 ans에 더하면서 진행</p>

 <p>만약 현재 사각형의 좌표가 r, c(구해야하는 좌표)일 경우 쌓아두었던 ans값을 출력한다.</p>

 ### 의사코드

```c++
void check()
{
	if 변의 길이가 0
		return;
	if (r,c)를 찾았을 때
		정답 출력
	if 범위 안에 (r, c)가 있을 때
	{
		왼쪽 위
		오른쪽 위
		왼쪽 아래
		오른쪽 아래
	}
	else 범위 안에 없을 때
		정답에 사각형 크기만큼 추가
}
```

 ### 개선점

 <p>사각형의 ans를 출력하고 난 이후로도 함수는 계속될테니, 출력시에 플래그를 세워 다른 함수들도 바로 리턴할 수 있게 작성할 수 있을 것 같다.</p>
