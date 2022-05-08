-- Query the list of CITY names from STATION which have vowels (i.e., a, e, i, o, and u) as both their first and last characters.
-- Your result cannot contain duplicates.

SELECT distinct(city)
FROM station
WHERE city regexp '^[aiueoAIUEO].*[aiueoAIUEO]$'