# Disaster on the Good Ship Lethbridge

2720 group project
spring 2019
Max Niu and Steven Deutekom

# Overview

This is a simple text based adventure game  
Following are instructions for compilation and then some sections of the user  
manual that will help get you going. For full game info and even a walk through  
please see the user manual in docs/user/userManual.pdf

# Compilation

To run the game clone the repository  
at the command line do
```
$ make adventureGame
$./adventureGame
```  
This will build the game and then allow you to run it in your terminal

# How to play

Here we have provided you with an explanation of all the actions the player  
can take and the game commands that are available to you. Followed by a more   
thorough explanation of how to enter you actions and commands. We finish with  
a few hints on what kind of information you are likely to encounter when   
interacting with the game world, and what it might mean.

All actions can be typed with any case you want. Also, except for load, you can  
just use the first letter of the desired action instead of typing the whole   
action. This is most helpful with long action names like inventory.

### Game Actions

The actions available to the player are:
1.  Get    
Moves an item from the room you are in into your inventory. The item can be   
in the room or nested inside a container in the room and you will be   
able to take it.  
eg) > get box  
  
2.  Drop  
Removes an item from your inventory and places it in the room.  
eg) > drop box  
  
3. Use   
Attempts to use an object in the world. If an object is usable you  
will interact it.  
eg) > use common room door  
  
4. Talk   
Interact with an NPC. Can work in 2 ways.
 - Brings up a talk menu. Select the number of the option you would like.   
After making a choice the dialogue will pop back up so you can make another   
choice without having to retype the command. Enter the number for Cancel to   
exit the dialogue.  
 - The NPC will respond in some way. This may be to say something to you   
or give you an item, etc. You should not be shy to talk to them again as   
sometimes they will have more to say, or to do.  
eg) > talk Clem spanner  
5. Look  
Gives you information about the room you are in or a specific object in  
that room.  
eg) > look  → gives room information  
eg) > look box   → gives info about the box and what is in it.  

6. Inventory  
Lists the items in the players inventory.  
eg) > inventory  

### Game Commands
1. Help  
Lists some information on the available player actions and game commands.  
eg) > help   
  
2. Save  
Saves the current state of the game.  
Creates a file using the player's name or overwrites an existing file.  
**NOTE** if you want to try a different approach, but keep previous   
progress use a new name.  
eg) > save  
  
3. Load  
Allows you to load previous progress. Like save this works using the players  
name. So you must start a game with the name of the player you wish to   
restore progress for.  
  
4. Quit  
Exits the game.  
**NOTE** this action is immediate and all unsaved progress will be lost.  

Entering commands

The parser for this game is extremely simple. All commands are read as a verb followed by a noun. This means not all commands will be intuitive to type, and all text after the command or action will be interpreted as the target of that action or command. For example:
  
```
> action target
```
**action** → one of the actions listed above
**target** → the name of the object to apply action to
  
Typing in actions that don't exist will be met with a message telling you you  
can't do that. And if you spell a targets name wrong or try to act on something   
not in the room or your inventory you will be told there isn't one.  

### Some messages
```
You can't verb!
```
You have entered an action that is not available.   
Check your spelling or the help menu and try again.  
```
For some reason you can't
```
This means that you are trying to use an object that is not active yet.   
There is usually a way to activate it. eg) a lock for a door. If your find   
yourself stuck in a room with doors that give this message when you try to use   
them look for other actions to take.
```
You don't have what you need
```
This means that you are trying to do something that requires you to have a    
specific item in your inventory. Like the above message it may result in the   
activation of something or in new actions. Look around for objects you think   
might be useful and try again (remember the object might be in another room).  
  
There will be other messages you encounter.
  
# Tips
1. Items can be active or inactive. Look for ways to activate them.   
They may not always let you know when you have done the right thing
Some items are not obtainable. If you are told you can't get something that 
means you can't ever get it. You don't need to keep trying  

2. Interaction with NPC is not always the same. Try different things.   
You never know if an NPC might have more to say or be more responsive if you   
have something they want in your inventory.  

3. There is no limit to how much you can carry  

4. Our apologies, but due to the limited parser you must type full names of   
any object you wish to interact with. This can get a little cumbersome at   
times and a little misspelling can ruin the attempt. NOTE any extra spaces   
will also result in failure.  

5. You do not have to worry about lower and upper case.   
All input will be fixed so that it can be compared easily. So don't worry about   
capitalizing names and such. Type it how you want to. If it is spelled   
correctly it will work.  

6. All actions except for Load can be entered with just the first letter   
of the action. eg) get or g will work to get something.  