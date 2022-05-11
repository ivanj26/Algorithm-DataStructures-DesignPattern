-- Query the Western Longitude (LONG_W) for the largest Northern Latitude (LAT_N) in STATION that is less than 137.2345.
-- Round your answer to 4 decimal places.

select round(long_w, 4)
from station
where lat_n = (select max(lat_n) from station where lat_n < 137.2345);