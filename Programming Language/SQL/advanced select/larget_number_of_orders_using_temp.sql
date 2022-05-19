-- Table Orders:
-- customer_number, order_number

-- Find the largest number of Orders

with temp as (
    select customer_number, count(*) as cnt from Orders group by customer_number
);

select customer_number from temp where cnt = (select max(cnt) from temp);