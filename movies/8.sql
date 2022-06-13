-- In 8.sql, write a SQL query to list the names of all people who starred in Toy Story.
-- Your query should output a table with a single column for the name of each person.
-- You may assume that there is only one movie in the database with the title Toy Story.

-- SELECT movies.title, stars.person_id FROM stars WHERE stars.person_id IN (SELECT movies.id FROM movies WHERE movies.id=stars.movie_id)


-- SELECT people.name FROM people WHERE id IN (SELECT movies.id FROM movies JOIN stars ON movies.id=stars.movie_id WHERE title = "Toy Story")

SELECT people.name FROM people WHERE id IN (SELECT stars.person_id FROM stars JOIN movies ON stars.movie_id=movies.id WHERE movies.title = "Toy Story")