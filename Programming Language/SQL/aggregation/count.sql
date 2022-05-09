-- Query a count of the number of cities in CITY having a Population larger than 100,000.

SELECT count(*)
FROM city
WHERE population > 100000;