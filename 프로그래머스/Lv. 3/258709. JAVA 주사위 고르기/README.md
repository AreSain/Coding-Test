https://school.programmers.co.kr/learn/courses/30/lessons/258709

테스트 케이스에서 시간초과가 있는데, 일단 값이 틀리지는 않는 것 같아 제출하고 최적화 하려 한다.
``` code
테스트 19 〉	통과 (9834.58ms, 385MB)
테스트 20 〉	통과 (9465.45ms, 370MB)
테스트 21 〉	통과 (9064.45ms, 393MB)
테스트 22 〉	실패 (시간 초과)
테스트 23 〉	실패 (시간 초과)
테스트 24 〉	실패 (시간 초과)
테스트 25 〉	실패 (시간 초과)
테스트 26 〉	실패 (시간 초과)
```

## 개선 1

``` code
for (int i = 0; i < playerADiceResult.length; i++) {
            while (playerBIndex < playerBDiceResult.length && 
                   playerBDiceResult[playerBIndex] < playerADiceResult[i]) {
                playerBIndex++;
            }
            win += playerBIndex;
        }
```

index를 하나씩 올리는 것 보다 이진탐색으로 index를 최적화 해보았다.

### 결과
``` code
테스트 19 〉	실패 (시간 초과)
테스트 20 〉	실패 (시간 초과)
테스트 21 〉	실패 (시간 초과)
테스트 22 〉	실패 (시간 초과)
테스트 23 〉	실패 (시간 초과)
테스트 24 〉	실패 (시간 초과)
테스트 25 〉	실패 (시간 초과)
테스트 26 〉	실패 (시간 초과)
```

왜 이진탐색을 적용하고 성능이 떨어지는건지 당최 감도 오지 않는다..
