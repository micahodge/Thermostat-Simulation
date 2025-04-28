int cat = 0, mode = 30, power = 31, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, tempF = 0, lastmode = 1; //initializing variables
int greenpower = 23, redheat = 22, greencool = 24, yellowfan = 25, binary1 = 47, binary2 = 45, binary3 = 43, binary4 = 41, binary5 = 39, binary6 = 37, binary7 = 35;//initializing LED and binary variables
int input1 = 46, input2 = 44, input3 = 42, input4 = 40, input5 = 38, input6 = 36, input7 = 34, decimal = 0; //initializing more binary variables
float voltage = 0, tempC = 0; // initializing float variables to get accurate read of voltage and temperature

void setup() {
  pinMode(power, INPUT); //setting pin 31 to input
  pinMode(mode, INPUT);//setting pin 30 to input
  pinMode(input1, INPUT);//setting pin 46 to input
  pinMode(input2, INPUT);//setting pin 44 to input
  pinMode(input3, INPUT);//setting pin 42 to input
  pinMode(input4, INPUT);//setting pin 40 to input
  pinMode(input5, INPUT);//setting pin 38 to input
  pinMode(input6, INPUT);//setting pin 36 to input
  pinMode(input7, INPUT);//setting pin 34 to input
  pinMode(greenpower, OUTPUT);//setting pin 23 to output
  pinMode(redheat, OUTPUT);//setting pin 22 to output
  pinMode(greencool, OUTPUT);//setting pin 24 to output
  pinMode(yellowfan, OUTPUT);//setting pin 25 to output
  pinMode(binary1, OUTPUT);//setting pin 47 to output
  pinMode(binary2, OUTPUT);//setting pin 45 to output
  pinMode(binary3, OUTPUT);//setting pin 43 to output
  pinMode(binary4, OUTPUT);//setting pin 41 to output
  pinMode(binary5, OUTPUT);//setting pin 39 to output
  pinMode(binary6, OUTPUT);//setting pin 37 to output
  pinMode(binary7, OUTPUT);//setting pin 35 to output
  Serial.begin(9600); // so the computer and the arduino can communicate smoothly
}

void loop() {
  cat = analogRead(A0); // reads the temperature sensor value
  voltage = cat * (5.0 / 1023); // finds the voltage through this equation
  tempC = (voltage) * 100; //finds the Celsius temperature through voltage value
  tempF = (9/5.0 * tempC) + 32; // calculates Fahrenheit temperature through Celsius value
  Serial.println(""); // prints a space line
  Serial.print("Current Temperature:"); // prints the words "Current Temperature:"
  Serial.println(tempF); // prints the Fahrenheit temperature value

  input1 = digitalRead(46); // stores the input value in input1
  input2 = digitalRead(44);// stores the input value in input2
  input3 = digitalRead(42);// stores the input value in input3
  input4 = digitalRead(40);// stores the input value in input4
  input5 = digitalRead(38);// stores the input value in input5
  input6 = digitalRead(36);// stores the input value in input6
  input7 = digitalRead(34);// stores the input value in input7

  input1 = input1 * 64; // multiplies the input1 value by 2^6
  input2 = input2 * 32;// multiplies the input2 value by 2^5
  input3 = input3 * 16;// multiplies the input3 value by 2^4
  input4 = input4 * 8;// multiplies the input4 value by 2^3
  input5 = input5 * 4;// multiplies the input5 value by 2^2
  input6 = input6 * 2;// multiplies the input6 value by 2^1
  input7 = input7 * 1;// multiplies the input7 value by 2^0
  decimal = (input1+input2+input3+input4+input5+input6+input7); // adds all of the input values up which becomes a decimal number
  Serial.print("Desired Temperature:"); // prints the words "Desired Temperature:"
  Serial.println(decimal); // prints the decimal value

  one = tempF % 2; // stores the last binary value as 1 or 0
  two = (tempF / 2) % 2;//stores the sixth binary value as 1 or 0
  three = (tempF / 4) % 2;// stores the fifth binary value as 1 or 0
  four = (tempF / 8) % 2;// stores the fourth binary value as 1 or 0
  five = (tempF / 16) % 2;// stores the third binary value as 1 or 0
  six = (tempF / 32) % 2;// stores the second binary value as 1 or 0
  seven = (tempF / 64) % 2;// stores the first binary value as 1 or 0

  digitalWrite(binary1, seven); //outputs the value (1 or 0) to the first LED pin
  digitalWrite(binary2, six);//outputs the value (1 or 0) to the second LED pin
  digitalWrite(binary3, five);//outputs the value (1 or 0) to the third LED pin
  digitalWrite(binary4, four);//outputs the value (1 or 0) to the fourth LED pin
  digitalWrite(binary5, three);//outputs the value (1 or 0) to the fifth LED pin
  digitalWrite(binary6, two);//outputs the value (1 or 0) to the sixth LED pin
  digitalWrite(binary7, one);//outputs the value (1 or 0) to the last LED pin

  power = digitalRead(31); // stores the value of the power input wire
  mode = digitalRead(30); // stores the value of the mode input wire

 if (power == 1) // if the power input is positive (equal to 1)
   { if (mode == 0) // if the mode input is negative (equal to 0)
  {if (tempF > decimal + 2) // if the temperature is greater than the desired temperature plus 2
    {if (lastmode == 0) // if the last mode of the system was cooling
    {digitalWrite(yellowfan, 1); // turn yellow fan LED on
   digitalWrite(greencool, 1); // turn green cooling LED on
   digitalWrite(greenpower, 1);//turn green power LED on
   digitalWrite(redheat, 0);// turn red heat LED on
   Serial.println("Your system is set to cooling."); //prints the words "Your system is set to cooling."
    lastmode = 0; // sets the lastmode variable to 0(cooling)
   delay(5000);} // delays the program 5 seconds
    else if (lastmode == 1) // if the last mode of the system was heating
    {digitalWrite(yellowfan, 0);// turn yellow fan LED off
   digitalWrite(greencool, 0);// turn green cooling LED off
   digitalWrite(greenpower, 1);//turn green power LED on
   digitalWrite(redheat, 0);// turn red heat LED off
   Serial.println("There is a 30 second cooldown when switching modes."); // prints the words "There is a 30 second cooldown when switching modes."
   delay(30000); // delays the programm 30 seconds
    lastmode = 0;}} // sets the last mode variable to 0(cooling)
  else if (tempF < decimal - 2) //if the temperature is less than the desired temperature minus 2
  {if (lastmode == 0)// if the last mode of the system was cooling
   { digitalWrite(yellowfan, 1);// turn yellow fan LED on
   digitalWrite(redheat, 0);// turn red heat LED off
   digitalWrite(greenpower, 1);//turn green power LED on
   digitalWrite(greencool, 1);// turn green cooling LED on
   Serial.println("Your system is set to cooling."); // prints the words "Your system is set to cooling."
   lastmode = 0; // sets the lastmode variable to 0(cooling)
   delay(5000);} // delays the program 5 seconds
   else if (lastmode == 1)// if the last mode of the system was heating
   {digitalWrite(yellowfan, 0); // turn yellow fan LED off
   digitalWrite(greencool, 0);// turn green cooling LED off
   digitalWrite(greenpower, 1);//turn green power LED on
   digitalWrite(redheat, 0);// turn red heat LED off
   Serial.println("There is a 30 second cooldown when switching modes.");// prints the words "There is a 30 second cooldown when switching modes."
   delay(30000);// delays the program 30 seconds
   lastmode = 0;}} // sets the lastmode variable to 0(cooling)
  else if (tempF >= (decimal - 2) && tempF <= (decimal + 2)) // if the temperature is within 2 on either side of the desired temperature
   {if (lastmode == 0)// if the last mode of the system was cooling
   {digitalWrite(yellowfan, 0); // turn yellow fan LED off
    digitalWrite(greencool, 0);// turn green cooling LED off
    digitalWrite(greenpower, 1);//turn green power LED on
    digitalWrite(redheat, 0);// turn red heat LED off
    lastmode = 0; // sets the lastmode variable to 0(cooling)
    delay(5000);}// delays the program 5 seconds
    else if (lastmode == 1)// if the last mode of the system was heating
    {digitalWrite(yellowfan, 0);// turn yellow fan LED off
   digitalWrite(greencool, 0);// turn green cooling LED off
   digitalWrite(greenpower, 1);//turn green power LED on
   digitalWrite(redheat, 0);// turn red heat LED off
   Serial.println("There is a 30 second cooldown when switching modes.");// prints the words "There is a 30 second cooldown when switching modes."
   delay(30000);// delays the program 30 seconds
    lastmode = 0;}}} // sets the lastmode variable to 0 (cooling)
  
  if (mode == 1) // if the mode input variable reads positive (equal to 1)
  {if (tempF > decimal + 2) // if the temperature is greater than the desired temperature plus 2
  {if (lastmode == 1)// if the last mode of the system was heating
  {digitalWrite(yellowfan, 1);// turn yellow fan LED on
   digitalWrite(greencool, 0);// turn green cooling LED off
   digitalWrite(greenpower, 1);//turn green power LED on
   digitalWrite(redheat, 1);// turn red heat LED on
   Serial.println("Your system is set to heating."); // prints the words "Your system is set to heating."
   lastmode = 1; // sets the lastmode variable to 1 (heating)
   delay(5000);}// delays the program 5 seconds
   else if (lastmode == 0)// if the last mode of the system was cooling
   {digitalWrite(yellowfan, 0);// turn yellow fan LED off
   digitalWrite(greencool, 0);// turn green cooling LED off
   digitalWrite(greenpower, 1);//turn green power LED on
   digitalWrite(redheat, 0);// turn red heat LED off
   Serial.println("There is a 30 second cooldown when switching modes.");// prints the words "There is a 30 second cooldown when switching modes."
   delay(30000);// delays the program 30 seconds
   lastmode = 1;}}// sets the lastmode variable to 1 (heating)
  else if (tempF < decimal - 2) // if the temperature is less than the desired temperature minus 2
  {if (lastmode == 1)// if the last mode of the system was heating
  {digitalWrite(yellowfan, 1);// turn yellow fan LED on
   digitalWrite(redheat, 1);// turn red heat LED on
   digitalWrite(greenpower, 1);//turn green power LED on
   digitalWrite(greencool, 0);// turn green cooling LED off
   Serial.println("Your system is set to heating.");// prints the words "Your system is set to heating."
   lastmode = 1;// sets the lastmode variable to 1 (heating)
   delay(5000);}// delays the program 5 seconds
   else if (lastmode == 0)// if the last mode of the system was cooling
   {digitalWrite(yellowfan, 0);// turn yellow fan LED off
   digitalWrite(greencool, 0);// turn green cooling LED off
   digitalWrite(greenpower, 1);//turn green power LED on
   digitalWrite(redheat, 0);// turn red heat LED off
   Serial.println("There is a 30 second cooldown when switching modes.");// prints the words "There is a 30 second cooldown when switching modes."
   delay(30000);// delays the program 30 seconds
   lastmode = 1;}}// sets the lastmode variable to 1 (heating)
  else if (tempF >= (decimal - 2) && tempF <= (decimal + 2)) // if the temperature is within 2 on either side of the desired temperature
   {if (lastmode == 1)// if the last mode of the system was heating
   {digitalWrite(yellowfan, 0);// turn yellow fan LED off
    digitalWrite(greencool, 0);// turn green cooling LED off
    digitalWrite(greenpower, 1);//turn green power LED on
    digitalWrite(redheat, 0);// turn red heat LED off
    lastmode = 1;// sets the lastmode variable to 1 (heating)
    delay(5000);}// delays the program 5 seconds
    else if (lastmode == 0)// if the last mode of the system was cooling
    {digitalWrite(yellowfan, 0);// turn yellow fan LED off
   digitalWrite(greencool, 0);// turn green cooling LED off
   digitalWrite(greenpower, 1);//turn green power LED on
   digitalWrite(redheat, 0);// turn red heat LED off
   Serial.println("There is a 30 second cooldown when switching modes.");// prints the words "There is a 30 second cooldown when switching modes."
   delay(30000); // delays the program 30 seconds
    lastmode = 1;}}}}// sets the lastmode variable to 1 (heating)

  if (power == 0) //if the power input is negative (equl to 0)
    {digitalWrite(greenpower, 0); // turns the green power LED off
    digitalWrite(greencool, 0);//turns the green cooling LED off
    digitalWrite(redheat, 0);//turns the red heating LED off
    digitalWrite(yellowfan, 1); //turns the yellow fan LED on
    Serial.println("The system has been turned off."); //prints the words "The system has been turned off."
    delay(15000); // delays the program 15 seconds
    digitalWrite(greenpower, 0); // turns the green power LED off
    digitalWrite(greencool, 0);//turns the green cooling LED off
    digitalWrite(redheat, 0);//turns the red heating LED off
    digitalWrite(yellowfan, 0); //turns the yellow fan LED off
    delay(15000);} //delays the program 15 seconds
}