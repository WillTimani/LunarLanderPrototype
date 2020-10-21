# LunarLander

LunarLander Prototype

This is a simple Lunar Lander clone. Original can be found here: http://moonlander.seb.ly/

Currently, this project only features minimal backend implementation with a simple frontend that is used to demonstrate use cases and planned functionality. 

How to Run:
  1. Pull this repository to a local system that can run shell scripts and executables
  2. Execute command: ./Build.sh
  3. Once the build has finished there should be an executable named "project_(clang++).exe". It is reccomended to change the name of this time something simpler such as LunarLander.exe.
  4. Run the executable that was just created: ./LunarLander.exe
  Note: Nothing may appear at first after initialization. Pressing enter should fix this and allow the user to enter a name, password and role to log in.
  5. Enter a name, password and role in order to login. If the credentials are not present, login will fail. Login credentials are currently hard coded in LoginDB.cpp inside the TechinicalServices/Persistence folder.
  6. Choose between Start Mission, Scoreboard, Store, Settings or Logout by inputing the number next to the selecting and pressing enter. Additional options will be given based on specified selections. 
  
Sample invocation showing a mission being played: 

![ThrustersSampleRun](https://github.com/WillTimani/LunarLanderPrototype/blob/master/Images/ThrustersSampleRun.png)

Sample invocation showing a navigation of the in-game store: 

![StoreSampleRun](https://github.com/WillTimani/LunarLanderPrototype/blob/master/Images/StoreSampleRun.png)

Design and Implementation created by:
William Timani
Matthew Quinlan 
Thomas Smith
Vijay Duggirala
