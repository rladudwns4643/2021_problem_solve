#1
SELECT animal_id
from animal_ins
where name is NULL
order by animal_id asc

#2
SELECT animal_id
from animal_ins
where name is not null
order by animal_id asc

#3
SELECT animal_type, case when name is null then 'No name' else name end name, sex_upon_intake
from animal_ins