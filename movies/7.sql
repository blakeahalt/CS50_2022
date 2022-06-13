-- In 7.sql, write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
-- Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
-- Movies that do not have ratings should not be included in the result.

SELECT movies.title, ratings.rating FROM movies INNER JOIN ratings ON movies.id=ratings.movie_id WHERE year = 2010 ORDER BY rating DESC, title ASC






--        -- SELECT r.last_name,

--        (SELECT MAX(YEAR(championship_date))
--           FROM champions AS c
--          WHERE c.last_name = r.last_name
--            AND c.confirmed = 'Y') AS last_championship_year
--   FROM riders AS r
--  WHERE r.last_name IN
--        (SELECT c.last_name
--           FROM champions AS c
--          WHERE YEAR(championship_date) > '2008'
--            AND c.confirmed = 'Y');