-- In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
-- Your query should output a table with a single column for the name of each person.
-- There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
-- Kevin Bacon himself should not be included in the resulting list.

-- SELECT name from people WHERE people.id IN (SELECT stars.person_id FROM stars WHERE stars.movie_id IN (SELECT movies.id FROM movies WHERE name = "Kevin Bacon"))

-- SELECT name from people WHERE people.id IN
-- (SELECT stars.person_id FROM stars
-- WHERE stars.movie_id IN (SELECT movies.id FROM movies
-- WHERE title = "One Way"))
SELECT name FROM people
WHERE people.id IN (SELECT DISTINCT stars.person_id FROM stars
WHERE stars.movie_id IN (SELECT movie_id FROM stars
WHERE stars.person_id IN (SELECT people.id FROM people
WHERE name = "Kevin Bacon" AND birth = 1958))
EXCEPT SELECT people.id FROM people WHERE name = "Kevin Bacon")