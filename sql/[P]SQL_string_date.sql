#1
SELECT animal_ins.animal_id, animal_ins.name, animal_ins.sex_upon_intake
from animal_ins
where animal_ins.name in ('Lucy', 'Ella', 'Pickle', 'Rogan', 'Sabrina', 'Mitty')

#2
SELECT animal_ins.animal_id, animal_ins.name
from animal_ins
where animal_ins.animal_type = 'Dog' and animal_ins.name like '%el%' #대소문자 구분은 binary(animal_ins.name)
order by animal_ins.name

#3
SELECT animal_ins.animal_id, animal_ins.name, if(animal_ins.sex_upon_intake like 'intact%', 'X', 'O') as '중성화'
from animal_ins
order by animal_id asc

#4
SELECT animal_ins.animal_id, animal_ins.name
from animal_ins join animal_outs using (animal_id)
order by timestampdiff(day, animal_ins.datetime, animal_outs.datetime) desc
limit 2

#5
SELECT animal_ins.animal_id, animal_ins.name, DATE_FORMAT(DATETIME, '%Y-%m-%d') as '날짜'
from animal_ins
order by animal_ins.animal_id