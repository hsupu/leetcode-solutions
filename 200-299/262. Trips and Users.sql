SELECT
    Request_at AS 'Day',
    round(
        COUNT(
            IF (Status != 'completed', TRUE, NULL)
        ) / count(*),
        2
    ) AS 'Cancellation Rate'
FROM
    (
        SELECT
            Request_at,
            Status
        FROM
            Users
        JOIN (
            SELECT
                Client_Id,
                Request_at,
                Status
            FROM
                Trips
            WHERE
                Request_at >= '2013-10-01'
            AND Request_at <= '2013-10-03'
        ) AS a ON Users.Users_Id = a.Client_Id
        WHERE
            Role = 'client'
        AND Banned = 'No'
    ) b
GROUP BY
    Request_at
