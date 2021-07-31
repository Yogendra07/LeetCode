# Write your MySQL query statement below

Select A.Name as Employee from Employee A , Employee B 
where A.ManagerId = B.Id and A.Salary > B.Salary;