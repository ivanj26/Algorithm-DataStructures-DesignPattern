-- Query the Western Longitude (LONG_W) where the smallest Northern Latitude (LAT_N) in STATION is greater than 38.778.
-- Round your answer to  decimal places.

select round(long_w, 4) from station
where lat_n = (select min(lat_n) from station where lat_n > 38.778);