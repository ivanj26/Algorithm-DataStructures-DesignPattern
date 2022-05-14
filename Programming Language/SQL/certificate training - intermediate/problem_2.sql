/*
Enter your query below.
Please append a semicolon ";" at the end of the query
*/

-- A business is analyzing data by country.
-- For each country, display the country name, total number of invoices, and their average amount.
-- Format the average amount as a floating number with 6 decimal places.
-- Return only those countries where their average invoice amount is greater than the average invoice amount over all invoices

-- Schemas:
-- 4 tables

-- 1. country
-- id, country_name

-- 2. city
-- id, city_name, postal_code, country_id

-- 3. customer
-- id, customer_name, city_id, customer_address, contact_person, email, phone, is_active

-- 4. invoice
-- id, invoice_number, customer_id, user_account_id, total_price

select co.country_name, sum(invoice_number), round(avg(iv.total_price), 6)
from invoice iv
inner join customer c on c.id = iv.customer_id
inner join city ci on ci.id = c.city_id
inner join country co on co.id = ci.country_id
group by co.country_name
having avg(iv.total_price) > (select avg(total_price) from invoice);