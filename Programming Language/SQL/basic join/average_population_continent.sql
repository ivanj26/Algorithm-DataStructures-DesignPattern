-- Given the CITY and COUNTRY tables, query the names of all the continents (COUNTRY.Continent)
-- and their respective average city populations (CITY.Population) rounded down to the nearest integer.
-- Note: CITY.CountryCode and COUNTRY.Code are matching key columns.

select continent, floor(avg(c.population))
from city c
inner join country co on co.code = c.countrycode
group by continent
order by continent asc;