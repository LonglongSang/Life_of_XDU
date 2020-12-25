create table instructor
(
	instructor_id int auto_increment,
	age int not null,
	name varchar(20) not null,
	gender char not null,
    specialty_name varchar(20) not null,
	check(gender='m' or gender='f'),
	constraint instructor_pk
		primary key (instructor_id),
    constraint fk
        foreign key specialty_name references specialty(specialty_name)
);
create table student
(
	student_id int not null,
	name varchar(20) not null,
	age int not null,
	gender char not null,
    class_id int not null,
	check(gender='m' or gender='f'),
	constraint student_pk
		primary key (student_id),
    constraint fk
        foreign key class_id references class(class_id)
);
create table major
(
    major_name varchar(20),
    specialty_name varchar(20) not null,
    constraint primary_key
        primary key (major_name),
    constraint fk
        foreign key specialty_name references specialty(specialty_name)
);
create table class
(
    class_id int not null,
    major_name varchar(20) not null,
    constraint pk
        primary key class_id,
    constraint fk
        foreign key major_name references major(major_name)
);
create table specialty
(
    specialty_name varchar(20) not null,
    builing varchar(20) not null,
    budget float not null,
    constraint pk
        primary key specialty_name,
);
create table course
(
	course_id int not null,
    instructor_id int not null,
	name varchar(20) not null,
	type char not null,
	year year not null,
	credit int not null,
	semester varchar(4) not null,
	check(credit>0 and (type='b' or type='x' or type='z') and (semester="Fall" or semester="Spring")),
	constraint course_pk
		primary key (course_id),
	constraint f
		foreign key (instructor_id) references instructor (instructor_id)
)
comment 'type:b meaning bixiu  x meaning xuanxiu x meaning xianxuan';


create table takes
(
	student_id int not null,
	grade int not null,
	`make_up_exam` bool not null,
	course_id int not null,
	year year not null,
	semester varchar(4) not null,
    check((semester="Spring" or semester="Fall") and (not make_up_exam or (make_up_exam and grade<=60))),
	constraint pk
		primary key (student_id, course_id, year, semester),
	constraint fk
		foreign key (student_id) references student (student_id),
	constraint fk2
		foreign key (course_id) references course (course_id)
);
