# Code Base

## Primary Repos
### [Avionics](https://github.com/CURocketEngineering/Avionics)
This is the main repo we work off of. It houses all the code often used across multiple flight computers. Everything on it must be general, organized, and testable. 

### [MARTHA-1.1 / MARTHA-1.3](https://github.com/CURocketEngineering/MARTHA)
MARTHA has the software specific to our custom PCB flight computer MARHTA (Miniaturized Avionics for Rapid Testing Handling and Assessment)   
Notice that it includes the Avionics repo within the [lib folder](https://github.com/CURocketEngineering/MARTHA-1.3).

### [Active-Aero](https://github.com/CURocketEngineering/Active-Aero)
This the repo for our active-aero flight computers which control the air brakes on the rocket.

### [Ground-Station](https://github.com/CURocketEngineering/Ground-Station)
Contains all of our software ran on ground stations systems. Including laptops for getting data off of the flight computer and radio systems for communicating with the rocket.

### [SAVA](https://github.com/CURocketEngineering/SAVA)
Repo for our 2025 payload which reads altitude data from 3 different altimeters simultaneously.

### [HIL-Lab](https://github.com/CURocketEngineering/HIL-lab)
This contains the software used by our support servers in our HIL (Hardware-In-the-Loop) lab. These servers are hooked up to a flight computer and made accessible remotely to support easier development. 
