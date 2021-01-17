/*
This is use for mysql
*/


/*
为什么有些mysql的指南上要用到delimiter $ XXXX(mysql语句) $;
因为mysql默认的定界符(delimiter)是";"，所以想输入多条带分号的语句一起执行时，就会被动被分开
所以我们要修改定界符，这里修改成了"$"，其实我们也可以用别的
同时当我们执行完后，尽可能重新将定界符重新修改为";"
*/

alter table titles_test rename titles_2017;
--将titles_test表更名为titles_2017

alter table actor add column create_date datetime not null default "2020-10-01 00:00:00";
--添加新列

alter table temp comment="this is add a comment to table temp";
--添加注释

alter table temp change val v int not null;
--将temp表中的val列名字改为v，同时还要写上他的类型，很奇怪

alter table temp modify column cnt int;
--修改列信息，将temp表中的cnt列改为int型

alter table temp drop column cnt;
--删除temp表中的cnt列

alter table audit add foreign key(emp_no) references employees_test(id);
--对audit表添加外键约束

create trigger audit_log after insert on employees_test
for each row
begin
insert into audit values(new.id,new.name);
end
--触发器
--new表示新的值，old表示旧的值

show triggers;--显示所有的触发器

create unique index uniq_idx_firstname on actor(first_name);
--对actor表的first_name列创建唯一索引
create index idx_lastname on actor(last_name);
--对actor表的last_name创建普通索引
select s.* from salaries s force index (idx_emp_no) where s.emp_no = 10005;
--使用索引查找

select d.dept_no,group_concat(d.emp_no separator ",")
from dept_emp d
group by d.dept_no
--group_concat

create table if not exists actor_name(
    first_name varchar(45) not null,
    last_name varchar(45) not null
);
insert into actor_name
select a.first_name,a.last_name
from actor a;
--创建actor_name表，并通过actor表向actor_name表进行插入



insert into titles_test values
('1', '10001', 'Senior Engineer', '1986-06-26', '9999-01-01'),
('2', '10002', 'Staff', '1996-08-03', '9999-01-01'),
('3', '10003', 'Senior Engineer', '1995-12-03', '9999-01-01'),
('4', '10004', 'Senior Engineer', '1995-12-03', '9999-01-01'),
('5', '10001', 'Senior Engineer', '1986-06-26', '9999-01-01'),
('6', '10002', 'Staff', '1996-08-03', '9999-01-01'),
('7', '10003', 'Senior Engineer', '1995-12-03', '9999-01-01');
--insert



create table if not exists actor(
    actor_id smallint(5) not null,
    first_name varchar(45) not null,
    last_name varchar(45) not null,
    last_update date not null,
    constraint pk
        primary key(actor_id)
);
--create

create procedure insertIntoFlights
(in a int,in b double,in c int,in d int,in e int,in f int)
begin
    insert into 
    flights(flight_id,price,num_seat,num_avail,from_city,to_city) 
    values (a,b,c,d,e,f);
end;
--存储过程in a int表示a是一个输入变量 int表示类型



insert ignore into actor values('3','ED','CHASE','2006-02-15 12:34:33');
--insert ignore，如果主键已经存在就跳过

replace into actor values('3','ED','CHASE','2006-02-15 12:34:33');
--replace insert，如果主键存在就替代



create view as view_temp select * from temp;
--创建视图，视图名字view_temp，来自table temp

create or replace view view_temp as select temp.val,temp.cnt from temp;
--更新view_temp

alter view tt as select * from temp;
--更新view

show full columns from temp;
show create table temp;--显示table temp的信息
show create view temp;--显示视图temp的信息
desc temp;
describe temp;
--显示temp表的信息,desc是describe的缩写

