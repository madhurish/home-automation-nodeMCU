# Home Automation using nodeMCU

## This project was submitted in the Smart India Hackathon - 2018 Grand Finale

Using the nodeMCU and the thinger API (http://thinger.io) we are controlling the appliances using a custom website by making API calls to thinger.

The aim of the project was to make it as user friendly as possible by eliminating the installation over head such as portforwording in the router, etc. and make the setup and usage a really smooth and intiutive process.

## Setup Phase :
Once the nodeMCU is plugged in and has be connected to the device that needs to be controlled by interfacing it via an relay,
the nodeMCU is in the client-mode checks to see if the last connected WiFi is available, one of the two things happen:
1. The nodeMCU finds the WiFi and connects to it
2. The nodeMCU doesn't find the WiFi and goes to the server-mode where the user cans configure WiFi connection.

## Scheduling :
This project also features scheduing using cron jobs where users can select the device, set the time and device state.

## Analytics
The project has analytics to predict the monthly bill based on usage patterns and the users can also visualise the monthly energy consumption data.
