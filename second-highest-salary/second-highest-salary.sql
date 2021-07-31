# Write your MySQL query statement below

Select max(Salary) as SecondHighestSalary from Employee
where Salary != (Select max(Salary) from Employee);