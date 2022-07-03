#1
select animal_type, count(animal_type) as count
from animal_ins
where animal_type in("Cat", "Dog")
group by animal_type
order by animal_type

#2
SELECT name, count(name) as "count"
from animal_ins
group by name
having count > 1
order by name

#3
select hour(datetime), count(*)
from animal_outs
where hour(datetime) > 8 and hour(datetime) < 20
group by hour(datetime)
order by hour(datetime)

#4
with RECURSIVE tmp_table as(
    select 0 as h
    union all
    select h+1 from tmp_table where h < 23
)

select h, count(animal_id)
from tmp_table
    left outer join animal_outs
    on HOUR(datetime) = tmp_table.h
group by h
order by h