-- In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Chadwick Boseman.

-- SELECT title FROM movies WHERE movies.id IN (SELECT ratings.movie_id FROM ratings JOIN people ON ratings.movie_id=movies.id WHERE name = "Chadwick Boseman" ORDER BY ratings.rating DESC) LIMIT 5

-- SELECT title FROM movies WHERE movies.id IN (SELECT stars.movie_id FROM stars JOIN ratings, people ON stars.person_id=people.id WHERE name = "Chadwick Boseman" ORDER BY rating DESC) LIMIT 5

--        Expected:            Actual:
--        42                   42
--        Black Panther        Get on Up
--        Marshall             Draft Day
--        Get on Up            Message from the King
--        Draft Day            Marshall


-- SELECT title FROM movies WHERE movies.id IN (SELECT stars.movie_id FROM stars JOIN ratings, people ON stars.person_id=ratings.movie_id WHERE name = "Chadwick Boseman" ORDER BY rating DESC)  LIMIT 5

--        Actual:
--        | Dama de noche              |
--        | El huésped del sevillano   |
--        | Nagarik                    |
--        | I Eat Your Skin            |
--        | Aventura en las islas Cíes |

-- SELECT movies.title FROM people
-- JOIN stars ON people.id = stars.person_id
-- JOIN movies ON stars.movie_id = movies.id
-- JOIN ratings on movies.id = ratings.movie_id
-- WHERE people.name = "Chadwick Boseman" ORDER BY rating DESC LIMIT 5

-- SELECT movies.title FROM people
-- JOIN stars, movies ON people.id = stars.person_id
-- JOIN movies ON stars.movie_id = movies.id
-- JOIN ratings ON movies.id = ratings.movie_id
-- WHERE people.name = "Chadwick Boseman" ORDER BY rating DESC LIMIT 5

-- SELECT movies.title from people
-- JOIN stars ON people.id = stars.person_id
-- JOIN movies ON stars.movie_id = movies.id
-- JOIN ratings on movies.id = ratings.movie_id
-- WHERE people.name = "Chadwick Boseman"
-- ORDER BY rating DESC
-- LIMIT 5;

SELECT movies.title FROM movies JOIN ratings ON movies.id=ratings.movie_id
WHERE ratings.movie_id IN
(SELECT stars.movie_id FROM stars WHERE stars.person_id =
(SELECT people.id FROM people
WHERE name = "Chadwick Boseman" )) ORDER BY rating DESC LIMIT 5

-- SELECT movies.title FROM movies JOIN ratings ON movies.id=ratings.movie_id
-- WHERE id IN
-- (SELECT movie_id FROM stars WHERE person_id =
-- (SELECT id FROM people WHERE name ="Chadwick Boseman")) ORDER BY ratings.rating DESC LIMIT 5