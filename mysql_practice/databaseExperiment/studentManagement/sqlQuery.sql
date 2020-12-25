/*
instructor(instructor_id,age,name,gender,specialty_name) primary_key=instructor_id
student(student_id,name,age,gender,class_id) primary_key=student_id
major(major_name,specialty_name) primary_key=major_name
class(class_id,major_name) primary_key=class_id
specialty(specialty_name,builing,budget) primary_key=specialty_name
course(course_id,instructor_id,name,type,year,credit,semester)
takes(student_id,grade,make_up_exam,course_id,year,semester) primary_key=student_id,course_id,year,semester
*/

/*
查询学生所选修的课程及成绩，并给出必修课平均成绩和选修课平均成绩；
给定学生id
*/

create procedure queryCouseLearned(in id int)
begin
    (select
        takes.name as "course",/*查询所修的课程及成绩*/ 
        takes.course_id as "id",
        takes.grade as "grade"
    from
        takes
    where
        id=takes.student_id
    )
    union all
    (select
        "avgerage grade of bixiu",/*查询必修的平均成绩*/
        1,
        avg(takes.grade)
    from
        takes
    where
        takes.student_id=id
    and
        takes.type='b'
    )
    union all
    (select
        "avgerage grade of xuanxiu",/*查询选修的平均成绩*/
        2,
        avg(takes.grade)
    from
        takes
    where
        takes.student_id=id
    and
        takes.type<>'b'
    )
end;



/*
查询教过某学生的所有老师
给定学生id
*/
create procedure queryInstructorTeached(in id int)
begin
    select
        instructor.name
    from
        (select
            distinct(instructor.instructor_id) as instructor_id
        from
            takes,course,instructor_id
        on
            takes.student_id=id
        and
            takes.course_id=course.course_id
        and
            takes.year=course.year
        and
            takes.semester=course.semester
        and
            course.instructor_id=instructor.instructor_id
        ) as temp
    join
        instructor
    on
        temp.instructor_id=instructor.instructor_id
    ;
end;



/*
查询应当被开除的学生
*/

create procedure queryShouldExpelStudent()
begin
    select
        student.student_id,
        student.name
    from
        student
    where
        student.student_id in (
            /*统计一学期必修课挂科超过10学分的学生*/
            select
                distinct(takes.student_id)
            from
                takes
            join
                course
            on
                takes.course_id=course.course_id
            and
                takes.year=course.year
            and
                takes.semester=course.semester
            where
                takes.type='b'--必修课标志
            and
                takes.grade<60--低于60分就是挂科
            group by
                takes.student_id,year,semester--聚合学期
            having
                sum(course.credit)>10--一学期不及格的必修课学分大于10分
        )
    or
        student.student_id in (
            --统计累计必修课挂科超过30学分的学生
            select
                distinct(takes.student_id)
            from
                takes
            join
                course
            on
                takes.course_id=course.course_id
            and
                takes.year=course.year
            and
                takes.semester=course.semester
            where
                course.type='b'
            and
                takes.grade<60
            group by
                takes.student_id
            having
                sum(course.credit)>30
        )
    or
        student.student_id in (
            --统计累计选修课挂科超过20学分的学生
            select
                distinct(takes.student_id)
            from
                takes
            join
                course
            on
                takes.course_id=course.course_id
            and
                takes.year=course.year
            and
                takes.semester=course.semester
            where
                course.type<>'b'--非选修课
            and
                course.grade<60
            group by
                takes.student_id
            having
                sum(course.credit)>20
        );
end;

    





    




