

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