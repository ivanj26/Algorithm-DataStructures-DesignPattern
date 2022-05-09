-- Write a query to find the maximum total earnings for all employees as well as the total number of employees who have maximum total earnings.
-- Then print these values as 2 space-separated integers.

-- Table: https://s3.amazonaws.com/hr-challenge-images/19629/1458557872-4396838885-ScreenShot2016-03-21at4.27.13PM.png

SELECT (salary * months) AS earnings, count(*)
FROM employee
GROUP BY  earnings
ORDER BY  earnings DESC limit 1;