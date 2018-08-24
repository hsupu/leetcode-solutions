SELECT A.Name AS Employee FROM Employee A LEFT JOIN Employee B ON (B.Id = A.ManagerId) WHERE A.Salary > B.Salary;
