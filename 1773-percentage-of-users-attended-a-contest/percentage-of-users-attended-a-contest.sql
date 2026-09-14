# Write your MySQL query statement below
SELECT contest_id, ROUND(COUNT(DISTINCT user_id)*100/(SELECT DISTINCT COUNT(user_id) FROM users),2) AS percentage FROM register
GROUP BY  contest_id
ORDER BY percentage DESC, contest_id;