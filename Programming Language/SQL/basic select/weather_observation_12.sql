-- Query the list of CITY names from STATION that do not start with vowels and do not end with vowels.
-- Your result cannot contain duplicates.

SELECT distinct(city)
FROM station
WHERE
	city regexp '^(?![aiueoAIUEO]).*$'
	AND city NOT regexp '^*.[aiueoAIUEO]$';