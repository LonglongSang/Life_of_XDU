select Id, Salary from Employee  order by Salary desc limit 3 
union
select 10 as Id, sum(a.Salary) as Salary from 
(select Salary from Employee  order by Salary desc limit 3, -1) a;
