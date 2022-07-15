#1
SELECT animal_outs.animal_id, animal_outs.name from animal_outs
left join animal_ins on animal_outs.animal_id = animal_ins.animal_id
where animal_ins.animal_id is null
order by animal_id asc

#2
SELECT animal_outs.animal_id, animal_outs.name from animal_outs
left outer join animal_ins on (animal_outs.animal_id = animal_ins.animal_id)
where animal_outs.datetime < animal_ins.datetime
order by animal_ins.datetime asc

#3
SELECT animal_ins.name, animal_ins.datetime
from animal_ins left join animal_outs on animal_ins.animal_id = animal_outs.animal_id
where animal_outs.animal_id is null
order by animal_ins.datetime asc limit 3

#4
SELECT animal_ins.animal_id, animal_ins.animal_type, animal_ins.name
from animal_ins join animal_outs on animal_ins.animal_id = animal_outs.animal_id
where sex_upon_intake in('Intact Male', 'Intact Female') and sex_upon_outcome in ('Spayed Female', 'Neutered Male')