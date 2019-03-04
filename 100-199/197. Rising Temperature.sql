SELECT A.Id FROM Weather A, Weather B WHERE A.Date = DATE_ADD(B.Date, INTERVAL 1 DAY) AND A.Temperature > B.Temperature;
