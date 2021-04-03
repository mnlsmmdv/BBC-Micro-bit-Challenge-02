# BBC Micro:bit Challenge 02 (UWE Bristol - BSc CS)
A simple Morse Code program will be executed on the BBC Micro:bit physical device to execute on two BBC Micro:bit's using crocodile cables using the IO ports.

## Program Description
The program chosen for Challenge 02 is the "Morse Code". It is an intermediate level program and the intended language to be written for Challenge 02 will be in C++ as it was done for challenge 01. The program will be executed on the BBC Micro:bit physical device once the device is powered on and connected to the computer or a external battery pack. There are two Micro:bit devices involved in this challenge 02. Micro:bit #1 is the sender and Micro:bit #2 is the reciever. Once Micro:bit #1 and Micro:bit #2 is powered on and Button B of Micro:bit #1 is pressed, it will use the IO pins using crocodiles cables attached on Micro:bit #1 to transmit an undeciphered Morse Code to Micro:bit #2 through the cable which will be deciphered. If Micro:bit #1's transmission is invalid Micro:bit #2's display will show a scroll message as "MISMATCH".  


## Usage
The program is to only be executed on the BBC Micro:bit device. Attempts to execute the C++ source code's hex code intended for this device and Challenge 01 on any other IOT device has the chance of not to execute and probably run in to errors. Log in to Mbed if you wish to edit the main.cpp file given in this repository and to maybe compile a new program for yourself online after the Micro:bit device is connected to the computer using a Mico USB to USB cable. Compile the code, download and copy the .hex file on to the device and it will run on start. Attach one pair of crocodile cables to each of the "0" pins in both Micro:bit's and attach the other pair to each of the "gnd" pins for it to work.

## Prerequisites
#### 1 - BBC Micro:bit physical device X 2
#### 2 - Computer running either Windows 8-10, currently supported versions of MacOS and Linux
#### 3 - Micro USB to USB cable X 2
#### 4 - Mbed Account with specifications done to execute and edit the source code online (Optional)
#### 5 - External Battery Packs X2

# Contact
#### Name: Ahmed Affaan, Ahmed Ahsan Azim
#### Country: Maldives
#### Language: C++
#### Email: mnlsmmdv13@protonmail.com (Affaan), ahsanazim34@gmail.com (Ahsan)
#### GitHub/GitLab: https://github.com/mnlsmmdv13 (Affaan), https://gitlab.uwe.ac.uk/aa2-azim (Ahsan)
