SELECT name FROM
    (SELECT * FROM songs
    ORDER BY duration_ms
    LIMIT 5)
ORDER BY duration_ms DESC;