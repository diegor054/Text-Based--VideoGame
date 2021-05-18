# A Text-Based Role-Playing Game

 > Authors: Diego Rivera (https://github.com/diegor054), Zachary Dammann (https://github.com/zdamm001), Evan Churilov (https://github.com/echur002)
 

# Project Description
 > The project we want to make is a text-based role-playing game. 
 > 
 > In this game, the player will have to choose which character they want to play as which will give them different paths depending on their choice. The player will also fight many stages of enemies, which will help them unlock and level up their abilities. This project is interesting to us because maybe one day we will be working for a company that develops video games so this would be a great place to start. Also, this role-playing game allows us to express our creativity when developing the game which seems fun to us. The programming language that we plan to use is C++. 
 > 
## Tools Used
 > We will also be using Valgrind and CMake.
 > Valgrind is a tool that will help us debug our code and find memory leaks as we are developing it. CMake will allow us to build executables that will use to run our code.
 > 
 ## Input/Output of Game
 >The inputs of our role-playing game will be user input that will guide where the game goes. Based on their decisions(user input), the user can decide what character type they want to use which will give them certain responsibilities and paths. The output for our game will be text based off the path the player chooses to take. This text will be story driven and will reflect what is happening in the game. Some examples other than the story text include health bars, attack quotes, and healing quotes.
 >
 ## Design Patterns
 >The design patterns we plan to use are Abstract Factory and decorator.
 > 
 > We chose to go with abstract factory because it will allow us to encapsulate the creation process of different families of objects. A problem we are expecting is having too many characters that share many of the same elements so it may become redundant. The abstract factory design pattern fixes that problem because we will have creation process of a specific type of character ready to go which eliminates redundancy. Also, this design pattern assures that each character will have the same elements so that we can implement a function such as “attack” and the opponent will for sure have a variable such as health. 
 
 >The second design pattern we chose was decorator. Throughout the game we expect user made decisions that will add responsibilities to their character such as being able to mass eliminate a group of enemies. This can become a problem because we would have to make many more subclasses that will be similar to that one that the user currently has. However, decorator will fix that problem since we can dynamically attach responsibilities to an object without having to make another subclass. Another example where this design pattern becomes helpful is the evolution of weapons and armor. As you gain more experience that leads to levels, the weapons (and their attack damage) and armor will increase. Therefore, the decorator design pattern is an effective way to solve this problem and will allow us to make our game more action filled. 
 > 
## Class Diagram
 > This OMT describes how each class is going to be implemented. There will be a class called character where the opponents and user characters will inherit functions and characteristics from it. There will also be an array of opponents that will be composed of opponent members that the user will have to eliminate. There will be various types of opponents and user characters and they will share similar traits. The decorator pattern is used to add abilities to the player or the opponents, and these abilities can be added at run time. There will be an abstract player class which chooses which type of player based on user input. There will also be an abstract stage factory which will add different opponents to each stage based on which path they take.
 > 
![OMT](https://user-images.githubusercontent.com/81644719/118717710-3d5a9700-b7db-11eb-8cf5-80be6ab2477c.png)
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
