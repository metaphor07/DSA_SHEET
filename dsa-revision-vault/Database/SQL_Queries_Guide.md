# SQL Queries: Simple Examples and Practical Tips

This is a practical SQL reference using a small online-store database. Examples use mostly standard SQL; a few commands (such as `LIMIT`) may differ slightly between MySQL, PostgreSQL, SQL Server, and Oracle.

## Sample tables used in the examples

```sql
CREATE TABLE customers (
  customer_id INT PRIMARY KEY,
  name        VARCHAR(100) NOT NULL,
  email       VARCHAR(150) UNIQUE,
  city        VARCHAR(50),
  joined_on   DATE
);

CREATE TABLE products (
  product_id INT PRIMARY KEY,
  product_name VARCHAR(100) NOT NULL,
  category   VARCHAR(50),
  price      DECIMAL(10,2),
  stock      INT DEFAULT 0
);

CREATE TABLE orders (
  order_id   INT PRIMARY KEY,
  customer_id INT NOT NULL,
  order_date DATE,
  status     VARCHAR(20),
  FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);

CREATE TABLE order_items (
  order_id   INT,
  product_id INT,
  quantity   INT,
  unit_price DECIMAL(10,2),
  PRIMARY KEY (order_id, product_id),
  FOREIGN KEY (order_id) REFERENCES orders(order_id),
  FOREIGN KEY (product_id) REFERENCES products(product_id)
);
```

## 1. Reading data: `SELECT`

```sql
-- Every column and row (avoid this in production when possible)
SELECT * FROM customers;

-- Only required columns
SELECT name, city FROM customers;

-- Rename result columns with aliases
SELECT product_name AS product, price AS selling_price
FROM products;

-- Unique values only
SELECT DISTINCT city FROM customers;
```

## 2. Filtering rows: `WHERE`

```sql
SELECT * FROM products WHERE price > 1000;

SELECT * FROM customers WHERE city = 'Delhi';

-- Both conditions must be true
SELECT * FROM products
WHERE category = 'Electronics' AND stock > 0;

-- Either condition can be true
SELECT * FROM customers
WHERE city = 'Delhi' OR city = 'Mumbai';

-- A range, including both endpoints
SELECT * FROM products WHERE price BETWEEN 500 AND 2000;

-- One of a list of values
SELECT * FROM orders WHERE status IN ('pending', 'shipped');

-- Text pattern: % means any number of characters, _ means one character
SELECT * FROM customers WHERE name LIKE 'A%';

-- Missing values must use IS NULL, never = NULL
SELECT * FROM customers WHERE email IS NULL;
```

## 3. Sorting and limiting: `ORDER BY`, `LIMIT`

```sql
-- Highest priced products first
SELECT product_name, price
FROM products
ORDER BY price DESC;

-- Sort by city, then name
SELECT name, city FROM customers
ORDER BY city ASC, name ASC;

-- First five most expensive products (MySQL/PostgreSQL/SQLite)
SELECT product_name, price FROM products
ORDER BY price DESC
LIMIT 5;
```

> SQL Server: use `SELECT TOP 5 ...`. Standard SQL / newer databases may use `FETCH FIRST 5 ROWS ONLY`.

## 4. Adding data: `INSERT`

```sql
INSERT INTO customers (customer_id, name, email, city, joined_on)
VALUES (1, 'Asha Sharma', 'asha@example.com', 'Delhi', '2026-01-10');

-- Insert several rows at once
INSERT INTO products (product_id, product_name, category, price, stock)
VALUES
  (101, 'Wireless Mouse', 'Electronics', 799.00, 25),
  (102, 'Notebook', 'Stationery', 80.00, 100);

-- Insert results produced by another query
INSERT INTO premium_customers (customer_id, name)
SELECT customer_id, name
FROM customers
WHERE customer_id IN (
  SELECT customer_id FROM orders
  GROUP BY customer_id
  HAVING COUNT(*) >= 10
);
```

## 5. Changing and removing rows: `UPDATE`, `DELETE`

```sql
-- Update selected rows
UPDATE products
SET price = price * 0.90
WHERE category = 'Stationery';

-- Update more than one column
UPDATE orders
SET status = 'shipped', order_date = CURRENT_DATE
WHERE order_id = 501;

-- Delete only matching rows
DELETE FROM customers
WHERE customer_id = 99;
```

> **Safety rule:** first run the same `WHERE` condition with `SELECT *`. An `UPDATE` or `DELETE` without `WHERE` affects every row.

## 6. Aggregates: `COUNT`, `SUM`, `AVG`, `MIN`, `MAX`

```sql
SELECT COUNT(*) AS total_customers FROM customers;

SELECT AVG(price) AS average_price,
       MIN(price) AS cheapest_price,
       MAX(price) AS highest_price
FROM products;

-- Value of each order
SELECT order_id, SUM(quantity * unit_price) AS order_total
FROM order_items
GROUP BY order_id;
```

## 7. Grouping data: `GROUP BY` and `HAVING`

```sql
-- Customer count in every city
SELECT city, COUNT(*) AS customer_count
FROM customers
GROUP BY city;

-- Categories whose average price exceeds 500
SELECT category, AVG(price) AS average_price
FROM products
GROUP BY category
HAVING AVG(price) > 500;
```

`WHERE` filters rows **before** grouping. `HAVING` filters grouped results **after** grouping.

```sql
-- Correct: only in-stock products are counted, then groups are filtered
SELECT category, COUNT(*) AS available_products
FROM products
WHERE stock > 0
GROUP BY category
HAVING COUNT(*) >= 3;
```

## 8. Joining tables

```sql
-- INNER JOIN: only orders that have a matching customer
SELECT o.order_id, c.name, o.order_date, o.status
FROM orders AS o
INNER JOIN customers AS c ON c.customer_id = o.customer_id;

-- LEFT JOIN: keep every customer, even those without an order
SELECT c.name, o.order_id
FROM customers AS c
LEFT JOIN orders AS o ON o.customer_id = c.customer_id;

-- Customers with no orders (anti-join)
SELECT c.customer_id, c.name
FROM customers AS c
LEFT JOIN orders AS o ON o.customer_id = c.customer_id
WHERE o.order_id IS NULL;

-- Join four tables to show every ordered product
SELECT o.order_id, c.name, p.product_name,
       oi.quantity, oi.unit_price,
       oi.quantity * oi.unit_price AS line_total
FROM orders o
JOIN customers c   ON c.customer_id = o.customer_id
JOIN order_items oi ON oi.order_id = o.order_id
JOIN products p    ON p.product_id = oi.product_id;
```

### Join tip

Always state the matching rule in `ON`. A missing or incorrect join condition can create a huge *Cartesian product* (every row matched with every other row).

## 9. Subqueries

```sql
-- Products priced above the overall average
SELECT product_name, price
FROM products
WHERE price > (SELECT AVG(price) FROM products);

-- Customers who placed at least one order
SELECT name
FROM customers
WHERE customer_id IN (SELECT customer_id FROM orders);

-- EXISTS is often clear for "does a related row exist?"
SELECT c.name
FROM customers c
WHERE EXISTS (
  SELECT 1
  FROM orders o
  WHERE o.customer_id = c.customer_id
);

-- Correlated subquery: compare product to its own category average
SELECT p.product_name, p.category, p.price
FROM products p
WHERE p.price > (
  SELECT AVG(p2.price)
  FROM products p2
  WHERE p2.category = p.category
);
```

## 10. Common table expressions (CTEs): `WITH`

CTEs make complex queries easier to read by naming intermediate results.

```sql
WITH order_totals AS (
  SELECT order_id, SUM(quantity * unit_price) AS total
  FROM order_items
  GROUP BY order_id
)
SELECT c.name, o.order_id, ot.total
FROM orders o
JOIN customers c ON c.customer_id = o.customer_id
JOIN order_totals ot ON ot.order_id = o.order_id
WHERE ot.total > 2000;
```

## 11. Conditional logic and handling NULLs

```sql
-- Create readable categories from values
SELECT product_name, stock,
  CASE
    WHEN stock = 0 THEN 'Out of stock'
    WHEN stock < 10 THEN 'Low stock'
    ELSE 'Available'
  END AS stock_status
FROM products;

-- Replace NULL with a fallback value
SELECT name, COALESCE(city, 'Unknown') AS city
FROM customers;

-- Conditional aggregation: count several statuses in one scan
SELECT
  COUNT(*) AS all_orders,
  SUM(CASE WHEN status = 'shipped' THEN 1 ELSE 0 END) AS shipped_orders,
  SUM(CASE WHEN status = 'pending' THEN 1 ELSE 0 END) AS pending_orders
FROM orders;
```

## 12. Date queries

```sql
-- Orders in a date range
SELECT * FROM orders
WHERE order_date >= '2026-01-01'
  AND order_date <  '2026-02-01';

-- Usually supported, but date functions vary by database
SELECT * FROM orders
WHERE order_date = CURRENT_DATE;
```

> For timestamp columns, prefer a half-open range (`>= start` and `< next_day`) instead of `BETWEEN`; it avoids accidentally excluding times late on the final day.

## 13. Window functions (advanced but very useful)

Unlike `GROUP BY`, window functions keep individual rows visible.

```sql
-- Rank products by price within each category
SELECT product_name, category, price,
       RANK() OVER (PARTITION BY category ORDER BY price DESC) AS price_rank
FROM products;

-- Running total of order revenue by date
WITH daily_sales AS (
  SELECT o.order_date, SUM(oi.quantity * oi.unit_price) AS revenue
  FROM orders o
  JOIN order_items oi ON oi.order_id = o.order_id
  GROUP BY o.order_date
)
SELECT order_date, revenue,
       SUM(revenue) OVER (ORDER BY order_date) AS running_revenue
FROM daily_sales;

-- Latest order for each customer
WITH ranked_orders AS (
  SELECT o.*,
         ROW_NUMBER() OVER (
           PARTITION BY customer_id ORDER BY order_date DESC, order_id DESC
         ) AS row_num
  FROM orders o
)
SELECT * FROM ranked_orders WHERE row_num = 1;
```

## 14. Set operations

```sql
-- UNION removes duplicate rows; both queries need compatible columns
SELECT email FROM customers WHERE city = 'Delhi'
UNION
SELECT email FROM customers WHERE city = 'Mumbai';

-- UNION ALL keeps duplicates and is generally faster
SELECT customer_id FROM orders WHERE status = 'pending'
UNION ALL
SELECT customer_id FROM orders WHERE status = 'shipped';
```

## 15. Table design commands (DDL)

```sql
CREATE TABLE categories (
  category_id INT PRIMARY KEY,
  category_name VARCHAR(50) NOT NULL UNIQUE
);

ALTER TABLE products ADD COLUMN description VARCHAR(500);

CREATE INDEX idx_orders_customer_date
ON orders (customer_id, order_date);

DROP TABLE categories; -- permanently removes the table and its data
```

## 16. Transactions

Use a transaction when several changes must either all succeed or all be undone.

```sql
BEGIN;

UPDATE products
SET stock = stock - 1
WHERE product_id = 101 AND stock > 0;

INSERT INTO orders (order_id, customer_id, order_date, status)
VALUES (601, 1, CURRENT_DATE, 'pending');

COMMIT;   -- make the changes permanent
-- ROLLBACK; -- use instead of COMMIT to undo uncommitted changes
```

## Tips and tricks for complex queries

1. **Build in layers.** Write and test the base `SELECT`, then joins, then filters, then aggregation. Use CTEs to give each layer a meaningful name.
2. **Use table aliases consistently.** `customers c` and `orders o` make joins short and prevent ambiguous-column errors.
3. **Avoid `SELECT *` in final queries.** Explicit columns document the result, prevent unwanted data exposure, and reduce data transferred.
4. **Know row multiplication.** Joining a customer to orders and order items creates one row per item, not one row per customer. Aggregate at the correct level.
5. **Use `COUNT(column)` carefully.** `COUNT(*)` counts all rows; `COUNT(email)` ignores rows where `email` is `NULL`.
6. **Prefer `EXISTS` for existence checks.** It expresses intent clearly and avoids duplicate rows that joins can create.
7. **Do not use `NOT IN` when the subquery may return `NULL`.** Prefer `NOT EXISTS`:

   ```sql
   SELECT c.name
   FROM customers c
   WHERE NOT EXISTS (
     SELECT 1 FROM orders o WHERE o.customer_id = c.customer_id
   );
   ```

8. **Index join and filter columns.** Common candidates include foreign keys (`orders.customer_id`) and frequently filtered date/status columns. Check the execution plan before adding many indexes.
9. **Keep functions off indexed filter columns when possible.** `WHERE order_date >= ...` can use an index more easily than `WHERE YEAR(order_date) = 2026`.
10. **Use parameterized queries in applications.** Never concatenate user input into SQL; parameters prevent SQL injection.
11. **Format long queries.** Put each selected expression and each join/condition on its own line. Readability prevents mistakes.
12. **Inspect the query plan.** Use `EXPLAIN` / `EXPLAIN ANALYZE` (syntax varies by database) when a correct query is slow.

## A complete complex-query example

Find the top three customers by completed-order spending in each city.

```sql
WITH customer_spend AS (
  SELECT
    c.customer_id,
    c.name,
    c.city,
    SUM(oi.quantity * oi.unit_price) AS total_spent
  FROM customers c
  JOIN orders o ON o.customer_id = c.customer_id
  JOIN order_items oi ON oi.order_id = o.order_id
  WHERE o.status = 'completed'
  GROUP BY c.customer_id, c.name, c.city
), ranked_customers AS (
  SELECT *,
         DENSE_RANK() OVER (
           PARTITION BY city ORDER BY total_spent DESC
         ) AS city_rank
  FROM customer_spend
)
SELECT customer_id, name, city, total_spent, city_rank
FROM ranked_customers
WHERE city_rank <= 3
ORDER BY city, city_rank, name;
```

**How to read it:** the first CTE calculates each customer's completed-order spending; the second ranks those customers within their city; the final query keeps the top three ranks.

