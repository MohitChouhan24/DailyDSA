# Write your MySQL query statement below
SELECT query_name , ROUND(AVG(rating/position),2) quality, ROUND(SUM(rating<3)*100/COUNT(rating),2) poor_query_percentage
FROM queries
GROUP BY query_name;