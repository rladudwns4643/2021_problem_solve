#1
SELECT DATETIME
FROM ANIMAL_INS
ORDER BY DATETIME desc
LIMIT 1

#2
SELECT DATETIME
FROM ANIMAL_INS
ORDER BY DATETIME desc
LIMIT 1

#3
select count(*)
from animal_ins

#4
select count(DISTINCT name) as count
from animal_ins