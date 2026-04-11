SELECT a.Id as `Id`
FROM `Weather` a
    join
    `Weather` b 
    ON datediff(a.RecordDate, b.RecordDate) = 1
    AND a.Temperature > b.Temperature;