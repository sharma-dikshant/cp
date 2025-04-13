## Important sql commands
- `SELECT` - extracts data from a database
- `UPDATE` - updates data in a database
- `DELETE` - deletes data from a database
- `INSERT INTO` - inserts new data into a database
- `CREATE DATABASE` - creates a new database
- `ALTER DATABASE` - modifies a database
- `CREATE TABLE` - creates a new table
- `ALTER TABLE` - modifies a table
- `DROP TABLE` - deletes a table
- `CREATE INDEX` - creates an index (search key)
- `DROP INDEX` - deletes an index


# SELECT: 

SELECT column1, column2, ...
FROM table_name; -- selects specific columns from the table

SELECT * FROM table_name; -- selects all columns from the table

SELECT column1, column2, ... FROM table_name WHERE condition; -- selects only the rows that satisfy the condition


# SELECT DISTINCT:

SELECT DISTINCT column1, column2, ... FROM table_name; -- selects only distinct (different) values from the table in the specified columns

SELECT DISTINCT column1, column2, ... FROM table_name WHERE condition; -- selects only distinct values from the table in the specified columns that satisfy the condition

- count distinct values in a column:
```sql
SELECT COUNT(DISTINCT column_name) FROM table_name; -- counts the number of distinct values in the specified column
```

## List of Important SQL Clauses

- `WHERE` - filters records that fulfill a specified condition.
```sql
SELECT * FROM employees WHERE department = 'Sales';
```

- `ORDER BY` - sorts the result set in ascending or descending order. Includes `ASC` (ascending) and `DESC` (descending).
```sql
SELECT * FROM employees ORDER BY salary DESC;
```

- `GROUP BY` - groups rows that have the same values into summary rows, like "find the number of customers in each country."
```sql
SELECT country, COUNT(*) FROM customers GROUP BY country;
```

- `HAVING` - filters records that work on summarized `GROUP BY` results.
```sql
SELECT department, AVG(salary) FROM employees GROUP BY department HAVING AVG(salary) > 50000;
```

- `JOIN` - combines rows from two or more tables based on a related column between them.
```sql
SELECT orders.order_id, customers.name 
FROM orders 
JOIN customers ON orders.customer_id = customers.customer_id;
```

- `UNION` - combines the result set of two or more `SELECT` statements (only distinct values).
```sql
SELECT city FROM customers
UNION
SELECT city FROM suppliers;
```

- `UNION ALL` - combines the result set of two or more `SELECT` statements (including duplicates).
```sql
SELECT city FROM customers
UNION ALL
SELECT city FROM suppliers;
```

- `LIMIT` - specifies the number of records to return.
```sql
SELECT * FROM employees LIMIT 10;
```

- `OFFSET` - specifies the starting point for the records to return.
```sql
SELECT * FROM employees LIMIT 10 OFFSET 5;
```

- `LIKE` - searches for a specified pattern in a column.
```sql
SELECT * FROM customers WHERE name LIKE 'A%';
```

- `IN` - allows you to specify multiple values in a `WHERE` clause.
```sql
SELECT * FROM employees WHERE department IN ('HR', 'IT', 'Sales');
```

- `BETWEEN` - filters the result set within a certain range.
```sql
SELECT * FROM products WHERE price BETWEEN 50 AND 100;
```

- `EXISTS` - checks for the existence of any record in a subquery.
```sql
SELECT * FROM customers WHERE EXISTS (SELECT * FROM orders WHERE customers.customer_id = orders.customer_id);
```

- `CASE` - adds conditional logic to SQL queries.
```sql
SELECT name, 
    CASE 
        WHEN salary > 50000 THEN 'High'
        ELSE 'Low'
    END AS salary_category
FROM employees;
```

- `AS` - renames a column or table with an alias.
```sql
SELECT name AS employee_name, salary AS employee_salary FROM employees;
```

- `IS NULL` / `IS NOT NULL` - filters records with null or non-null values.
```sql
SELECT * FROM employees WHERE manager_id IS NULL;
```

- `FETCH` - retrieves a specific number of rows after an `OFFSET`.
```sql
SELECT * FROM employees OFFSET 5 ROWS FETCH NEXT 10 ROWS ONLY;
```

