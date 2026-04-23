# Write your MySQL query statement below
SELECT name AS Customers
FROM Customers c
LEFT JOIN Orders o ON c.id = o.customerId
WHERE o.id IS NULL;


-- select name as Customers
-- from customers c
-- left join orders o on c.id = o.customerId 
-- where o.customerId is Null 