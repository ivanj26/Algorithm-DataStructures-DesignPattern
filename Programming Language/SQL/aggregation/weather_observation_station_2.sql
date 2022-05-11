-- Query the following two values from the STATION table:
-- The sum of all values in LAT_N rounded to a scale of 2 decimal places.
-- The sum of all values in LONG_W rounded to a scale of 2 decimal places.

-- output: lat lon

select concat(round(sum(lat_n), 2), ' ', round(sum(long_w), 2)) from station;