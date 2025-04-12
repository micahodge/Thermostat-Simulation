<h1>Thermostat Simulation System</h1>

<h2>Description</h2>
Project consists of a simple PowerShell script that walks the user through "zeroing out" (wiping) any drives that are connected to the system. The utility allows you to select the target disk and choose the number of passes that are performed. The PowerShell script will configure a diskpart script file based on the user's selections and then launch Diskpart to perform the disk sanitization.
<br />


<h2>Sensors nad Electronics Used Used</h2>

- <b>Arduino Mega 2560</b> 
- <b>TMP36 Temperature Sensor</b>

<h2>Challenges and Solutions</h2>

- <b>The main challenge with this project was that for each TMP36 sensor that I used, they kept giving me bad readings that varied a lot. If I did this project again, I would invest in finding a more reliable temperature sensor. The sensor sometimes gave bad values, making the system do things it was not meant to do. To counter this, I would set variables inside the code to specific values so that the simulation could still be tested. Doing this, the simulation fully worked as intended. This only worked for the testing of this project, and, in the end, a good sensor would be the only thing that could entirely fix this problem.</b> 

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
