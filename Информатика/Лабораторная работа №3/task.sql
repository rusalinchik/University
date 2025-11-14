DROP TABLE IF EXISTS order_items;
DROP TABLE IF EXISTS orders;
DROP TABLE IF EXISTS products;

CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    price NUMERIC(10, 2) NOT NULL
);

CREATE TABLE orders (
    order_id SERIAL PRIMARY KEY,
    order_date DATE NOT NULL
);

CREATE TABLE order_items (
    order_item_id SERIAL PRIMARY KEY,
    order_id INT NOT NULL,
    product_id INT NOT NULL,
    quantity INT NOT NULL,
    total_price NUMERIC(10,2) NOT NULL,

    FOREIGN KEY (order_id) REFERENCES orders(order_id) ON DELETE CASCADE,
    FOREIGN KEY (product_id) REFERENCES products(id) ON DELETE RESTRICT
);

INSERT INTO products (name, price) VALUES
('Диван', 45000),
('Подушка', 700),
('Стул', 1500),
('Кресло', 12000);

INSERT INTO orders (order_date) VALUES
('2025-10-13'),
('2025-06-12'),
('2025-11-15');

INSERT INTO order_items (order_id, product_id, quantity, total_price) VALUES
(1, 1, 1, 45000),
(1, 2, 2, 1400),
(2, 4, 1, 12000),
(3, 3, 3, 4500);

SELECT * FROM products;

SELECT oi.order_item_id, p.name AS product_name, oi.quantity, oi.total_price
FROM order_items oi
JOIN products p ON oi.product_id = p.id
WHERE oi.order_id = 1;

SELECT SUM(total_price) AS total_order_price
FROM order_items
WHERE order_id = 1;

SELECT o.order_id, o.order_date, SUM(oi.total_price) AS total_amount
FROM orders o
JOIN order_items oi ON o.order_id = oi.order_id
WHERE o.order_date BETWEEN '2025-06-01' AND '2025-12-31'
GROUP BY o.order_id, o.order_date
ORDER BY o.order_date;

SELECT p.name, SUM(oi.quantity) AS total_quantity
FROM order_items oi
JOIN products p ON oi.product_id = p.id
JOIN orders o ON oi.order_id = o.order_id
WHERE o.order_date BETWEEN '2025-06-01' AND '2025-12-31'
GROUP BY p.name
ORDER BY total_quantity DESC;

UPDATE products
SET price = 1600
WHERE id = 3;

DELETE FROM order_items
WHERE order_item_id = 2
RETURNING *;