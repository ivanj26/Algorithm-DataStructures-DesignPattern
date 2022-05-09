-- Query the average population of all cities in CITY where District is California.

SELECT avg(population)
FROM city
WHERE district = 'California';