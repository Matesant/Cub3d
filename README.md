# Cub3d

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <div class="header-container">
         <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/covers/cover-cub3d-bonus.png" width="400" alt="Imagem 1"/>
        <img src="https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExdTUxa3NrMnR5cHM3eGdrZDFoYnh4ZmFzYnp2bXhqZHJ0dXdsNHl3MiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/SEMAn3Tnb3tKJ1uDq5/giphy.gif" width="280" alt="Imagem 2"/>
    </div>
</body>
</html>


<h1 align="center">Our first Ray cast</h1>

This repository contains the second graphical project of the 42 curriculum, developed using MinilibX. This project was a collaborative effort with [Alisson Marcos](https://github.com/alissonmarcs).

## About
In this project, we are tasked with creating a game similar to Wolfenstein that employs ray casting. The goal is to develop a 3D perspective game within a 2D plane by implementing ray casting techniques.

### Challenges
- User Input Validation: Ensure that user input is properly validated and handled.
- Map Validation: Verify the integrity and correctness of the map used in the game.
- Ray Casting Logic: Implement the logic to cast rays and render them in a way that simulates a 3D perspective.
- Texture Mapping: Apply textures to enhance the visual appearance and realism of the game.

## Requirements
The functions are written in __C language__ and need the `gcc` along with some graphical libraries..

```shell
$ sudo apt-get install libx11-dev libxext-dev
```

## Instructions

### 1. Compiling the archives

To compile the project, go to its path and run:

For __mandatory__:
```
$ make
```
### 2. Cleaning all binary (.o) and executable files (.a)

To delete all files generated with make, go to the path and run:
```
$ make fclean
```

## Usage

- after compiling, run:

```shell
$ ./cub3d assets/maps/minecrat.cub
```

### Maps

You can create your oun maps!

#### to do so, you will need:

-A Closed Environment: The program will generate an error if the map is open (i.e., if it lacks boundaries).
- Textures: Provide textures of your choice. In the map archive, specify SO, NO, WE, and EA with the paths to PNG texture files.
- Floor and Ceiling Colors: Define the colors for the floor and ceiling. Use F for the floor color and C for the ceiling color, with values ranging from 0 to 255.
- Character Conventions: Adhere to the following map characters:

| CHAR |	OBJECT   |
| --------- | ---------- |
| 1         |   Wall   |
| N	        | Player facing north |
| E	        | Player facing east |
| W         | Player facing west|
| S         | Player facing south|   
| 0         |   Floor     |


