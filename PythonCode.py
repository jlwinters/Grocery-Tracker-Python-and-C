#
#	CS 210, PythonCode.py
#	Purpose: Initalize Python functions based on C++ input from Source.cpp file
#
#	@author Austin Johnson
#	@date 06/16/2021
#
import re
import string


def ItemList():
    #Opening and reading the input item list file
    file = open("ItemList.txt", "r") 
    text = file.read()
    #Output our list in a new line format
    word_list = text.split('\n')
    #Declare an empty dictionary
    word_freq = {}
    #Process the list using a for loop
    for word in word_list:
        #Adds one to our word count in the list for each appearance
        word_freq[word] = word_freq.get(word, 0) + 1
        keys = sorted(word_freq.keys())

    for word in keys:
        #Define our final output
        final=word.capitalize()
        #Print the sorted output, along with the frequency
        print(final + ': ' + str(word_freq[word]))

def ItemFreq(v):
    #Opening and reading the input item list file
    file = open("ItemList.txt", "r") 
    text = file.read()
    #Output our list in a new line format
    word_list = text.split('\n')
    #Declare an empty dictionary
    word_freq = {}
    for word in word_list:
        word_freq[word] = word_freq.get(word, 0) + 1
    #Loop to determine whether C++ string input is located within the item list
    if v in word_freq:
        return word_freq[v]
    else:
        return 0

def Frequency():
    file = open("ItemList.txt", "r") 
    text = file.read()
    word_list = text.split('\n')
    word_freq = {}
    for word in word_list:
        #Create Frequency.dat file
        f = open("frequency.dat", "w")
        word_freq[word] = word_freq.get(word, 0) + 1
        keys = sorted(word_freq.keys())

    for word in keys:
        #Append the sorted information to the .dat file
        f = open("frequency.dat", "a")
        #Define our final output
        final=word.capitalize()
        #Print the sorted output, along with the frequency
        f.write(final + ' ' + str(word_freq[word]) + "\n")
        #Close the file
        f.close()