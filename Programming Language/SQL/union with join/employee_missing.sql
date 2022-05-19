-- # Write your MySQL query statement below
-- Write an SQL query to report the IDs of all the employees with missing information. The information of an employee is missing if:

-- The employee's name is missing, or
-- The employee's salary is missing.

-- Table Employees:
-- employee_id, name

-- Table Salaries:
-- employee_id, salary

select e.employee_id
from Employees e
left join Salaries s on s.employee_id = e.employee_id
where e.name is null or s.salary is null

union

select s.employee_id
from Salaries s
left join Employees e on e.employee_id = s.employee_id
where e.name is null or s.salary is null

order by employee_id;