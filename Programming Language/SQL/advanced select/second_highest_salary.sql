-- Table Employee:
-- id, salary

-- Output:
-- [2nd salary] else [null]

-- this problem can be solved by using IFNULL() function

SELECT IFNULL(
   (SELECT DISTINCT(salary)
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1, 1), null
) AS SecondHighestSalary;