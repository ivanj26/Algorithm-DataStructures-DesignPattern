-- Output: Company Code, Founder, total number of lead managers, total number of senior managers,
-- total number of managers, and total number of employees.
-- 
-- Order your output by ascending company_code.

/*
Enter your query here.
*/

SELECT company_code, founder,
    (SELECT COUNT(DISTINCT lead_manager_code)
    FROM Lead_Manager
    WHERE company_code = c.company_code), 
    (SELECT COUNT(DISTINCT senior_manager_code)
    FROM Senior_Manager
    WHERE company_code = c.company_code), 
    (SELECT count(distinct manager_code)
    FROM Manager
    WHERE company_code=c.company_code), 
    (SELECT count(distinct employee_code)
    FROM Employee
    WHERE company_code=c.company_code)
FROM Company c
ORDER BY  company_code;