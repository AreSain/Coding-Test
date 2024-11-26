SELECT
    YEAR(A.DIFFERENTIATION_DATE) AS YEAR,
    ABS(B.MAX_SIZE - A.SIZE_OF_COLONY) AS YEAR_DEV,
    A.ID AS ID
FROM ECOLI_DATA AS A
INNER JOIN (
    SELECT
         YEAR(DIFFERENTIATION_DATE) AS YEAR,
        MAX(SIZE_OF_COLONY) AS MAX_SIZE
    FROM ECOLI_DATA
    GROUP BY YEAR(DIFFERENTIATION_DATE)
) AS B
ON YEAR(A.DIFFERENTIATION_DATE) = B.YEAR
ORDER BY YEAR ASC, YEAR_DEV ASC;
