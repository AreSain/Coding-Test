https://school.programmers.co.kr/learn/courses/30/lessons/284530

### 첫 제출

```sql
SELECT YEAR(YM) AS YEAR,
    ROUND(AVG(PM_VAL1), 2) AS PM10,
    ROUND(AVG(PM_VAL2), 2) AS 'PM2.5'
FROM AIR_POLLUTION
GROUP BY YEAR
ORDER BY YEAR ASC

25/100
```

문제에서 준 조건 중 수원지역을 빼먹었다.
```sql
WHERE LOCATION2 LIKE '수원'
```
추가해서 제출 후 통과했다.