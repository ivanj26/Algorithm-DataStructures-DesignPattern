-- Query a list of CITY names from STATION for cities that have an even ID number.

-- Print the results in any order, but exclude duplicates from the answer.
-- The STATION table is described as follows:
-- Columns: ID, State, City, Lat_N, Long_W

SELECT distinct(city)
FROM station
WHERE id mod 2 = 0; 