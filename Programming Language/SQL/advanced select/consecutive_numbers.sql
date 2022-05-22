-- Logs table:
-- id, num

-- Example:
-- id, num
-- 1, 2
-- 2, 2
-- 3, 2
-- 4, ...

-- Query: Find all the numbers that appear at least three times consecutively.

SELECT  distinct num AS ConsecutiveNums
FROM Logs
WHERE (id + 1, num) IN ( SELECT * FROM Logs)
AND (id + 2, num) IN ( SELECT * FROM Logs);