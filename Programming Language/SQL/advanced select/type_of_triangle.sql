-- Write a query identifying the type of each record in the TRIANGLES table using its three side lengths.
-- Output one of the following statements for each record in the table:

select
	case
		when a + b > c then (
			case
				when a = b
				and b = c then 'Equilateral'
				when a = b
				or b = c
				or a = c then 'Isosceles'
				else 'Scalene'
			end
		)
		else 'Not A Triangle'
	end
from
	triangles;