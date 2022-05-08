-- Find the difference between the total number of CITY entries in the table and the number of distinct CITY entries in the table.
-- The STATION table is described as follows:

-- Columns: ID, City, State, Lat_N, Long_W

SELECT (count(city) - count(distinct(city)))
FROM station;