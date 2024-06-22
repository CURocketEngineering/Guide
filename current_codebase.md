# Code Base

## Primary Repos
### [Avionics](https://github.com/CURocketEngineering/Avionics)
This is the main repo we work off of. It houses all the code often used across multiple flight computers. Everything on it must be general, organized, and testable. 

### [MARTHA](https://github.com/CURocketEngineering/MARTHA)
MARTHA has the software specific to our custom PCB flight computer MARHTA (Miniaturized Avionics for Rapid Testing Handling and Assessment)   
Notice that it includes the Avionics repo within the [lib folder](https://github.com/CURocketEngineering/MARTHA/tree/main/lib).

### [HIL-lab](https://github.com/CURocketEngineering/HIL-lab)
This contains the software used by our support servers in our HIL (Hardware-In-the-Loop) lab. These servers are hooked up to a flight computer and made accessible remotely to support easier development. 
