# Write your MySQL query statement below
SELECT ROUND(SUM(order_date = customer_pref_delivery_date)*100/count(*),2) AS immediate_percentage FROM delivery
WHERE (customer_id,order_date) in (
    SELECT customer_id,min(order_date)
    FROM delivery
    GROUP BY customer_id
)