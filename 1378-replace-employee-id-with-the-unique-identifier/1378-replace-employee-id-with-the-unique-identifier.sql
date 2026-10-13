# Write your MySQL query statement below
select Employees.name , EmployeeUNI.unique_id 
from employees 
left join EmployeeUNI
on employees.id = employeeUNI.id ;