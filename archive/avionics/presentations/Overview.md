# Overview of Avionics
Note: this is designed to be 1:1 with a markdown and latex version. Conversion can 
be done via `pandoc`. Edit the version in markdown for an easier time editing, 
it is considered the master. A fall-2020 goal will be to make this information
as thorough as possible and contain links to more detail on github. As of now,
this documentation is considered a very high-level overview of avionics as a whole.

## Requirements
The avionics bay is designed for data collection and telemetry 
(hence [sounding rocket](https://en.wikipedia.org/wiki/Sounding_rocket)). The
avionics bay is also responsible for the recovery of the rocket, a process using
a smaller drogue parachute at apogee (the highest point of fight) until the rocket
reaches closer to the ground and activates a larger main parachute. The two-chute
system allows us to safely recover the rocket while allowing it to fall to the 
ground as fast (and as close) as possible. 

IREC requires redundancy (as any good system should have). This is usually done
by two proprietary SRAD (Student-Researched-And-Developed) systems and one 
COTS (Commercial-Off-The-Shelf) system. Recent IREC rules have now required use of
a GPS beacon, a system that will record GPS location and ping a tracker to make
physical recovery easier for a ground team. 

Avionics can be as simple, or as difficult, as you want it to be. A simple system
involves purchasing a couple COTS systems and only using those. This would be
cheaper, and much easier, than developing our own system. But then how would we
learn anything?

## Flight Logic
Main flight is handled via our proprietary system Firefly χ. This system uses a 
raspberry pi with configurable mediums for data recording, communication, and
ejecting parachutes. The system keeps track of the rocket in states (no, this 
isn't just a few if-statements). The states are (loosely) as follows: Idle (when
the rocket is not doing anything), Armed (when the rocket is on the launch pad
and waiting to be ignited), Drifting (moving upwards approaching apogee), 
Apogee (highest point), Waiting (falling, waiting to reach an explicit height
to eject the second parachute), Recovery (waiting for a ground team to retrieve
the system). All logic is relative to the states and states only move in-order
(although we can take our system out of arm for obvious reasons). 

Each state change occurs due to a variable change from external measurements.
Since sensors are not necessarily 100% reliable, we utilize different techniques
to monitor the changes. Drifting is activited by a sudden upward acceleration.
Apogee is activated by a change in sign in the differential of air pressure.
Recovery is activated by a certain altitude. 

## Recovery
Recovery is done via a two-chute system. Previous implementations of ejection
involves a preasurized volume of the rocket, between two bulkheads, that connect
two carbon-fiber sections by shear-pins. The avionics system will activate a
relay (an electronic switch that connects two wires) on a state change that will
apply a signal to an e-match (an "electronic-match" that lights by electrical
current). The e-match can break open a system, such as a pressure-vessel containing
CO2, which fills the space with air, blowing out the shear-pins, and separating
the rocket. In the seperation, a parachute connected to both parts will come 
out and catch the rocket during the fall. 

A drogue parachute is used first to slow down the system while a larger parachute
allows for the rocket to safely land on the ground. 

## Previous Systems
The original implementation of the avionics bay was arduino-only. Since it was
difficult for new members to contribute, this implementation has been redone in
python on a Raspberry Pi to allow much more simplicity. Since arduinos are 
embedded systems, it didn't allow for much complexity. Using a Raspberry Pi,
CURE now has access to an operating system that allows us to be more creative
in our approach.

## Lessons Learned
Big issues in previous years involved telemetry. Technically, we have yet to make
it work. But this is good news! Our rockets still did awesome and once we have this
knocked out, we'll be killing it. 

Carbon fiber is no rf-transparent, meaning radio signals cannot easily escape the
rocket. A solution to this is to make the avionics bay out of another material.
Other solutions are being looked into, and more research will need to be done
in this field.

Know when to make something from scratch and when to use something already
implemented. Whether hardware or software, a good approach is a modular approach
in which we can move more proprietary later on.

Battery life is hard. Always have more batteries than you need. Make sure 
everything is also as secure as possible. 

## Upcoming Projects
Firefly chi, while technically complete, will be undergoing major restructuring to
make it even better. The new avionics bay will be designed to be 3d printed and 
as modular as possible, to make design on both avionics and structures greatly
simplified. 

APRS is being considered for use instead of XBees for radio communication (and
potentially even GPS!).

A proprietary sensorboard will be developed to make avionics sensors more 
"in-house." This will allow us to be more confident in our data and more creative
in what we can capture. 

The avionics dashboard has never been a priority due to a lack of telemetry.
A new, highly modular and great-looking dashboard will most likely be created
in ReDash. An easy approach will be to use a python backend to capture radio
data, save it to a sqlite database, and have the mounted sqlite database in a
docker container. 

Testing is very hard to do for avionics systems (just go and read about how
SpaceX tests avionics). In an effort with propulsion, avionics will try to
test hardware  before time on much simplified water-propelled rockets.

A camera system needs to be developed. A good implementation might be an 
independent system that sits on a seperate level of the avionics bay that is 
toggled on by firefly chi.

## Resources
All current avionics work can be found on github, a hosting site for work versioned
with the software git.
All CURE work can be found at [CURE](https://github.com/CURocketEngineering/cure).
Firefly chi work can be found at [firefly](https://github.com/CURocketEngineering/firefly_chi).
Avionics-specific notes and other information can be found at [team/avionics](https://github.com/CURocketEngineering/team/tree/master/avionics).

Other documentation can be found in-project. Firefly chi has most documentation built
into the code and markdown notes. 
