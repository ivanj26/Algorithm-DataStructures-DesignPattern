-- Table Employee:
-- id, salary

-- Output:
-- [nth salary] else [null]

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M int;
SET M=N-1;
  RETURN (
      --   # Write your MySQL query statement below.
      select distinct(salary)
        from Employee
        order by salary desc
        limit 1 offset M
  );
END