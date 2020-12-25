/*
自建查询
*/
/*
1、查询出属于Comp.Sci.系的老师
*/

select
    instructor.name
from
    instructor
where
    instructor.dept_name="Comp.Sci."


/*
2、所有教师中工资大于50000的老师们的平均工资
*/
select
    avg(instructor.salary)
from
    instructor
where
    instructor.salary>50000
/*
3、统计出每个部门有多少老师
*/
select
    instructor.dept_name,
    sum(1) as num_of_department
from
    instructor
group by
    instructor.dept_name

/*
4、统计出每个部门的平均工资
*/
select
    instructor.dept_name
    avg(instructor.salary) as avg_salary_of_dep
from
    instructor
group by
    instructor.dept_name

/*
5、找出每个部门的最高工资
*/
select
    instructor.dept_name,
    max(instructor.salary) as max_salary_of_dep
from
    instructor
group by
    instructor.dept_name


/*
书上P105
*/
/*
a、找出Comp.Sci.系开设的具有3个学分的课程名称
*/
select
    c.title
from 
    course c
where
    c.dept_name="Comp.Sci."
and
    c.credits=3
/*
b、找出名叫Einstein的教师教授的所有学生的标识
*/

select 
    student.name
from
    instructor
join 
    teaches
join
    takes
join
    student
on
    instructor.name="Einstein"
and
    instructor.id=teaches.id
and
    teaches.course_id=takes.course
and
    teaches.sec_id=takes.sec_id
and
    takes.id=student.id

/*
c、找出教师的最高工资
*/

select
    max(instructor.salary)
from
    instructor


/*
d、找出工资最高的所有教师
*/

select
    instructor.name
from
    instructor
where
    instructor.salary=
    (
        select 
            max(instructor.salary) 
        from 
            instructor
    )

/*
e、找出2009年秋季开设的每个课程段的选课人数
*/
select
    takes.sec_id,
    sum(1) as num_of_sec_id
from
    takes
where
    takes.year="2009"
and
    takes.semester="Fall"
group by
    takes.sec_id


/*
f、找出2009年秋季开设的所有课程段中，找出最多的选课人数
*/
select
    sum(1)
from
    takes
where
    takes.year="2009"
and
    takes.semester="Fall"
group by
    takes.sec_id
order by
    sum(1) desc
limit 1


/*
f、找出在2009年秋季拥有最多选课人数的课程段
*/
select
    takes.sec_id
from
    takes
group by
    takes.sec_id
having
    sum(1)=(
        select
            sum(1)
        from
            takes
        where
            takes.year="2009"
        and
            takes.semester="Fall"
        group by
            takes.sec_id
        order by
            sum(1) desc
        limit 1        
    )

/*
3.24重写一些with语句
原来的语句，将其改写为不带with的sql查询
解释即求部门总工资大于部门间总工资的平均工资的部门
*/
with dept_total(dept_name,value) as(
    select 
        instructor.dept_name,
        sum(instructor.salary)
    from
        instructor
    group by
        instructor.dept_name
),
dept_total_avg(value) as(
    select
        avg(dept_total.value)
    from
        dept_total
)
select
    dept_name
from
    dept_total,dept_total_avg
where
    dept_total.value>=dept_total_avg.value;

/*
重写后
*/
select
    instructor.dept_name
from
    instructor
group by
    instructor.dept_name
having
    sum(instructor.salary)>=(
        select
            sum(instructor.salary)/count(distinct(instructor.dept_name))
        from
            instructor
    )