-- https://www.hackerrank.com/challenges/the-blunder/problem?isFullScreen=true
select
    ceil(avg(salary) - avg(replace(salary, '0', '')))
from
    employees;