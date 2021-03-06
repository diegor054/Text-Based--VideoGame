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
 > We chose to go with abstract factory because it will allow us to encapsulate the creation process of different families of objects. A problem we are expecting is having too many characters that share many of the same elements so it may become redundant. The abstract factory design pattern fixes that problem because we will have creation process of a specific type of character ready to go which eliminates redundancy. Also, this design pattern assures that each character will have the same elements so that we can implement a function such as ???attack??? and the opponent will for sure have a variable such as health. 
 
 >The second design pattern we chose was decorator. Throughout the game we expect user made decisions that will add responsibilities to their character such as being able to mass eliminate a group of enemies. This can become a problem because we would have to make many more subclasses that will be similar to that one that the user currently has. However, decorator will fix that problem since we can dynamically attach responsibilities to an object without having to make another subclass. Another example where this design pattern becomes helpful is the evolution of weapons and armor. As you gain more experience that leads to levels, the weapons (and their attack damage) and armor will increase. Therefore, the decorator design pattern is an effective way to solve this problem and will allow us to make our game more action filled. 
 > 
## Class Diagram
 > This OMT describes how each class is going to be implemented. There will be a class called character where the opponents and user characters will inherit functions and characteristics from it. There will also be an array of opponents that will be composed of opponent members that the user will have to eliminate. There will be various types of opponents and user characters and they will share similar traits. The decorator pattern is used to add one or more abilities to the player or the opponents, and these abilities can be added at run time. There will be an abstract player factory class in which the concrete factories get the interface for the type of player that the user chooses based on user input. There will also be an abstract stage factory class, which has two concrete factories where one will be called to configure the amount, type, and level of the opponents for each stage based on which path the user takes. The scripted description of the paths gives the user the necessary information for the paths so the user can determine whether their player type, level, or other characteristics are more suitable for a different path.
 > 
![Screenshot (135)](https://user-images.githubusercontent.com/69490329/120254038-bdeab000-c23d-11eb-86a0-47de9aaf9586.png)
 
 ## Screenshots
 > ![image](https://user-images.githubusercontent.com/81644719/120352280-7a338d00-c2b5-11eb-954e-fbec5f0fd9d9.png)
 > ![image](https://user-images.githubusercontent.com/81644719/120353192-5ae92f80-c2b6-11eb-9001-3adbd3763f30.png)
 > ![image](https://user-images.githubusercontent.com/81644719/120353795-c501d480-c2b6-11eb-8d9e-d62fc5b7353a.png)

 ## Installation/Usage
 > To install this application, clone this repository onto your local machine that contains CMake. After you call make, run the executable named "dungeon" to play the game.
 > 
 > * git clone --recursive https://github.com/cs100/final-project-drive043_zdamm001_echur002.git
 > * cd final-project-drive043_zdamm001_echur002/
 > * cmake3 .
 > * make
 > * ./dungeon

 ## Testing
 > Our project was tested by using unit tests that we created and then ran by googletest. Our project was also tested for memory leaks by using valgrind.
 >
 > ![image](https://user-images.githubusercontent.com/81644719/120354423-43f70d00-c2b7-11eb-91a8-8ead167f97de.png)
 > ![image](https://user-images.githubusercontent.com/81644719/120356105-d77d0d80-c2b8-11eb-8de5-eb4601838a2e.png)

 
