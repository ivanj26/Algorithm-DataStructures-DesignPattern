-- Table: Movies

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | movie_id      | int     |
-- | title         | varchar |
-- +---------------+---------+
-- movie_id is the primary key (column with unique values) for this table.
-- title is the name of the movie.

-- Table: Users
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | user_id       | int     |
-- | name          | varchar |
-- +---------------+---------+
-- user_id is the primary key (column with unique values) for this table.
-- The column 'name' has unique values.


-- Table: MovieRating
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | movie_id      | int     |
-- | user_id       | int     |
-- | rating        | int     |
-- | created_at    | date    |
-- +---------------+---------+

-- # Write your MySQL query statement below
with 
    highest_user as (
        select t.name as results
        from (
            select u.user_id, u.name, count(*) as number_of_rating
            from Users u
            join MovieRating m on u.user_id = m.user_id
            group by u.user_id
            order by number_of_rating desc, u.name asc
        ) as t
        limit 1
    ),

    highest_movie_rating as (
        select t.title as results
        from (
            select m.title, avg(rating) as avg_rating
            from Movies m
            join MovieRating mv on mv.movie_id = m.movie_id
            where mv.created_at between '2020-02-01' and '2020-02-29'
            group by title
            order by avg_rating desc, title asc
        ) as t
        limit 1
    )
select highest_user.results from highest_user
union all
select highest_movie_rating.results from highest_movie_rating