/*
Enter your query below.
Please append a semicolon ";" at the end of the query
*/

-- Given the product and invoice details at online store, find all the products that were not sold.
-- For each such product, display its SKU, and product name.
-- Order the result by SKU, ascending.

-- Schemas:
-- 1. Product table
-- id, sku, product_name, product_description, current_price, quantity_in_stock, is_active

-- 2. Invoice item table
-- invoice_id, product_id,  quantity, price, line_total_price

select sku, product_name
from product p
left join invoice_item it on it.product_id = p.id
where it.id is null
order by sku asc;