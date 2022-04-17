# Dashboard

The goal of this project was to create a web application, more precisely a Dashboard, that works like [Netvibes](https://www.netvibes.com/en).

## Features

The app will offer the following features:
• The user registers on the application in order to obtain an account
• The registered user then confirms their enrollment on the application before being able to use it
• The application then asks the authenticated user to subscribe to Services (cf Services)
• Each Service offers Widgets
• The authenticated user composes his Dashboard by inserting previously configured widget instances
• A Timer allows to refresh the information displayed by the different widget instances present on the Dashboard

## Services and Widgets

The app offers three services:

- Youtube
- Weather
- FF14

As well as 6 widgets:
| Services |Widgets |
|----------------|-------------------------------|
|Weather|Weather of a city|
|Weather|Temperature of a city|
|Youtube|Number of subscribers for a chain|
|Youtube|Number of views for a video|
|Youtube|Last N comments for a video|
|FF14|Jobs of a character|

# Build

Run the command:
docker-compose up --build
