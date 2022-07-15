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