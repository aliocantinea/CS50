-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Copied schema layout to notes file to refer to
.schema
-- .tables to see what the output is as suggested
.tables
-- Started with crime_scene_reports as suggested
.schema crime_scene_reports
-- View year, month, day, street, description filtered by street, month and day to see how many results are populated
SELECT year, month, day, street, description
  FROM crime_scene_reports
 WHERE street LIKE "Humphrey Street" AND month = 7 AND day = 28;
-- First entry mentions Theft of CS50 duck
-- Interviews of 3 witnesses mentioning the bakery
-- Time was 10:15am
-- Refering to schema, interviews table has transcript
SELECT name, year, month, day, transcript FROM interviews WHERE transcript like "%bakery%";
-- Narrowed down output with refined date
SELECT name, year, month, day, transcript FROM interviews WHERE transcript like "%bakery%" AND day = 28;
-- Ruth mentions bakery_security_logs (sus that she knows that there are security cameras, like she scoped it out ahead of time...)
-- Eugene mentions seeing the theif at ATM on Leggett Street withdrawing before time of crime (interesting he is watching ATMs, might be a perp in the future, keep you eyes on this one...)
-- Raymond mentions heard short, less than a min, outbound call of thief taking earliest flight out of town, booked by accomplice (nothing suspect here, just an observant citizen!)

-- Look at Ruth's accounts
SELECT activity, hour, minute FROM bakery_security_logs WHERE day = 28;
-- Narrow down time and show license_plate
SELECT activity, license_plate, hour, minute FROM bakery_security_logs WHERE day = 28 AND hour <= 10;
-- Of the license_plate that left around the time of the crime, 5P2BI95 fits
SELECT activity, license_plate, hour, minute FROM bakery_security_logs WHERE day = 28 AND license_plate = "5P2BI95";
-- enter 9:15
-- exit 10:16
-- Could be someone else I guess, but bold that they(thief) would steal and then loiter

-- Look into Eugene's interview
-- ATM feels like a red herring since there is no foreign key to the data
-- (Bit strange since I work at a bank and know we keep record of bank cards doing transactions because with joint accounts that way we can track compromised cards to do with fraud)
-- (I do feel it was intended to have account_number be a foreign key in atm_transactions with bank_accounts(account_numbers) being the reference)
--(Also where are the transaction timestamps... this bank is sus too, probably launderying money!)
-- account numbers should be the same on both atm transactions and bank accounts
SELECT account_number, transaction_type FROM atm_transactions WHERE atm_location LIKE "Leggett Street";
-- not sure how transaction_type is recorded, now that I can see it is withdraw narrow down search
SELECT account_number FROM atm_transactions WHERE atm_location LIKE "Leggett Street" AND transaction_type = "withdraw" AND day = 28;
-- not many transactions on the 28th, might be a better way to narrow down people
SELECT name FROM people WHERE id IN
    (SELECT person_id FROM bank_accounts WHERE account_number IN
        (SELECT account_number FROM atm_transactions WHERE atm_location LIKE "Leggett Street" AND transaction_type = "withdraw" AND day = 28));
--+---------+
--|  name   |
--+---------+
--| Benista |
--| Brooke  |
--| Bruce   |
--| Diana   |
--| Iman    |
--| Kenny   |
--| Luca    |
--| Taylor  |
--+---------+

-- Look into Raymond's interview
SELECT caller, receiver, duration FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28;
-- sort by duration, which I guess has to be secs as there are none short enought to match less than a min if it was mins
SELECT caller, receiver, duration FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 ORDER BY duration;
-- only show those less than 60 secs
SELECT caller, receiver, duration FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 ORDER BY duration;
-- get names from people with phone numbers that made calls less than 1 min on the 28th
SELECT name FROM people WHERE phone_number IN
    (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 ORDER BY duration);
--+---------+
--|  name   |
--+---------+
--| Benista |
--| Bruce   |
--| Carina  |
--| Diana   |
--| Kelsey  |
--| Kenny   |
--| Sofia   |
--| Taylor  |
--+---------+

-- INTERSECT to show names that are the same over both previous queries
SELECT name FROM people WHERE id IN
    (SELECT person_id FROM bank_accounts WHERE account_number IN
        (SELECT account_number FROM atm_transactions WHERE atm_location LIKE "Leggett Street" AND transaction_type = "withdraw" AND day = 28))
        INTERSECT
        SELECT name FROM people WHERE phone_number IN
    (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 ORDER BY duration);
--+---------+
--|  name   |
--+---------+
--| Benista |
--| Bruce   |
--| Diana   |
--| Kenny   |
--| Taylor  |
--+---------+

-- First query not accurate from bakery_security_logs
-- there were a lot of people that came in and out of the bakery, check flights first to see how many left fiftyville
SELECT * FROM airports;
--8, CSF, Fiftyville Regional Airport, Fiftyville
SELECT id FROM flights WHERE day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville");
-- get name from the passengers on the flights outbound the day after the crime
SELECT name FROM people WHERE passport_number IN
    (SELECT DISTINCT(passport_number) FROM passengers WHERE flight_id IN
        (SELECT id FROM flights WHERE day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")));
-- 37 results, narrow down to earliest flight
SELECT id, hour, minute FROM flights WHERE day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") ORDER BY hour;
-- limit flights to 1 sorted by time
SELECT name FROM people WHERE passport_number IN
    (SELECT DISTINCT(passport_number) FROM passengers WHERE flight_id IN
        (SELECT id FROM flights WHERE day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") ORDER BY hour LIMIT 1)) ORDER BY name;
--+--------+
--|  name  |
--+--------+
--| Bruce  |
--| Doris  |
--| Edward |
--| Kelsey |
--| Kenny  |
--| Luca   |
--| Sofia  |
--| Taylor |
--+--------+
   SELECT name
     FROM people
    WHERE id IN
          (SELECT person_id
             FROM bank_accounts
            WHERE account_number IN
                  (SELECT account_number
                     FROM atm_transactions
                    WHERE atm_location LIKE "Leggett Street"
                          AND transaction_type = "withdraw"
                          AND day = 28
                  )
          )

INTERSECT

   SELECT name
     FROM people
    WHERE phone_number IN
          (SELECT caller
             FROM phone_calls
            WHERE year = 2021
                  AND month = 7
                  AND day = 28
                  AND duration < 60
          )

INTERSECT

   SELECT name
     FROM people
    WHERE passport_number IN
          (SELECT passport_number
             FROM passengers
            WHERE flight_id IN
                  (SELECT id
                     FROM flights
                    WHERE day = 29
                          AND origin_airport_id =
                          (SELECT id
                             FROM airports
                            WHERE city = "Fiftyville"
                          )
                 ORDER BY hour
                    LIMIT 1
                  )
          )
 ORDER BY name;
--this narrows down to 3 people that INTERSECT across all 3 searches
SELECT name, year, month, day, transcript FROM interviews WHERE transcript like "%bakery%" AND day = 28;
--didn't notice the time ruth said, within 10 mins of theft got in car and left the bakery parking lot
--crime_scene_reports said it took place at 10:15am
-- looking for an exit from the bakery parking lot between 10:15am and 10:25am
SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = "exit";
-- just like before, COLLECT THOSE NAMES!
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = "exit");
-- put it into the INTERSECT and hope it returns 1 name!!
   SELECT name
     FROM people
    WHERE id IN
          (SELECT person_id
             FROM bank_accounts
            WHERE account_number IN
                  (SELECT account_number
                     FROM atm_transactions
                    WHERE atm_location LIKE "Leggett Street"
                          AND transaction_type = "withdraw"
                          AND day = 28
                  )
          )

INTERSECT

   SELECT name
     FROM people
    WHERE phone_number IN
          (SELECT caller
             FROM phone_calls
            WHERE year = 2021
                  AND month = 7
                  AND day = 28
                  AND duration < 60
          )

INTERSECT

   SELECT name
     FROM people
    WHERE passport_number IN
          (SELECT passport_number
             FROM passengers
            WHERE flight_id IN
                  (SELECT id
                     FROM flights
                    WHERE day = 29
                          AND origin_airport_id =
                          (SELECT id
                             FROM airports
                            WHERE city = "Fiftyville"
                          )
                 ORDER BY hour
                    LIMIT 1
                  )
          )

INTERSECT

   SELECT name
     FROM people
    WHERE license_plate IN
          (SELECT license_plate
             FROM bakery_security_logs
            WHERE day = 28
                  AND hour = 10
                  AND minute BETWEEN 15 AND 25
                  AND activity = "exit"
          )

 ORDER BY name;
-- YAY!! I knew it!! (well not really, and I haven't tested it yet so Bruce might not done has hers' so we will see)


-- To find flight and destination
-- To confirm he was on the flight
SELECT origin_airport_id FROM flights WHERE id IN (SELECT flight_id FROM passengers WHERE passport_number = (SELECT passport_number FROM people WHERE name = "Bruce"));
-- Now to see where it went
SELECT destination_airport_id FROM flights WHERE id IN (SELECT flight_id FROM passengers WHERE passport_number = (SELECT passport_number FROM people WHERE = "Bruce"));
-- Then the city where the destination airport is
SELECT city FROM airports WHERE id =
    (SELECT destination_airport_id FROM flights WHERE id IN
        (SELECT flight_id FROM passengers WHERE passport_number =
            (SELECT passport_number FROM people WHERE name = "Bruce")));
--+---------------+
--|     city      |
--+---------------+
--| New York City |
--+---------------+
-- Now to find his partner in crime!
-- Back to the phones
SELECT caller, receiver FROM phone_calls WHERE caller = (SELECT phone_number FROM people WHERE name = "Bruce");
-- Narrow down to the day
SELECT caller, receiver FROM phone_calls WHERE day = 28 AND caller = (SELECT phone_number FROM people WHERE name = "Bruce");
-- Still 4 unique numbers, so find the people's names
SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE day = 28 AND caller = (SELECT phone_number FROM people WHERE name = "Bruce"));
-- too many results, narrow down length of call
SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE day = 28 AND duration < 60 AND caller = (SELECT phone_number FROM people WHERE name = "Bruce"));
--+-------+
--| name  |
--+-------+
--| Robin |
--+-------+
--!! Robin was the accomplice!!

-- This was such a fun game, because it felt more like a game than a problem set! Honestly this course is amazing!!
-- Also I added a lot of comments because this is really what was going through my head, it isn't the most efficient but it was a real adventure!!