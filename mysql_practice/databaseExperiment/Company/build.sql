/*
employee(employee_name,street,city) primary_key=employee_name
works(employee_name,company_name,salary) primary_key=employee_name
company(company_name,city) primary_key=company_name
managers(employee_name,manager_name) primary_key=employee_name
*/
create table employee
(
    employee_name varchar(32) not null,
    street varchar(32) not null,
    city varchar(32) not null,
    constraint pk
        primary key (employee_name)
);

create table works
(
    employee_name varchar(32) not null,
    company_name varchar(32) not null,
    salary float not null,
    constraint pk
        primary key (employee_name)
);
create table company
(
    company_name varchar(32) not null,
    city varchar(32),
    constraint pk
        primary key (company_name)
);
create table managers
(
    employee_name varchar(32) not null,
    manager_name varchar(32) not null,
    constraint pk
        primary key (employee_name)
);