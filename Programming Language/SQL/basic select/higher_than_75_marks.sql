-- Query the Name of any student in STUDENTS who scored higher than  Marks.
-- Order your output by the last three characters of each name.
--   If two or more students both have names ending in the same last three characters (i.e.: Bobby, Robby, etc.),
-- secondary sort them by ascending ID.

select `name` from students
where marks > 75
order by right(name, 3), id asc;