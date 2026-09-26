# Write your MySQL query statement below
WITH new_table AS(
    SELECT 
        d.name AS Department,
        e.name AS Employee,
        e.salary AS Salary,
        DENSE_RANK() OVER(
            PARTITION BY d.name
            ORDER BY e.salary DESC
        ) AS Ranking
    FROM employee e
    LEFT JOIN department d
    ON e.departmentId = d.id
)
SELECT 
    Department,Employee,Salary
FROM new_table 
WHERE Ranking <= 3;

