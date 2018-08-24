SELECT Score, Rank FROM (SELECT Score, (SELECT COUNT(DISTINCT Score) FROM Scores AS B WHERE B.Score >= A.Score) AS Rank FROM Scores AS A) AS T ORDER BY Score DESC;
