-- Write your MySQL query statement below
-- https://leetcode.com/problems/department-top-three-salaries/

with temp_top_salaries as (
    select
        d.id as DepartmentID,
        d.name as Department,
        (
            select
                distinct(salary)
            from
                Employee e
            where
                e.departmentId = d.id
            order by
                salary desc
            limit
                1 offset 0
        ) as salary_1,
        (
            select
                distinct(salary)
            from
                Employee e
            where
                e.departmentId = d.id
            order by
                salary desc
            limit
                1 offset 1
        ) as salary_2,
        (
            select
                distinct(salary)
            from
                Employee e
            where
                e.departmentId = d.id
            order by
                salary desc
            limit
                1 offset 2
        ) as salary_3
    from
        Department d
)
select
    t.Department as Department,
    e.name as Employee,
    e.salary as Salary
from
    temp_top_salaries t
    inner join Employee e on e.departmentId = t.DepartmentID
where
    e.salary = t.salary_1
    or e.salary = t.salary_2
    or e.salary = t.salary_3