-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | sell_date   | date    |
-- | product     | varchar |
-- +-------------+---------+
-- There is no primary key for this table, it may contain duplicates.
-- Each row of this table contains the product name and the date it was sold in a market.

-- Input: 
-- Activities table:
-- +------------+------------+
-- | sell_date  | product     |
-- +------------+------------+
-- | 2020-05-30 | Headphone  |
-- | 2020-06-01 | Pencil     |
-- | 2020-06-02 | Mask       |
-- | 2020-05-30 | Basketball |
-- | 2020-06-01 | Bible      |
-- | 2020-06-02 | Mask       |
-- | 2020-05-30 | T-Shirt    |
-- +------------+------------+
-- Output: 
-- +------------+----------+------------------------------+
-- | sell_date  | num_sold | products                     |
-- +------------+----------+------------------------------+
-- | 2020-05-30 | 3        | Basketball,Headphone,T-shirt |
-- | 2020-06-01 | 2        | Bible,Pencil                 |
-- | 2020-06-02 | 1        | Mask                         |
-- +------------+----------+------------------------------+

-- Write an SQL query to find for each date the number of different products sold and their names.
-- The sold products names for each date should be sorted lexicographically.
-- Return the result table ordered by sell_date.

select
    sell_date,
    count(distinct product) as num_sold,
    group_concat(distinct product) as products
from
    Activities
group by
    sell_date
order by
    sell_date;