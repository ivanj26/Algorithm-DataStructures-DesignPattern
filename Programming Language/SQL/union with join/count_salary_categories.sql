with 
low_income as (select 'Low Salary' as category, count(*) as accounts_count from Accounts where income < 20000),
middle_income as (select 'Average Salary' as category, count(*) as accounts_count from Accounts where income >= 20000 and income <= 50000),
high_income as (select 'High Salary' as category, count(*) as accounts_count from Accounts where income > 50000)

select * from low_income
union
select * from middle_income
union
select * from high_income