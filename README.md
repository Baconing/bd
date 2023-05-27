# bd
bd is a SQL-like database software with its own "fork" of SQL adding a type system based on the query rather than the table.
you can force a type on a column by adding a type after the column name, however it is not required.

bd is a personal project im using to help me store data easily in my projects.
while bd will likely be a server/client system, it will likely also be available as a library for serverless applications. (e.g. game save files)

bd is currently in development and is not ready for use.

finally, bd is a way for me to learn C++, so it will likely not be ready for a while


examble bdq (bacon database query) to modify data :
```
update "asd": string, "-11": int, "1.1": float, "true": bool ("row1", "row2", "row3", "row4") into "table" where "asd": string ("name")
```


examble bdq to create a table
```
create table "table_name" ("column1": pk string, "column2": nullable int, "column3": float, "column4": bool)
```
OR 
```
create table "table_name" ("column1": pk, "column2")
```