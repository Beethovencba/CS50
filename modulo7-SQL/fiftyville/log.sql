-- Keep a log of any SQL queries you execute as you solve the mystery.

Transcrição do depoimento:
sqlite3 fiftyville.db "SELECT description FROM crime_scene_reports WHERE year = '2020' AND month = '7' AND day = '28' AND street = 'Chamberlin Street';" > depoimento.sql

Depoimentos:
sqlite3 fiftyville.db "SELECT name, transcript FROM interviews WHERE month = '7' AND day = '28' AND year = '2020' AND transcript LIKE  '%courthouse%';" > depoimentos.sql

Placa do carro:
sqlite3 fiftyville.db  "SELECT license_plate FROM courthouse_security_logs WHERE activity = 'exit' AND month = '7' AND hour = '10' AND minute BETWEEN 15 AND 30;" > placas.sql

Saques e contas
sqlite3 fiftyville.db "SELECT account_number, amount FROM atm_transactions WHERE month = '7' AND day = '28' AND atm_location = 'Fifer Street';" > compra.sql

Ligaçoes Feitas:
sqlite3 fiftyville.db "SELECT caller, receiver FROM phone_calls WHERE month = '7' AND day = '28' AND duration <= 60;" > ligacoes_feitas.sql


# Cruzamento dos DB people, bank_accounts e atm_transactions:

sqlite3 fiftyville.db "SELECT name FROM people WHERE id IN (
>     SELECT person_id
>     FROM bank_accounts
>     WHERE account_number IN (
>         SELECT account_number
>         FROM atm_transactions
>         WHERE month = '7' AND day = '28' AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw'
>     )
> );" > nomes_contas.sql





# Cruzamento dos DB people, bank_accounts, atm_transactions e phone_calls:

sqlite3 fiftyville.db "

    SELECT name, phone_number, passport_number, license_plate FROM people

    JOIN bank_accounts ON people.id = person_id
    WHERE account_number IN
        (SELECT account_number FROM atm_transactions
        WHERE month = '7' AND day = '28' AND atm_location = 'Fifer Street'
        AND transaction_type = 'withdraw')

    AND phone_number IN
        (SELECT caller FROM phone_calls
        WHERE month = '7' AND day = '28' AND duration <= 60)

    AND license_plate IN
        (SELECT license_plate FROM courthouse_security_logs
        WHERE activity = 'exit' AND month = '7' AND hour = '10'
        AND minute BETWEEN 15 AND 30);

" > nomes_contas3.sql



# cumplices:

sqlite3 fiftyville.db "

    SELECT name, phone_number, passport_number, license_plate FROM people
    WHERE phone_number = '(367) 555-5533'
    OR phone_number = '(375) 555-8161';

" > cumplice_and_criminoso1.sql

# Destino:

sqlite3 fiftyville.db "

    SELECT abbreviation, full_name, city FROM airports

    WHERE id IN
        (SELECT origin_airport_id FROM flights
        WHERE id IN
            (SELECT flight_id FROM passengers WHERE passport_number = '5773159633')
        AND month = '7' AND day = '29'

    UNION

        SELECT destination_airport_id FROM flights
        WHERE id IN
            (SELECT flight_id FROM passengers WHERE passport_number = '5773159633')
        AND month = '7' AND day = '29');

" > destino.sql

