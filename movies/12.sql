-- In 12.sql, write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Johnny Depp.
-- You may assume that there is only one person in the database with the name Helena Bonham Carter.

-- SELECT title FROM movies
-- WHERE movies.id IN (SELECT stars.movie_id FROM stars
-- WHERE stars.person_id IN
-- (SELECT people.id FROM people
-- WHERE name = "Johnny Depp")) AND
-- (SELECT title FROM movies
-- WHERE movies.id IN
-- (SELECT stars.movie_id FROM stars
-- WHERE stars.person_id IN (SELECT people.id FROM people
-- WHERE name = "Helena Bonham Carter")))

SELECT title FROM movies
WHERE movies.id IN (SELECT stars.movie_id FROM stars
WHERE stars.person_id IN (SELECT people.id FROM people
WHERE name = "Johnny Depp")) AND title IN
(SELECT title FROM movies
WHERE movies.id IN (SELECT stars.movie_id FROM stars
WHERE stars.person_id IN (SELECT people.id FROM people
WHERE name ="Helena Bonham Carter")))


-- SELECT movies.title FROM people
-- JOIN movies ON movies.id=stars.movie_id
-- JOIN stars ON stars.person_id=people.id
-- WHERE name = "Johnny Depp" AND movies.title IN (
-- SELECT movies.title FROM people
-- JOIN stars ON stars.person_id=people.id
-- JOIN movies ON movies.id=stars.movie_id
-- WHERE name = "Helena Bonham Carter")



-- SELECT movies.title FROM people
-- JOIN stars ON people.id = stars.person_id
-- JOIN movies ON stars.movie_id = movies.id
-- WHERE people.name = "Johnny Depp" AND movies.title IN(
-- SELECT movies.title FROM people
-- JOIN stars ON people.id = stars.person_id
-- JOIN movies ON stars.movie_id = movies.id
-- WHERE people.name = "Helena Bonham Carter");