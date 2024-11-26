https://school.programmers.co.kr/learn/courses/30/lessons/164670

### 첫 제출

```sql
SELECT
    USER_ID,
    NICKNAME,
    CONCAT(UGU.STREET_ADDRESS1, ' ', UGU.STREET_ADDRESS2) 전체주소,
    CONCAT(SUBSTR(UGU.TLNO, 1, 3), '-', SUBSTR(UGU.TLNO, 4, 4),  '-', SUBSTR(UGU.TLNO, 8, 4)) AS 전화번호
FROM USED_GOODS_USER AS UGU
JOIN (
    SELECT WRITER_ID,
    COUNT(*) AS TOTAL_BOARD
    FROM USED_GOODS_BOARD
) AS AL
ON UGU.USER_ID = AL.WRITER_ID
WHERE AL.TOTAL_BOARD > 2
ORDER BY USER_ID DESC
```
틀렸다.

도시이름을 붙이지 않아서 수정했고, 내부 쿼리에서 Group By를 추가하여 여러개의 컬럼을 받아올 수 있게 수정했다.