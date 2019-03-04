SELECT DISTINCT A.Num FROM `Logs` A, `Logs` B, `Logs` C WHERE B.Id = A.Id+1 AND C.Id = A.Id+2 AND B.Num = A.Num AND C.Num = A.Num;
