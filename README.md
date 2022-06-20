# CS-210 Programming Languages

## Table of Contents

*   [Project Summary](#project-summary)
*   [Author's Notes](#authors-notes)
*   [Challenges](#challenges)
*   [Transferable Skills](#transferable-skills)
*   [Code Layout](#code-layout)

## Project Summary
The goal of this project was to create an item-tracking program for a hypothetical grocery store that links both C++ and Python. The program is designed to display a UI that prompts for user input and executes several functions. Using an item list file, the first option produces a list of all items purchased in a given day along with the frequency. The second option allows the user to input a specific grocery item, and the program will return the frequency of that specific item. The third option displays a histogram of the item data file, with asterisks representing the frequency of each item. Lastly, the user also has the option to close the program.

## Author's Notes
Reflecting on the project, I feel that I did exceptionally well in all categories. The program successfully displays the overall frequency, individual frequency, and histogram of the item list. I have also met the industry standard best practices by including helpful comments in my code and appropriate naming conventions. In terms of improvement, I feel that I could make some changes so that the program is more secure and efficient. In all honesty, I would have likely used only Python if it were an option, since it would allow for the code to be much simpler. Additionally, I would implement a method to access and manage the item list on a server platform, instead of a local text file that can be easily modified by the user.

## Challenges
The biggest challenge that I faced during development was the implementation of the specific item frequency. I was struggling to figure out how I could take a user input string from C++, pass that string to Python, and then return a numeric value to C++. Fortunately, I was able to refer to my previous code for the first option, since both options would require the program to read the item list file and create a dictionary. I spent more time than I would like to admit troubleshooting an error where Python would return the value 0, regardless of user input. I received some helpful feedback from a helpful contributor on the website Stack Overflow. It turns out that I mistakingly passed an integer to Python, instead of a string. Fascinating how a single word can make or break the program! Truly a valuable lesson learned, and I would like to note the helpfulness of using Stack Overflow to ask for assistance.

## Transferable Skills
Moving forward, the most important skill that I will carry into future projects is the ability to utilize multiple coding languages to perform complex functions. It is always a good idea to consider the additional possibilities that different programming languages may bring to your development process.

## Code Layout
During my work on this project, I tried to keep a high level of code readability so that it would be easy to maintain and update. The biggest contributing factor of which, is the comments that I've included in the program. The comments are meant to explain how specific elements were implemented where I felt that it may be confusing. The second most important factor is the naming conventions that I chose for the variables. I am confident that I chose appropriate names that will enhance my code readability.
