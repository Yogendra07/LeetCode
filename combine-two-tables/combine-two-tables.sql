# Write your MySQL query statement below

Select FirstName,LastName,City,State from Person P LEFT JOIN Address A on P.PersonId = A.PersonId;