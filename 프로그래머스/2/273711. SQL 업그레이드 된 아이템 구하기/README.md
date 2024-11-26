https://school.programmers.co.kr/learn/courses/30/lessons/273711

### 첫 제출
```sql
SELECT
    II.ITEM_ID,
    II.ITEM_NAME,
    II.RARITY
FROM ITEM_INFO AS II
JOIN ITEM_TREE AS IT
ON II.ITEM_ID = IT.ITEM_ID
WHERE IT.PARENT_ITEM_ID IS NOT NULL
ORDER BY ITEM_ID DESC
0/100
```

WHERE절에서 NOT NULL인(ROOT)아이템만 아니면 될 줄 알았지만, 처음에 RARE가 아닌 상황을 고려하지 않았다.
```sql
WHERE IT.PARENT_ITEM_ID IN (
    SELECT ITEM_ID
    FROM ITEM_INFO
    WHERE RARITY LIKE 'RARE'
)
```
로 수정했다.