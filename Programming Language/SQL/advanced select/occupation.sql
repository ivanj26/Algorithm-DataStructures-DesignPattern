-- query output: There are a total of [occupation_count] [occupation]s.

SELECT
    CONCAT(name, '(', LEFT(occupation, 1), ')')
FROM
    OCCUPATIONS
ORDER BY
    name asc;

SELECT
    CONCAT(
        'There are a total of ',
        total,
        ' ',
        occupation,
        's.'
    )
FROM
    (
        SELECT
            count(*) as total,
            lower(occupation) as occupation
        FROM
            OCCUPATIONS
        GROUP BY
            occupation
        ORDER BY
            total asc
    ) t;