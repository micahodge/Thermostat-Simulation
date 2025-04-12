<h1>Thermostat Simulation System</h1>

<h2>Description</h2>
This project is a simulation that lets a user control temperature while having heating and cooling modes. Two breadboards in this project contained connections and circuits. The first smaller breadboard had nine wires in it; the front wire was to turn the system on and off, the second wire was to turn the heating and cooling modes on and off (positive for heating mode and negative for cooling mode), and the last seven wires were binary wires that the user could use to input their desired temperature in. The second and bigger breadboard contained the TMP36 temperature sensor circuit and 11 LEDs. The left seven LEDs showed the recorded temperature (from the TMP36 temperature sensor) of the room in binary; the next three LEDs showed if the system was in heating mode (red LED), if the fan was on or off (yellow LED), or if the cooling mode was on (green LED); and the last LED showed if the system was turned on or off. <br><br>
If the user's desired temperature was less than 2 degrees (higher or lower) than the actual temperature in the room, then the fan, heating, and cooling system would turn off. If the desired temperature was more than 2 degrees (higher or lower) than the actual room temperature, then the fan would turn on, and either the heating or the cooling system would turn on until the room temperature was within 2 degrees of the desired temperature. The heating and cooling system also had a cooldown system. Whenever the heating mode was switched to the cooling mode (and vice versa), it would have a 30-second cooldown before it would officially switch to the cooling mode. Also, if the system was turned off, then the fan would stay on for 15 seconds as a cooldown to the system; but then if the system was turned back on within 30 seconds of it being turned off, the system would wait the entire 30 seconds until it was turned back on.
<br />


<h2>Sensors and Electronics Used</h2>

- <b>Arduino Mega 2560</b> 
- <b>TMP36 Temperature Sensor</b>

<h2>Challenges and Solutions</h2>

- <b>A big challenge with this project was that for each TMP36 sensor that I used, they kept giving me bad readings that varied a lot. If I did this project again, I would invest in finding a more reliable temperature sensor. The sensor sometimes gave bad values, making the system do things it was not meant to do. To counter this, I would set variables inside the code to specific values so that the simulation could still be tested. Doing this, the simulation fully worked as intended. This only worked for the testing of this project, and, in the end, a good sensor would be the only thing that could entirely fix this problem.
-<br><br>
Another small challenge I had to deal with was coding the system to have a 30 cooldown every time the mode was switched from heating to cooling or vice versa. At the start of the project, the system only knew when it was in heating or cooling mode, but it did not know that it might have just been switched to the mode just then, so it would not know when to have a cooldown. The fix to this was to put a variable called "lastmode" in every part of my code. This variable would change from 0-1 based on whether its previous mode was different or not. For each scenario that this system could have, it has a choice between 2 options: one where the previous mode is the same, and one where the previous mode is different.
- </b> 

<h2>Photos</h2>

<p align="center">
Front View: <br/>
<img src="https://i.imgur.com/eNo5MLC.jpeg" height="50%" width="50%" />
<br />
<br />
Side View:  <br/>
<img src="https://i.imgur.com/wOvYBpE.jpeg" height="50%" width="50%"/>
<br />
<br />
