##1 Prints all titles (minus header)
# import csv

# with open("favorites.csv", 'r') as file:
#     reader = csv.reader(file)
#     next(reader)
#     for row in reader:
#         print(row[1])


##2 Prints only user [title]
# import csv

# titles = []

# with open("favorites.csv", 'r') as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         print(row["title"])

##3 Only prints if title is not already there
# import csv

# titles = []

# with open("favorites.csv", 'r') as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         if not row["title"] in titles:
#             titles.append(row["title"])

#     for title in titles:
#         print(title)


##4 appends variable title to [titles]. title uses .upper() and .strip() on row["title"]
# import csv

# titles = []

# with open("favorites.csv", 'r') as file:
#     reader = csv.DictReader(file)

#     for row in reader:
#         title = row["title"].upper().strip()
#         if not row["title"] in titles:
#             titles.append(title)

#     for title in titles:
#         print(title)


##5 data structure: set() ensures all values are unique
# import csv

# titles = set()

# with open("favorites.csv", 'r') as file:
#     reader = csv.DictReader(file)

#     for row in reader:
#         title = row["title"].upper().strip()
#         titles.add(title)

# for title in titles:
#     print(title)


##6 Add sorted(titles) will sort the set before iterating over it
# import csv

# titles = set()

# with open("favorites.csv", 'r') as file:
#     reader = csv.DictReader(file)

#     for row in reader:
#         title = row["title"].upper().strip()
#         titles.add(title)

# for title in sorted(titles):
#     print(title)


##7 Back to dictionary {} not set(): keys = titles; values = int count
# import csv

# titles = {}

# with open("favorites.csv", 'r') as file:
#     reader = csv.DictReader(file)

#     for row in reader:
#         title = row["title"].upper().strip()
#         titles[title] += 1

# for title in sorted(titles):
#     print(title)
    # KeyError: 'HOW I MET YOUR MOTHER' - Must add each title to dict first and set initial value to 1


##8 Counting
# import csv

# titles = {}

# with open("favorites.csv", 'r') as file:
#     reader = csv.DictReader(file)

#     for row in reader:
#         title = row["title"].upper().strip()
#         if title in titles:
#             titles[title] += 1
#         else:
#             titles[title] = 1

# for title in sorted(titles):
#     print(title, titles[title])


##9 Add counts as values, set initial value to 0 and inc by 1
# import csv

# titles = {}

# with open("favorites.csv", 'r') as file:
#     reader = csv.DictReader(file)

#     for row in reader:
#         title = row["title"].upper().strip()
#         if not title in titles:
#             titles[title] = 0
#         else:
#             titles[title] += 1

    ##9.1 This produces the key in the dictionary where can refer to its values

# for title in sorted(titles):
#     print(title, titles[title])

    ##9.2 Comment out above, [def get_value], below for loop will sort by values

# def get_value(title):
#     return titles[title]

# for title in sorted(titles, key=get_value, reverse=True):
#     print(title, titles[title])

    ##9.3 Comment out above, below is same as [def get_value] in the same line - see syntax

# for title in sorted(titles, key=lambda title: titles[title], reverse=True):
#     print(title, titles[title])

        # print(row.keys)[1]
    #     title = row["title"].strip().upper()
    #     if not title in titles:
    #         titles[title] = 1
    #     else:
    #         titles[title] += 1
    #         titles.add(title) # set()
    #         if not row["title"] in titles: # titles[]
    #             titles.append(title)
    # print(titles)


##10 Count all occurrances of a specific title
# import csv

# counter = 0

# with open("favorites.csv", 'r') as file:
#     reader = csv.DictReader(file)

#     for row in reader:
#         title = row["title"].upper().strip()
#         if title == "THE OFFICE":
#             counter += 1

# print(f"Number of people who like The Office: {counter}")


##11 Can now check if the word "OFFICE" was in the title
# import csv

# counter = 0

# with open("favorites.csv", 'r') as file:
#     reader = csv.DictReader(file)

#     for row in reader:
#         title = row["title"].upper().strip()
#         if "OFFICE" in title:
#             counter += 1

# print(f"Number of people who like The Office: {counter}")



##12 REGULAR EXPRESSIONS

# .*@.*\..*                                   .+@.+\..+

# . any character                             . any character
# * 0 or more times                           + 1 or more times
# @ just at sign                              @ just at sign
# .* 0 or more characters again               .+ 1 or more characters again
# \. (\)escapes string and writes "."         \. (\)escapes string and writes "."
# .* 0 or more characters again               .+ 1 or more characters again

# ? optional character
# ^ start of input
# $ end of input


##13 Implement re library for regular expressions
# import csv
# import re

# counter = 0

# with open("favorites.csv", 'r') as file:
#     reader = csv.DictReader(file)

#     for row in reader:
#         title = row["title"].upper().strip()
#         if re.search("OFFICE", title):
#             counter += 1
#         #13.1 "^(OFFICE|THE OFFICE)$" - matches either/or but only if those exact strings
#         #13.2 THE.OFFICE allows for any typos between the words

# print(f"Number of people who like The Office: {counter}")


##14 Ask user for a particular title and report its popularity
# import csv

# title = input("Title: ").strip().upper()

# counter = 0

# with open("favorites.csv", 'r') as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         if row["title"].strip().upper() == title:
#             counter += 1

# print(counter)


# ##15 SQL
#     sqlite3 favorites.db - run the sqlite3 program with favorites.db as the name of the file for our database
#     .import - SQLite creates a table in our database with the data from our CSV file.

        $ sqlite3 favorites.db
        SQLite version 3.36.0 2021-06-18 18:36:39
        Enter ".help" for usage hints.
        sqlite> .mode csv
        sqlite> .import favorites.csv favorites

    ##15.1
        open database again and check the schema, or design with .schema

        $ sqlite3 favorites.db
        SQLite version 3.36.0 2021-06-18 18:36:39
        Enter ".help" for usage hints.
        sqlite> .schema
        CREATE TABLE IF NOT EXISTS "favorites"(
        "Timestamp" TEXT,
        "title" TEXT,
        "genres" TEXT
        );

    ##15.2 We can select, or read data, with:
        sqlite> SELECT title FROM favorites;
          aka - SELECT column FROM table;
        +------------------------------------+
        |                title               |
        +------------------------------------+
        | How i met your mother              |
        | The Sopranos                       |
        | Friday Night Lights                |
        ...

        We can then read data from columns:
            SELECT title, genre FROM favorites

    ##15.3 Clean up titles to uppercase and only unique values as before with:
        sqlite> SELECT DISTINCT(UPPER(title)) FROM shows;

        ...
        | LAW AND ORDER                      |
        | B99                                |
        | GOT                                |
        ...

    ##15.4 Get a count
        sqlite> SELECT COUNT(title) FROM favorites;

        +--------------+
        | COUNT(title) |
        +--------------+
        | 158          |
        +--------------+

    ##15.5 Other phrase examples:
        WHERE    - adding a Boolean expression to filter our data
        LIKE     - filtering responses more loosely
        ORDER BY
        LIMIT
        GROUP BY

    ##15.6 Limit number of results
        sqlite> SELECT title FROM favorites LIMIT 10;

        +-----------------------+
        |         title         |
        +-----------------------+
        | How i met your mother |
        | The Sopranos          |
        | Friday Night Lights   |
        | Family Guy            |
        | New Girl              |
        | Friends               |
        | Office                |
        | Breaking Bad          |
        | Modern Family         |
        | Office                |
        +-----------------------+

    ##15.7 Look for titles matching a string:
        sqlite> SELECT title FROM favorites WHERE title LIKE "%office%";

        +-------------+
        |    title    |
        +-------------+
        | Office      |
        | Office      |
        | The Office  |
        | The Office  |
        | The Office  |
        | The Office  |
        | The Office  |
        | The Office  |
        | The Office  |
        | The Office  |
        | The Office  |
        | the office  |
        | The Office  |
        | ThE OffiCE  |
        | The Office  |
        | Thevoffice  |
        +-------------+

    ##15.8 The % character is a placeholder for zero or more other characters (like .* in regular expressions)
        Here we can select just the count in our command:
        sqlite> SELECT COUNT(title) FROM favorites WHERE title LIKE "%office%";

        +--------------+
        | COUNT(title) |
        +--------------+
        | 16           |
        +--------------+

    ##15.9 If we don't like a show we can delete it
        sqlite> SELECT COUNT(title) FROM favorites WHERE title LIKE "%friends%";

        +--------------+
        | COUNT(title) |
        +--------------+
        | 9            |
        +--------------+

        sqlite> DELETE FROM favorites WHERE title LIKE "%friends%";
        sqlite> SELECT COUNT(title) FROM favorites WHERE title LIKE "%friends%";

        +--------------+
        | COUNT(title) |
        +--------------+
        | 0            |
        +--------------+

    ##15.10 Can update a specific row of data by changing its value (from "Thevoffice" to "The Office")
        sqlite> SELECT title FROM favorites WHERE title = "Thevoffice";

        +------------+
        |   title    |
        +------------+
        | Thevoffice |
        +------------+
        sqlite> UPDATE favorites SET title = "The Office" WHERE title = "Thevoffice";
        sqlite> SELECT title FROM favorites WHERE title = "Thevoffice";

    ##15.11 Can change the values in multiple rows
        sqlite> SELECT genres FROM favorites WHERE title = "Game of Thrones";

        +--------------------------------------------------------------------------------------------------------------+
        |                                                    genres                                                    |
        +--------------------------------------------------------------------------------------------------------------+
        | Action, Adventure, Drama, Fantasy, Thriller, War                                                             |
        | Action, Adventure, Drama                                                                                     |
        | Action, Adventure, Comedy, Drama, Family, Fantasy, History, Horror, Musical, Mystery, Romance, Thriller, War |
        | Action, Drama, Family, Fantasy, War                                                                          |
        | Fantasy, Thriller, War                                                                                       |
        +--------------------------------------------------------------------------------------------------------------+

        sqlite> UPDATE favorites SET genres = "Action, Adventure, Drama, Fantasy, Thriller, War" WHERE title = "Game of Thrones";
        sqlite> SELECT genres FROM favorites WHERE title = "Game of Thrones";

        +--------------------------------------------------+
        |                      genres                      |
        +--------------------------------------------------+
        | Action, Adventure, Drama, Fantasy, Thriller, War |
        | Action, Adventure, Drama, Fantasy, Thriller, War |
        | Action, Adventure, Drama, Fantasy, Thriller, War |
        | Action, Adventure, Drama, Fantasy, Thriller, War |
        | Action, Adventure, Drama, Fantasy, Thriller, War |
        +--------------------------------------------------+

    #15.12 DELETE and DROP removes rows and even entire tables

##16 TABLES

sqlite> .schema
CREATE TABLE IF NOT EXISTS "favorites"(
  "Timestamp" TEXT,
  "title" TEXT,
  "genres" TEXT
);

    ##16.1 Can see redundancy in in the values of genres
        sqlite> SELECT genres FROM favorites;

        +-----------------------------------------------------------+
        |                          genres                           |
        +-----------------------------------------------------------+
        | Comedy                                                    |
        | Comedy, Crime, Drama, Horror, Sci-Fi, Talk-Show, Thriller |
        | Drama, Family, Sport                                      |
        | Animation, Comedy                                         |
        | Comedy, Drama                                             |
        ...

        SELECT title FROM favorites WHERE genre = "Comedy";
                                ... WHERE genre = "Comedy, Drama";
                                ... WHERE genre = "Comedy, News";
                                ... etc.

    ##16.2 Can write Python program that uses SQL to import CSV data into TWO TABLES:

        # Imports titles and genres from CSV into a SQLite database
        import cs50
        import csv

        # Create database
        open("favorites8.db", "w").close()
        db = cs50.SQL("sqlite:///favorites8.db")

        # Create tables
        db.execute("CREATE TABLE shows (id INTEGER, title TEXT NOT NULL, PRIMARY KEY(id))")
        db.execute("CREATE TABLE genres (show_id INTEGER, genre TEXT NOT NULL, FOREIGN KEY(show_id) REFERENCES shows(id))")

        # Open CSV file
        with open("favorites.csv", "r") as file:

            # Create DictReader
            reader = csv.DictReader(file)

            # Iterate over CSV file
            for row in reader:

                # Canoncalize title
                title = row["title"].strip().upper()

                # Insert title
                show_id = db.execute("INSERT INTO shows (title) VALUES(?)", title)

                # Insert genres
                for genre in row["genres"].split(", "):

                    db.execute("INSERT INTO genres (show_id, genre) VALUES(?, ?)", show_id, genre)

    ##16.3 Database will have this design:
        $ sqlite3 favorites8.db
        SQLite version 3.36.0 2021-06-18 18:36:39
        Enter ".help" for usage hints.
        sqlite> .schema
            # create shows table: (id column, title column, key=id)
        CREATE TABLE shows (id INTEGER, title TEXT NOT NULL, PRIMARY KEY(id));
            # create genres table: (show_id column references the shows table, along with genre column)
        CREATE TABLE genres (show_id INTEGER, genre TEXT NOT NULL, FOREIGN KEY(show_id) REFERENCES shows(id))

        RELATION - like a link between rows in different tables in the database

    ##16.4 ONE-TO-MANY relationship: if shows have more than one genre
        sqlite> SELECT * FROM shows;
        +-----+------------------------------------+
        | id  |               title                |
        +-----+------------------------------------+
        | 1   | HOW I MET YOUR MOTHER              |
        | 2   | THE SOPRANOS                       |
        | 3   | FRIDAY NIGHT LIGHTS                |
        | 4   | FAMILY GUY                         |
        | 5   | NEW GIRL                           |
        | 6   | FRIENDS                            |
        | 7   | OFFICE                             |
        ...

        sqlite> SELECT * FROM genres;
        +---------+-------------+
        | show_id |    genre    |
        +---------+-------------+
        | 1       | Comedy      |
        | 2       | Comedy      |
        | 2       | Crime       |
        | 2       | Drama       |
        | 2       | Horror      |
        | 2       | Sci-Fi      |
        | 2       | Talk-Show   |
        | 2       | Thriller    |
        | 3       | Drama       |
        | 3       | Family      |
        | 3       | Sport       |
        | 4       | Animation   |
        | 4       | Comedy      |
        | 5       | Comedy      |
        | 6       | Comedy      |
        | 7       | Comedy      |
        ...

    ##16.5 Select all comedy shows by selecting from genres table first, then look for those id's in the shows table:
        sqlite> SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = "Comedy");

            NESTED QUERIES:
            (INNER) - returns list of show id's
            (OUTER) - uses those id's to select the titles of shows that match

        +------------------------------------+
        |               title                |
        +------------------------------------+
        | HOW I MET YOUR MOTHER              |
        | THE SOPRANOS                       |
        | FAMILY GUY                         |
        | NEW GIRL                           |
        | FRIENDS                            |
        | OFFICE                             |
        | MODERN FAMILY                      |
        ...

    ##16.6 Can sort and show unique titles by adding to the command
        sqlite> SELECT DISTINCT(title) FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = "Comedy") ORDER BY title;

        +------------------------------------+
        |               title                |
        +------------------------------------+
        | ARCHER                             |
        | ARRESTED DEVELOPMENT               |
        | AVATAR THE LAST AIRBENDER          |
        | B99                                |
        | BILLIONS                           |
        | BLACK MIRROR                       |
        ...

    ##16.7 Can add new data to each table (ADD NEW SHOW)
        sqlite> INSERT INTO shows (title) VALUES("Seinfeld");

            #Then look for its row id in table
        sqlite> SELECT * FROM shows WHERE title = "Seinfeld";

        +-----+----------+
        | id  |  title   |
        +-----+----------+
        | 159 | Seinfeld |
        +-----+----------+

            #use show_id to add a new row in the genres table
        sqlite> INSERT INTO genres (show_id, genre) VALUES(159, "Comedy");

            # UPDATE to set the title to uppercase
        sqlite> UPDATE shows SET title = "SEINFELD" WHERE title = "Seinfeld";

            #run same command as before - should see new show is added to comedies
        sqlite> SELECT DISTINCT(title) FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = "Comedy") ORDER BY title;

        ...
        | SEINFELD                       |
        ...

    #