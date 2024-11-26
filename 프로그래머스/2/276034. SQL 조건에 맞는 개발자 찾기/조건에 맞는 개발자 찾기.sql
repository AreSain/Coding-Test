SELECT DISTINCT
    D.ID,
    D.EMAIL,
    D.FIRST_NAME,
    D.LAST_NAME
FROM DEVELOPERS AS D
JOIN SKILLCODES S ON (D.SKILL_CODE &S.CODE) = S.CODE
WHERE S.NAME LIKE 'Python' OR S.NAME LIKE 'C#'
ORDER BY ID ASC