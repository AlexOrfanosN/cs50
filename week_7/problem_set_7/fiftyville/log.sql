--crime took place on Humphrey Street on the 28th of July.

--Read description from crime scene
SELECT description FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = "Humphrey Street";
--crime took place at 10.15am

-- ill start with the interviews
SELECT name,transcript FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28
AND transcript LIKE "%bakery%";

--Three witnesses.
--Ruth saw the thief exiting the bakery in his car sometime within ten minutes from the theft.
--ill access the bakery security logs and see who exited up to 10.25am. I will also cross reference their plates with their names.

SELECT name, bakery_security_logs.hour, bakery_security_logs.minute
FROM people
JOIN bakery_security_logs
ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.year = 2021
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.activity = "exit"
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25
ORDER BY bakery_security_logs.minute;

-- i have some useful data from the bakery security logs but still not much to go on.
-- The second witness, Eugene stated that he saw the thief earlier withdrawing money from an atm in Leggett Street

SELECT account_number, amount
FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";

--Now i will find the owners of these accounts. This will help narrow down the suspect list.

SELECT name, atm_transactions.amount
FROM people
JOIN bank_accounts
ON people.id = bank_accounts.person_id
JOIN atm_transactions
ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year = 2021
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw";

--So far i have narrowed it down to 4 suspects that appear in both searches. (Bruce, Diana, Iman and Luca)

--Next ill follow Raymonds interview which states that:
--1) The thief made a call as he was leaving the bakery that lasted less than a minute and,
--2) He asked the person(accomplice) to book him a the earliest flight oout of fiftyville on the next day.

-- Im searching for flights out of fiftyville on the next day and oredering them by time of departure.
SELECT flights.id, full_name, city, flights.hour, flights.minute
FROM airports
JOIN flights
ON airports.id = flights.destination_airport_id
WHERE flights.origin_airport_id =
(SELECT id
FROM airports
WHERE city = "Fiftyville")
AND flights.year = 2021
AND flights.month = 7
AND flights.day = 29
ORDER BY flights.hour, flights.minute;

--The first flight out of Fiftyville is to LaGuardia Airport, New York City at 8.20am. Airport id is 36.
--This must be the destination he escaped to

-- Now i need to access the passenger list for this flight.
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
FROM people
JOIN passengers
ON people.passport_number = passengers.passport_number
JOIN flights
ON passengers.flight_id = flights.id
WHERE flights.year = 2021
AND flights.month = 7
AND flights.day = 29
AND flights.hour = 8
AND flights.minute = 20
ORDER BY passengers.passport_number;

--Managed to narrow down to two suspects (Bruce and Luca)

--Following up on Raymonds interview, i will now access the phone logs to try finding the suspect.
--Ill search for phone calls that their duration was equal or less than a minute and order them.
SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration <= 60
ORDER BY phone_calls.duration;

--By process of elimination, only Bruce can be the thief. He made a call that lasted 45 seconds.
--I will try finding the rechievers of said calls and find his accomplice by matching the duration of the call.
SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration <= 60
ORDER BY phone_calls.duration;

--There is one match. Robin and the duration is also 45 seconds.
-- i can safely assume that he is the accomplice.
