https://school.programmers.co.kr/learn/courses/30/lessons/164668

### 첫 제출

```sql
SELECT 
    AL.WRITER_ID AS USER_ID,
    UGU.NICKNAME,
    AL.TOTAL_SALES
FROM USED_GOODS_USER AS UGU
JOIN (
SELECT WRITER_ID,
    SUM(PRICE) AS TOTAL_SALES
FROM USED_GOODS_BOARD
WHERE STATUS LIKE 'DONE'
) AS AL
ON UGU.USER_ID = AL.WRITER_ID
WHERE AL.TOTAL_SALES >= 700000
ORDER BY TOTAL_SALES ASC
```

정답을 보고 진행했다.
첫 3단계라고 너무 어렵게 생각하고 있었던게 화근이었나보다.
그냥 두 테이블 JOIN해서 조건 걸어서 출력해서 해결했다.