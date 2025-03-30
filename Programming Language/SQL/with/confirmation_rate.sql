with confirmed_view as (
    select s.user_id, count(*) as number_of_confirmed 
    from Signups s
    left join Confirmations c on c.user_id = s.user_id
    where c.action = 'confirmed'
    group by s.user_id
),
timeout_view as (
    select s.user_id, count(*) as number_of_timeout 
    from Signups s
    left join Confirmations c on c.user_id = s.user_id
    where c.action = 'timeout'
    group by s.user_id
)

select s.user_id as user_id, ifnull(round(t.number_of_confirmed / (t.number_of_confirmed + t.number_of_timeout), 2), 0) as confirmation_rate
from Signups s
left join (
    select cw.user_id, ifnull(cw.number_of_confirmed, 0) as number_of_confirmed, ifnull(tw.number_of_timeout, 0) as number_of_timeout
        from confirmed_view cw
        left join timeout_view tw on tw.user_id = cw.user_id
) t on t.user_id = s.user_id