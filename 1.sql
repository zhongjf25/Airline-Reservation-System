create database db_test;
use db_test;

create table User_info
(
	UserID int auto_increment primary key, 
	UserName varchar(20) not null,
	UserPwd varchar(30) not null,
	UserSex int not null
)

select * from User_info;
insert into User_info (UserName, UserPwd, UserSex) values ('Alice', '1', 0);
insert into User_info (UserName, UserPwd, UserSex) values ('Bob', '2', 0);
delete from User_info where UserName='Alice';
delete from User_info where UserPwd='2';

select Username from User_info where Username='Alice';
select Username from User_info where Username='B';
select count(*) from User_info where Username='Alice';

select UserSex from User_info where UserName='Alice' and UserPwd='123';
