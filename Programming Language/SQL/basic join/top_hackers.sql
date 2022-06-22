-- https://www.hackerrank.com/challenges/full-score/problem?isFullScreen=true

select
    h.hacker_id,
    h.name
from
    Hackers h
    inner join (
        select
            s.hacker_id,
            c.challenge_id
        from
            Submissions s
            inner join Challenges c on c.challenge_id = s.challenge_id
            inner join Difficulty d on c.difficulty_level = d.difficulty_level
            and d.score = s.score
    ) f on f.hacker_id = h.hacker_id
group by
    h.hacker_id,
    h.name
having
    count(h.hacker_id) > 1
order by
    count(h.hacker_id) desc,
    h.hacker_id asc