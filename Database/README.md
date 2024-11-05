# Database 
Database is a storage system that has a collection of data. Relational database store in the form of tables that can be easily retrieved managed and updated.

### What is an ER diagram?
describe the relationship of entities that need to be stored in a database. 

### Entity - 
living or a nonliving component that is showcased by rectangle 

> weak Entity - an entity that relies on another entity represeted by double rectangle

### Attribute 
describe the property of an entity

**Key attribute - **uniquely identifies an entity from the set of entities . 

eg. Roll number



### Types of SQL Commands 
1. Data Definition Language ( DLL ) 
    1. Create
    2. Alter
    3. Drop
    4. Truncate
2. Data Manipulation Language ( DML )
    1. Select
    2. Update
    3. Delete
    4. Insert
3. Data Control Language ( DCL )
    1. Grant
    2. Revoke 
4. Transaction Control Language 
    1. Commit 
    2. Rollback 


```
Select column1,column2
From table_name
Where conditon1, condition2
Group by column1,column2
Having condition1, condition2
Order by column1,column2
```
### Data Types in SQL
- Exact Numeric 
    - int, smallint, bit, decimal
- Approximate Numeric
    - float, real
- Data and Time
    - data,time, timestamp
- String 
    - char,varchar,text
- binary
    - binary, varbinary, image
### Operators in SQL
- Arithmetic 
    - + , - , *, /, %
- Logical
    - ALL,AND,ANY,BETWEEN, EXISTS
- Comparision
    -  =,!=,>,<,<=,!<,!> 
# Some commands 
- show database;
- use <database>;
- show tables;
- select <columns> from <table_name>;
- describe <table_name>; 
- create database <database_name>; 
- create table <table_name> (column1 data_type, column2 data_type,column3 data_type...);
- insert into <table_name> values(column_val1),(column_val2),(column_val3,...);
- select distinct <column_name> from <table_name>; to show distinct values in a particular column
- select count(column_name) from <table_name>; to count the number 
- select count(colum_name) as <alias_name> from <table_name>; - using aliases
- select sum(column_name) as <table_name>; - adding the column values 
- select avg(column_name) as <table_name>; - to find the average of the columns
- select * from <table_name>; - to get all the columns
- select <columns> from <table_name> where <column> condition <value>;
- select <columns> from <table_name> where <column>in (conition);
- select <columns> from <table_name> where <column> between (conition) and (condition);
- select <column> aggregate_func(columns) from <table> group by <column>;
what it does is it first groups the rows based on the condition and then apply aggregate function

- select <columns> from <table> order by <column> ;
- select <columns> from <table> order by <column> desc;
- select length('some_string') as <alias>;
- select repeat('some_symbol',number);
- select ( num + num) as <alias>
- select upper('string');  or ucase also works
- select curdate(); - gives the current date
- select day(currdate()); - extract the day from the currdate;
- select now();
string function

- select <columns>, concat(column1,column2) as <alias> from <tablename>;
- select replace("word1 word2 word3","word2","word4") - it replaces 2nd word by 4th 
