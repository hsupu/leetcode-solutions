SELECT Name AS Customers FROM Customers WHERE NOT EXISTS (SELECT CustomerId FROM Orders WHERE Orders.CustomerId = Customers.Id);
