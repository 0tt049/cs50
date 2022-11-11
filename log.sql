-- Keep a log of any SQL queries you execute as you solve the mystery.
-- All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.
--
--  Query 01
--  Crime scene report at July 28, 2021. Humphrey Street
/*    SELECT id,
description
FROM crime_scene_reports
WHERE YEAR = 2021       AND
MONTH = 7       AND
DAY = 28       AND
street = "Humphrey Street"; */
-- 295 | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
--
--  Query 02
--  Crime scene report from July 28, 2021, that mentions "bakery"
/*    SELECT id,
name,
transcript
FROM interviews
WHERE YEAR = 2021       AND
MONTH = 7       AND
DAY = 28       AND
transcript LIKE "%bakery%"; */
--  161 | Ruth    | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
--  162 | Eugene  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
--  163 | Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
--
--  Query 03
--  Bakery security log from within ten minutes of the theft
/*    SELECT id,
HOUR,
MINUTE,
activity,
license_plate
FROM bakery_security_logs
WHERE YEAR = 2021       AND
MONTH = 7       AND
DAY = 28       AND
HOUR = 10       AND
MINUTE >= 5       AND
MINUTE <= 25       AND
activity = "exit"; */
-- +-----+------+--------+----------+---------------+
-- | id  | hour | minute | activity | license_plate |
-- +-----+------+--------+----------+---------------+
-- | 260 | 10   | 16     | exit     | 5P2BI95       |
-- | 261 | 10   | 18     | exit     | 94KL13X       |
-- | 262 | 10   | 18     | exit     | 6P58WS2       |
-- | 263 | 10   | 19     | exit     | 4328GD8       |
-- | 264 | 10   | 20     | exit     | G412CB7       |
-- | 265 | 10   | 21     | exit     | L93JTIZ       |
-- | 266 | 10   | 23     | exit     | 322W7JE       |
-- | 267 | 10   | 23     | exit     | 0NTHK55       |
-- +-----+------+--------+----------+---------------+
--
--  Query 04
--  ATM transactions from July 28, 2021 at Leggett Street
/*    SELECT id,
account_number,
amount
FROM atm_transactions
WHERE YEAR = 2021       AND
MONTH = 7       AND
DAY = 28       AND
atm_location = "Leggett Street"       AND
transaction_type = "withdraw"; */
-- +-----+----------------+--------+
-- | id  | account_number | amount |
-- +-----+----------------+--------+
-- | 246 | 28500762       | 48     |
-- | 264 | 28296815       | 20     |
-- | 266 | 76054385       | 60     |
-- | 267 | 49610011       | 50     |
-- | 269 | 16153065       | 80     |
-- | 288 | 25506511       | 20     |
-- | 313 | 81061156       | 30     |
-- | 336 | 26013199       | 35     |
-- +-----+----------------+--------+
--
--  Query 05
--  Phone calls by the thief to an accomplice at the time theft that lasted less than a minute.
/*    SELECT id,
caller,
receiver
FROM phone_calls
WHERE YEAR = 2021       AND
MONTH = 7       AND
DAY = 28       AND
duration <= 60; */
-- +-----+----------------+----------------+
-- | id  |     caller     |    receiver    |
-- +-----+----------------+----------------+
-- | 221 | (130) 555-0289 | (996) 555-8899 |
-- | 224 | (499) 555-9472 | (892) 555-8872 |
-- | 233 | (367) 555-5533 | (375) 555-8161 |
-- | 234 | (609) 555-5876 | (389) 555-5198 |
-- | 251 | (499) 555-9472 | (717) 555-1342 |
-- | 254 | (286) 555-6063 | (676) 555-6554 |
-- | 255 | (770) 555-1861 | (725) 555-3243 |
-- | 261 | (031) 555-6622 | (910) 555-3251 |
-- | 279 | (826) 555-1652 | (066) 555-9701 |
-- | 281 | (338) 555-6650 | (704) 555-2131 |
-- +-----+----------------+----------------+
--
--  Query 06
--  Find first flight from the day after the flight
/*    SELECT id,
origin_airport_id,
destination_airport_id
FROM flights
WHERE YEAR = 2021       AND
MONTH = 7       AND
DAY = 29
ORDER BY HOUR,
MINUTE
LIMIT 1; */
-- +----+-------------------+------------------------+
-- | id | origin_airport_id | destination_airport_id |
-- +----+-------------------+------------------------+
-- | 36 | 8                 | 4                      |
-- +----+-------------------+------------------------+
--
--  Query 07
--  Airport from wich thief left to wich thief went to.
/*    SELECT *
FROM airports
WHERE id = 8        OR
id = 4; */
-- +----+--------------+-----------------------------+---------------+
-- | id | abbreviation |          full_name          |     city      |
-- +----+--------------+-----------------------------+---------------+
-- | 4  | LGA          | LaGuardia Airport           | New York City |
-- | 8  | CSF          | Fiftyville Regional Airport | Fiftyville    |
-- +----+--------------+-----------------------------+---------------+
--
--  Query 08
--  Passager list from first flight the day after the theft
/*    SELECT *
FROM passengers
WHERE flight_id = 36; */
-- +-----------+-----------------+------+
-- | flight_id | passport_number | seat |
-- +-----------+-----------------+------+
-- | 36        | 7214083635      | 2A   |
-- | 36        | 1695452385      | 3B   |
-- | 36        | 5773159633      | 4A   |
-- | 36        | 1540955065      | 5C   |
-- | 36        | 8294398571      | 6C   |
-- | 36        | 1988161715      | 6D   |
-- | 36        | 9878712108      | 7A   |
-- | 36        | 8496433585      | 7B   |
-- +-----------+-----------------+------+
--
--  Query 09
--  People info from passengers in first flight the day after the theft
/*    SELECT *
FROM people
WHERE passport_number IN (
SELECT passport_number
FROM passengers
WHERE flight_id = 36
); */
-- +--------+--------+----------------+-----------------+---------------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate |
-- +--------+--------+----------------+-----------------+---------------+
-- | 395717 | Kenny  | (826) 555-1652 | 9878712108      | 30G67EN       |
-- | 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       |
-- | 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
-- | 467400 | Luca   | (389) 555-5198 | 8496433585      | 4328GD8       |
-- | 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
-- | 651714 | Edward | (328) 555-1152 | 1540955065      | 130LD9Z       |
-- | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
-- | 953679 | Doris  | (066) 555-9701 | 7214083635      | M51FA04       |
-- +--------+--------+----------------+-----------------+---------------+
--
--  Query 10
--  Cross reference license_plate from passengers with those from bakery security log
   CREATE VIEW filtered_plate_bakery AS
   SELECT license_plate
     FROM bakery_security_logs
    WHERE YEAR = 2021       AND
          MONTH = 7       AND
          DAY = 28       AND
          HOUR = 10       AND
          MINUTE >= 5       AND
          MINUTE <= 25       AND
          activity = "exit";

   CREATE VIEW filtered_plate_flight AS
   SELECT license_plate
     FROM people
    WHERE passport_number IN (
             SELECT passport_number
               FROM passengers
              WHERE flight_id = 36
          );

   CREATE VIEW crossed_plate AS
   SELECT *
     FROM filtered_plate_bakery
  NATURAL JOIN filtered_plate_flight;

-- +---------------+
-- | license_plate |
-- +---------------+
-- | 94KL13X       |
-- | 4328GD8       |
-- | G412CB7       |
-- | 0NTHK55       |
-- +---------------+
--
--  Query 11
--  Cross reference phone from passengers with those from phone calls
   CREATE VIEW filtered_phone_flight AS
   SELECT phone_number
     FROM people
    WHERE passport_number IN (
             SELECT passport_number
               FROM passengers
              WHERE flight_id = 36
          );

   CREATE VIEW filtered_phone_calls AS
   SELECT caller AS phone_number
     FROM phone_calls
    WHERE YEAR = 2021       AND
          MONTH = 7       AND
          DAY = 28       AND
          duration <= 60;

   CREATE VIEW crossed_phone AS
   SELECT *
     FROM filtered_phone_flight
  NATURAL JOIN filtered_phone_calls;

-- +----------------+
-- |  phone_number  |
-- +----------------+
-- | (130) 555-0289 |
-- | (499) 555-9472 |
-- | (367) 555-5533 |
-- | (499) 555-9472 |
-- | (286) 555-6063 |
-- | (826) 555-1652 |
-- +----------------+
--
--  Query 12
--  Cross reference phone and license_plate from people table
   CREATE VIEW crossed_people_phone_plate AS
   SELECT *
     FROM people
    WHERE phone_number IN crossed_phone       AND
          license_plate IN crossed_plate;

-- +--------+--------+----------------+-----------------+---------------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate |
-- +--------+--------+----------------+-----------------+---------------+
-- | 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       |
-- | 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
-- | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
-- +--------+--------+----------------+-----------------+---------------+
--
--  Query 13
--  Cross reference account number with people id
   CREATE VIEW name_people_from_account AS
   SELECT name
     FROM people
    WHERE id IN (
             SELECT person_id
               FROM bank_accounts
              WHERE account_number IN (
                       SELECT account_number
                         FROM atm_transactions
                        WHERE YEAR = 2021       AND
                              MONTH = 7       AND
                              DAY = 28       AND
                              atm_location = "Leggett Street"       AND
                              transaction_type = "withdraw"
                    )
          );

-- +---------+
-- |  name   |
-- +---------+
-- | Kenny   |
-- | Iman    |
-- | Benista |
-- | Taylor  |
-- | Brooke  |
-- | Luca    |
-- | Diana   |
-- | Bruce   |
-- +---------+
--
--  Query 14
--  Check Bruce's accomplice from phone call
   SELECT name
     FROM people
    WHERE phone_number = "(375) 555-8161";

     DROP view crossed_plate;

     DROP view crossed_phone;

     DROP view filtered_plate_bakery;

     DROP view filtered_plate_flight;

     DROP view filtered_phone_flight;

     DROP view filtered_phone_calls;

     DROP view crossed_people_phone_plate;

     DROP view name_people_from_account;