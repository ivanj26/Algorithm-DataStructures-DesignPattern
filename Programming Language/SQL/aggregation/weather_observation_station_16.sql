-- Query the smallest Northern Latitude (LAT_N) from STATION that is greater than 38.778.
-- Round your answer to 4 decimal places.

select round(min(lat_n), 4) from station
where lat_n > 38.778;