// #ardutronic in Instagram

//pin7 = red
//pin8 = green
wait = 1000;

void loop()
(
    digitalWrite(red, HIGH);
    delay(wait);
    digitalWrite(red, LOW);
    delay(wait);
    counter++;

    if(counter == 5)
    (
        digitalWrite(green, HIGH);
        delay(3000);
        digitalWrite(green, LOW);
        counter = 0;
    )
)