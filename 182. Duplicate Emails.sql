# Write your MySQL query statement below
SELECT email 
FROM (
    SELECT email, COUNT(email) AS num
    FROM Person
    GROUP BY email
) AS temp_table
WHERE num > 1;