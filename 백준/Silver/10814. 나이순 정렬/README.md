https://www.acmicpc.net/problem/10814

## 한번 고친 이유

class를 만들어서 문제를 푼건 처음인데,

People 배열을 New로 선언하고, for문으로 속을 채우는 곳에서 NullPointException이 생겼다.
안에 People을 하나하나 객체로 New 해주는 절차가 필요했다.