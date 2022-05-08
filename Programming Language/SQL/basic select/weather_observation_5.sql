-- Query the two cities in STATION with the shortest and longest CITY names, as well as their respective lengths (i.e.: number of characters in the name).
-- If there is more than one smallest or largest city, choose the one that comes first when ordered alphabetically.

-- The STATION table is described as follows:
-- Columns: ID, City, State, Lat_N, Long_W

SELECT city, length(city)
FROM station
ORDER BY length(city), city ASC limit 1;

SELECT city, length(city)
FROM station
ORDER BY length(city) DESC limit 1; 