Welcome to the Hunt the Wumpus game! 
-
You play as an adventurer entering the cave of the
Wumpus, and your goal is to collect the gold treasure in the cave and escape without
dying. There are different hazards including the Wumpus throughout the cave, so be wary!
Happy playing!

-----------------------------------------------------------------------------------------

Instructions:

1) In this repository, there is a makefile! This will make compiling much simpler, download this and you can compile with:

       make wumpus

If you would like to check for memory leaks (for debugging purposes) you can compile with: 

    make leak_check

2) Run the program with:

./wumpus (make leak_check will run this automatically)

3) The program will first ask you to enter the desired side length of your cave. 
You can enter a integer value between 4 and 50 inclusive for your cave. If you enter 
an integer outside this range, the program will ask you to re-input a valid value.

 Next, the program will ask you whether you would like to be in debug mode or not. 
 Debug mode will allow you to see where the Wumpus, the gold, the escape rope, and 
 other hazards are in the cave. You can enter an integer value, 1 for debug mode to be 
 on and 0 if you would like it off. Like the side length, if you enter a integer that is not
 0 or 1, the program will ask you to re-input a valid value.

 After this you will see your Wumpus cave printed to the screen. 
 Here are two examples:

    debug mode on (5x5 cave):           debug mode off (6x6 cave):
    -------------------------           ------------------------------
       ||*~ || W ||   || S ||              ||   ||   ||   ||   ||   ||
    -------------------------           ------------------------------
     G ||   ||   ||   ||   ||              ||   ||   ||   ||   ||   ||
    -------------------------           ------------------------------
       || P ||   ||   ||   ||              ||   ||   ||   ||   ||   ||
    -------------------------           ------------------------------
       || P ||   ||   || S ||              ||   ||*  ||   ||   ||   ||
    -------------------------           ------------------------------
       ||   ||   ||   ||   ||              ||   ||   ||   ||   ||   ||
    -------------------------           ------------------------------
                                           ||   ||   ||   ||   ||   ||
                                        ------------------------------

 Above the cave map, there will be two lines telling you your oxygen level and how many
 arrows you have. You will start with 3 arrows every game, and cannot gain more so use
 them sparingly!

 Right below the cave map, you may see some messages, known as percepts. These will let you know
 when you are next to a room with a certain "event" in it. These events are:

 the Gold (G) - this is the room where the gold treasure is being kept. If you walk into this 
                room, you will automatically pick up the gold.

    The percept for the Gold is: "You see a glimmer nearby."

 the Wumpus (W) - this is the room in which the Wumpus resides. If you enter this room, the
                  Wumpus will wake up and eat you and you will automatically die.

    The percept for the Wumpus is: "You smell a terrible stench."

 Stalactites (S) - there are two rooms that have stalactites in them. If you walk into either
                   of these rooms, there is a 50% chance that the stalactites will fall and
                   kill you.

    The percept for stalactites is: "You hear water dripping."

 Submerged Pool Access (P) - there are two rooms that provide access to the cave's underwater
                             pool system. If you enter one of these rooms, you will automatically
                             dive into the pool system. While underwater you can travel through the
                             cave without encountering any events that are not another (or the same)
                             pool access room. However, every turn you spend underwater, you oxygen
                             level will deplete by one. If you run out of oxygen, you will drown and die.
                             Your oxygen resets when you resurface from the pool system.

    The percept for pool access rooms is: "You hear wind blowing." 

 A menu outlining what actions you can take will also be printed:

 W-up
 
 A-left
 
 S-down
 
 D-right
 
 f-fire an arrow

 The letters on the left are what letters you can enter to take an action. 
 Only enter 1 letter for this input, as this will take the first character in your input.
 If the first character you enter is not one of the 5 required to take an 
 action, the program will reprompt you for a valid input.

 If you choose to enter 'w':
 
   - the player will move one room to the north assuming there is no wall.

 If you choose to enter 'a':
 
   - the player will move one room to the west assuming there is no wall.

 If you choose to enter 's':
 
   - the player will move one room to the south assuming there is no wall.

 If you choose to enter 'd':
 
   - the player will move one room to the east assuming there is no wall.

 If you choose to enter 'f':
 
   - you get to fire an arrow! You can choose which direction (same as moving) to shoot the arrow.
      if your arrow hits the Wumpus, you will kill it! You do not have to worry about it when looking
      for the gold.
      if your arrow misses, there is a 75% chance of the Wumpus waking up and moving to a different
      room in the cave system. This can be the room you are currently in, so be careful!

 Once you collect the gold, you need to make it back to the room you entered the cave at to escape and win,
 so make sure to remember where you started.

 When the game is over (you either escape with the gold or die in the cave), another menu will be printed:

    Would you like to:
    1: play in the same cave
    2: play with a different cave
    3: quit the game entirely

 Playing the same cave would mean you play again with the same cave configuration (same size, events in same place, etc)
 If you want to play in a different cave, the program will once again ask what side length you would like the cave to be
 with the same conditions of being an integer between 4 and 50 inclusive.
 If you choose to quit the game, you would be exited from the program.

 This asks for an integer input based on the numbers on the left, so 1-3. If you enter an integer other than these, you
 will be reprompted for a valid input.

4) Limitations:
- you can only set your debug mode at the beginning of the program, all replays will hold the same debug mode.
