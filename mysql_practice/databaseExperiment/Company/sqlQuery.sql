/*
4个表
employee(employee_name,street,city) primary_key=employee_name
works(employee_name,company_name,salary) primary_key=employee_name
company(company_name,city) primary_key=company_name
managers(employee_name,manager_name) primary_key=employee_name
目录
*/

/*
3.9
*/
/*
a、找出所有为"First Bank Corporation"工作的雇员名字及其居住城市
*/
select
    employee.employee_name,
    employee.city
from
    works
left join
    employee
on
    works.company_name="Fisrt Bank Corporation"
and
    works.employee_name=employee.employee_name

/*
b、找出所有为"Fisrt Bank Corporation"工作且薪金超过10000的雇员名字、居住城市和街道
*/
select
    employee.employee_name,
    employee.city,
    employee.street
from
    works
left join
    employee
on
    works.company_name="Fisrt Bank Corporation"
and
    works.salary>10000
and
    works.employee_name=employee.employee_name
/*
c、找出所有不为"Fisrt Bank Corporation"工作的雇员
*/

select
    works.employee_name
from
    works
where
    works.company_name<>"Fisrt Bank Corporation"


/*
d、找出数据库中工资高于"Small Bank Corporation"的每个雇员的所有雇员
*/

select
    works.employee_name
from
    works
where
    works.salary>(
        select
            max(works.salary)
        from
            works
        where
            works.company_name="Small Bank Corporation"
    )
/*
e、假设一个公司可以在好几个城市有分部。找出位于"Small Bank Corporation"所有所在
城市的所有公司
*/
--company(company_name,city) primary_key=company_name
select
    c1.company_name
from
    company c1
join
    comment c2
on
    c2.company_name="Small Bank Corporation"
and
    c1.city=c2.city
group by
    c1.company_name
having
    sum(distint(c1.city))=(
        select
            sum(distint(company.city))
        from
            company
        where
            company.company_name="Small Bank Corporation"
    )


/*
f、找出雇员最多的公司
*/

select
    works.company_name
from
    works
group by
    works.company_name
having
    sum(1)=(
        select
            max(temp.tot)
        from
            (select
                sum(1) as tot
            from
                works
            group by
                works.company_name
            ) as temp
    )

/*
g、找出平均工资高于"First Bank Corporation"平均工资的那些公司
*/
select
    works.company_name
from
    works
group by
    works.company_name
having
    avg(works.salary)>(
        select
            avg(works.salary)
        from
            works
        where
            works.company_name="First Bank Corporation"
    )



/*
3.10
*/

/*
a、修改Jones现在的居住城市为Newton市
*/
update
    employee
set
    employee.city="Newton"
where
    employee.employee_name="Jones"
/*
b、为"First Bank Corporation"所有工资不超过10000美元的经理增长10%的工资
对工资超过10000美元的值增长3%
*/
update
    works
set
    works.salary=(
        case
            when
                works.salary<10000
            then
                works.salary*1.1
            else
                works.salary*1.03
        end
    )
where
    works.company_name="First Bank Corporation"
and
    works.employee_name in (
        select
            managers.manager_name
        from
            managers
    )

/*
3.16
*/

/*
a、找出所有为"First Bank Corporation"工作的雇员名字
*/
select
    works.employee_name
from
    works
where
    works.company_name="First Bank Corporation"

/*
b、找出所有居住城市与公司所在城市相同的雇员
*/
/*
方法1
*/
select
    works.employee_name
from
    works
inner join
    employee
inner join
    company
on
    works.employee_name=employee.employee_name
and
    works.company_name=company.company_name
and
    employee.city=company.company_name

/*
方法2
*/
select
    works.employee_name
from
    works,employee,company
on
    works.employee_name=employee.employee_name
and
    works.company_name=company.company_name
and
    employee.city=company.company_name


/*
c、找出所有居住街道和城市与经理相同的雇员
*/

select
    manager.employee_name
from
    managers,employee as e1,employee as e2
on
    manager.employee_name=e1.employee_name
and
    manager.manager_name=e2.employee_name
and
    e1.city=e2.city
and
    e1.street=e2.street

/*
d、找出工资高于其所在公司雇员平均水平的所有雇员
*/
select
    works.employee_name
from
    works
inner join
    (
        select
            works.company_name,
            avg(works.salary) as avg_salary
        from
            works
        group by
            works.company_name
    ) as mapping
on
    works.company_name=mapping.company_name
and
    works.salary>manager.avg_salary



/*
e、找出工资总和最小的公司
*/
with temp as(
    select
        works.company_name,
        sum(works.salary) as sum_salary
    from
        works
    group by
        works.company_name
)
select
    t1.company_name
from
    temp as t1,temp as t2
group by
    t1.company_name
having
    sum(t1.sum_salary>t2.sum_salary)==0



/*
3.17
*/
/*
a、为"First Bank Corporation"的所有雇员增长10%的工资
*/
update
    works
set
    works.salary=works.salary*1.1
when
    works.company_name="First Bank Corporation"

/*
b、为"First Bank Corporation"的所有经理增长10%的工资
*/

update
    works
set
    works.salary=works.salary*1.1
where
    works.company_name="First Bank Corporation"
and
    works.employee_name in (
        select
            manager.manager_name
        from
            manager
    )

/*
c、删除"Small Bank Corporation"的雇员在works中的所有元祖
*/

delete
from
    works
where
    works.company_name="First Bank Corporation"

    