# Write your MySQL query statement below
select Person.firstname , Person.lastname , address.city , address.state 
from person 
left join address
on person.personId = address.personId ;