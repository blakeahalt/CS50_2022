-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM "crime_scene_reports" WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";
-- No record of "Chamberlin Street"
SELECT description FROM "crime_scene_reports" WHERE month = 7 AND day = 28;
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
-------------------------------------------------------------------------------------------+
-- | Vandalism took place at 12:04. No known witnesses.
-- | Shoplifting took place at 03:01. Two people witnessed the event.
-- | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
-- | Money laundering took place at 20:30. No known witnesses.
-- | Littering took place at 16:36. No known witnesses.
-- +-------------------------------------------------------------------------------------------------------

SELECT name, month, day, transcript FROM "interviews" WHERE month = 7 AND day = 28 AND transcript LIKE "%bakery%";
-- Gather the 3 interviews from that day

-- |  name   | month | day |
-- | Ruth    | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- | Eugene  | 7     | 28  | I dont know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- | Raymond | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

SELECT  people.name, bakery_security_logs.license_plate, people.license_plate, people.passport_number, people.phone_number FROM "bakery_security_logs" JOIN "people" ON people.license_plate=bakery_security_logs.license_plate WHERE month = 7 AND day = 28 AND hour = 10 AND activity = "exit" ORDER BY hour ASC;
-- Who left the bakery after 10
+---------+---------------+---------------+-----------------+----------------+
|  name   | license_plate | license_plate | passport_number |  phone_number  |
+---------+---------------+---------------+-----------------+----------------+
| Vanessa | 5P2BI95       | 5P2BI95       | 2963008352      | (725) 555-4692 |
| Bruce   | 94KL13X       | 94KL13X       | 5773159633      | (367) 555-5533 |
| Barry   | 6P58WS2       | 6P58WS2       | 7526138472      | (301) 555-4174 |
| Luca    | 4328GD8       | 4328GD8       | 8496433585      | (389) 555-5198 |
| Sofia   | G412CB7       | G412CB7       | 1695452385      | (130) 555-0289 |
| Iman    | L93JTIZ       | L93JTIZ       | 7049073643      | (829) 555-5269 |
| Diana   | 322W7JE       | 322W7JE       | 3592750733      | (770) 555-1861 |
| Kelsey  | 0NTHK55       | 0NTHK55       | 8294398571      | (499) 555-9472 |
| Taylor  | 1106N58       | 1106N58       | 1988161715      | (286) 555-6063 |
+---------+---------------+---------------+-----------------+----------------+

SELECT * FROM "atm_transactions" WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street";
-- Who used ATM transactions that morning
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+

SELECT bank_accounts.account_number, person_id, atm_transactions.day, atm_transactions.amount, atm_transactions.transaction_type FROM "bank_accounts" JOIN "atm_transactions" ON atm_transactions.account_number=bank_accounts.account_number WHERE atm_transactions.account_number = 28500762 OR atm_transactions.account_number = 28296815 OR atm_transactions.account_number = 76054385 OR atm_transactions.account_number = 49610011 OR atm_transactions.account_number = 16153065 OR atm_transactions.account_number = 25506511 OR atm_transactions.account_number = 81061156 OR atm_transactions.account_number = 26013199 AND day = 28 ORDER BY day ASC;
-- ID of people who used ATM
-- +----------------+-----------+-----+--------+------------------+
-- | account_number | person_id | day | amount | transaction_type |
-- +----------------+-----------+-----+--------+------------------+
-- | 28500762       | 467400    | 28  | 48     | withdraw         |
-- | 28296815       | 395717    | 28  | 20     | withdraw         |
-- | 76054385       | 449774    | 28  | 60     | withdraw         |
-- | 49610011       | 686048    | 28  | 50     | withdraw         |
-- | 16153065       | 458378    | 28  | 80     | withdraw         |
-- | 25506511       | 396669    | 28  | 20     | withdraw         |
-- | 81061156       | 438727    | 28  | 30     | withdraw         |
-- | 26013199       | 514354    | 28  | 35     | withdraw         |
-- +----------------+-----------+-----+--------+------------------+

SELECT name, people.id, people.phone_number, day, phone_calls.receiver, phone_calls.caller, people.license_plate FROM "people" JOIN "phone_calls" ON phone_calls.caller=people.phone_number WHERE people.id = 467400 OR people.id = 395717 OR people.id = 449774 OR people.id = 686048 OR people.id = 458378 OR people.id = 396669 OR people.id = 438727 OR people.id = 514354 AND phone_calls.day = 28 ORDER BY day ASC;
-- Names of people who withdrew from ATM on the 28th
+--------+---------+----------------+-----+----------------+----------------+---------------+
|   id   |  name   |  phone_number  | day |    receiver    |     caller     | license_plate |
+--------+---------+----------------+-----+----------------+----------------+---------------+
| 395717 | Kenny   | (826) 555-1652 | 28  | (066) 555-9701 | (826) 555-1652 | 30G67EN       |
| 449774 | Taylor  | (286) 555-6063 | 28  | (310) 555-8568 | (286) 555-6063 | 1106N58       |
| 686048 | Bruce   | (367) 555-5533 | 28  | (704) 555-5790 | (367) 555-5533 | 94KL13X       |
| 458378 | Brooke  | (122) 555-4581 | 28  | (831) 555-0973 | (122) 555-4581 | QX4YZN3       |
| 438727 | Benista | (338) 555-6650 | 28  | (704) 555-2131 | (338) 555-6650 | 8X428L0       |
| 514354 | Diana   | (770) 555-1861 | 28  | (725) 555-3243 | (770) 555-1861 | 322W7JE       |

SELECT phone_calls.caller, phone_calls.receiver, people.phone_number, people.name, day, duration FROM "phone_calls" JOIN "people" ON phone_calls.receiver=people.phone_number WHERE caller = "(826) 555-1652" OR caller = "(338) 555-6650" OR caller = "(286) 555-6063" OR caller = "(122) 555-4581" OR caller = "(770) 555-1861" OR caller = "(367) 555-5533" ORDER BY duration ASC;
-- Names of people called that lasted under a minute
       +----------------+----------------+----------------+----------+-----+----------+
Name   |     caller     |    receiver    |  phone_number  |   name   | day | duration |
       +----------------+----------------+----------------+----------+-----+----------+
Taylor | (286) 555-6063 | (676) 555-6554 | (676) 555-6554 | James    | 28  | 43       |
Bruce  | (367) 555-5533 | (375) 555-8161 | (375) 555-8161 | Robin    | 28  | 45       |
Diana  | (770) 555-1861 | (725) 555-3243 | (725) 555-3243 | Philip   | 28  | 49       |
Benista| (338) 555-6650 | (704) 555-2131 | (704) 555-2131 | Anna     | 28  | 54       |
Kenny  | (826) 555-1652 | (066) 555-9701 | (066) 555-9701 | Doris    | 28  | 55       |


SELECT * FROM "airports" WHERE city = "Fiftyville";
-- Fiftyville Airport ID = 8; Abbreviation = CSF
-- +----+--------------+-----------------------------+------------+
-- | id | abbreviation |          full_name          |    city    |
-- +----+--------------+-----------------------------+------------+
-- | 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
-- +----+--------------+-----------------------------+------------+

SELECT * FROM "flights" WHERE month = 7 AND day = 29 AND origin_airport_id = 8;
-- The earliest flight leaving the 29th is 8:20 flying to 4()
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
-- | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+

SELECT * FROM "airports" WHERE airports.id = 4
-- The thief is flying to Laguardia Airport in NYC
-- The earliest flight leaving the 29th is 8:20 flying to 4()
-- +----+--------------+-------------------+---------------+
-- | id | abbreviation |     full_name     |     city      |
-- +----+--------------+-------------------+---------------+
-- | 4  | LGA          | LaGuardia Airport | New York City |
-- +----+--------------+-------------------+---------------+

SELECT * FROM flights WHERE destination_airport_id = 4 AND month = 7 AND day = 29 ORDER BY hour ASC;
-- Flight ID going to NYC
+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
+----+-------------------+------------------------+------+-------+-----+------+--------+

SELECT * FROM "passengers" WHERE flight_id = 36;
-- Passengers on flight 36
+-----------+-----------------+------+
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 36        | 7214083635      | 2A   |
| 36        | 1695452385      | 3B   |
| 36        | 5773159633      | 4A   |
| 36        | 1540955065      | 5C   |
| 36        | 8294398571      | 6C   |
| 36        | 1988161715      | 6D   |
| 36        | 9878712108      | 7A   |
| 36        | 8496433585      | 7B   |
+-----------+-----------------+------+

SELECT DISTINCT name, phone_number, people.passport_number, license_plate FROM "people" JOIN "passengers" ON people.passport_number=passengers.passport_number WHERE flight_id = 36 ORDER BY people.passport_number ASC;
-- ID of passengers
+--------+----------------+-----------------+---------------+
|  name  |  phone_number  | passport_number | license_plate |
+--------+----------------+-----------------+---------------+
| Edward | (328) 555-1152 | 1540955065      | 130LD9Z       |
| Sofia  | (130) 555-0289 | 1695452385      | G412CB7       |
| Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
| Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
| Doris  | (066) 555-9701 | 7214083635      | M51FA04       |
| Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
| Luca   | (389) 555-5198 | 8496433585      | 4328GD8       |
| Kenny  | (826) 555-1652 | 9878712108      | 30G67EN       |
+--------+----------------+-----------------+---------------+

SELECT phone_calls.receiver, phone_calls.caller, day, duration FROM "phone_calls" WHERE phone_calls.caller = "(367) 555-0409" OR phone_calls.caller = "(789) 555-8833" OR phone_calls.caller = "(059) 555-4698" OR phone_calls.caller = "(022) 555-4052" OR phone_calls.caller = "(194) 555-5027" OR phone_calls.caller = "(219) 555-0139" ORDER BY duration ASC;

+----------------+----------------+-----+----------+
|    receiver    |     caller     | day | duration |
+----------------+----------------+-----+----------+
| (892) 555-8872 | (499) 555-9472 | 28  | 36       |
| (910) 555-3251 | (031) 555-6622 | 28  | 38       |
| (676) 555-6554 | (286) 555-6063 | 28  | 43       |
| (375) 555-8161 | (367) 555-5533 | 28  | 45       |
| (725) 555-3243 | (770) 555-1861 | 28  | 49       |
| (717) 555-1342 | (499) 555-9472 | 28  | 50       |
| (996) 555-8899 | (130) 555-0289 | 28  | 51       |
| (704) 555-2131 | (338) 555-6650 | 28  | 54       |
| (066) 555-9701 | (826) 555-1652 | 28  | 55       |
| (022) 555-4052 | (770) 555-1196 | 25  | 60       |
| (389) 555-5198 | (609) 555-5876 | 28  | 60       |

SELECT * FROM people WHERE phone_number = "(960) 555-2044";
+--------+----------+----------------+-----------------+---------------+
|   id   |   name   |  phone_number  | passport_number | license_plate |
+--------+----------+----------------+-----------------+---------------+
| 548858 | Kathleen | (960) 555-2044 | 2628207874      | PF37ZVK       |
+--------+----------+----------------+-----------------+---------------+
-- Ernest calls Kathleen to purchase his ticket

SELECT * FROM "passengers" WHERE flight_id = 4 AND passport_number = 6216255522 ORDER BY passport_number ASC;
-- Confirming the passengers flying on the first flight out: Ernest is in seat 4B

-- +-----------+-----------------+------+
-- | flight_id | passport_number | seat |
-- +-----------+-----------------+------+
-- | 4         | 6216255522      | 4B   |
-- +-----------+-----------------+------+

SELECT phone_calls.caller, phone_calls.receiver, people.phone_number, people.name, day, duration FROM "phone_calls" JOIN "people" ON phone_calls.receiver=people.phone_number WHERE caller = "(826) 555-1652" OR caller = "(338) 555-6650" OR caller = "(286) 555-6063" OR caller = "(122) 555-4581" OR caller = "(770) 555-1861" OR caller = "(367) 555-5533" ORDER BY duration ASC;



SELECT  DISTINCT people.name, people.license_plate, passengers.passport_number, phone_calls.caller, phone_calls.receiver, amount, duration FROM "bakery_security_logs"
JOIN "people" ON people.license_plate=bakery_security_logs.license_plate
JOIN "passengers" ON passengers.passport_number=people.passport_number
JOIN "phone_calls" ON phone_calls.caller=people.phone_number
JOIN "bank_accounts" ON bank_accounts.person_id=people.id
JOIN "atm_transactions" ON atm_transactions.account_number=bank_accounts.account_number
WHERE bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute > 15
AND bakery_security_logs.minute < 25
AND phone_calls.day = 28
AND atm_transactions.day = 28
AND activity = "exit"
AND phone_calls.duration < 60
ORDER BY hour ASC;

+-------+---------------+-----------------+----------------+----------------+--------+----------+
| name  | license_plate | passport_number |     caller     |    receiver    | amount | duration |
+-------+---------------+-----------------+----------------+----------------+--------+----------+
| Bruce | 94KL13X       | 5773159633      | (367) 555-5533 | (375) 555-8161 | 50     | 45       |
| Diana | 322W7JE       | 3592750733      | (770) 555-1861 | (725) 555-3243 | 35     | 49       |
+-------+---------------+-----------------+----------------+----------------+--------+----------+