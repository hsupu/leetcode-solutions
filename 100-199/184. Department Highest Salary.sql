SELECT Department.Name AS Department, Employee.Name AS Employee, Employee.Salary
FROM
	Employee JOIN Department ON (Employee.DepartmentId = Department.Id),
	(SELECT MAX(Salary) AS Salary, DepartmentId
		FROM Employee
		GROUP BY DepartmentId
	) T
WHERE Employee.Salary = T.Salary AND Employee.DepartmentId = T.DepartmentId;
