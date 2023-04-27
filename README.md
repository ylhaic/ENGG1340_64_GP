Here's a high-level design for your text-based maze adventure game using Norse Mythology as the background. Note that this is only an outline, and you'll have to flesh out the details and implement the C++ code yourself.

1. Game Structure

Create a main class MazeGame to handle the overall game flow, player state, and interactions with the smaller games.
Implement the maze as a graph, where each node represents a room and edges represent the connections between rooms. You can use an adjacency list or adjacency matrix to represent the graph.
Some rooms will contain smaller games (game1, game2, game3, game4, game5), and some rooms will be empty or contain other elements like monsters, treasures, or health potions.
The player will navigate the maze by moving between connected rooms.
2. Norse Mythology Theme

Set the game in the world of Norse Mythology, with locations inspired by the Nine Realms (Asgard, Midgard, Jotunheim, etc.).
The player takes the role of a Norse hero on a quest to retrieve a powerful artifact guarded by monsters and challenges.
The smaller games (game1 to game5) can be themed around Norse myths, like solving riddles posed by a wise god or defeating a monster in a tactical battle.
3. Player State

Implement a Player class to store the player's current state, including health points, weapons, and current room.
Health points decrease when the player loses a small game or encounters a monster.
Weapons can be collected by winning small games and used to defeat monsters.
4. Small Games

Implement each small game as a separate class (e.g., Game1, Game2, etc.) and include them using the header files (game1.h, game2.h, etc.).
The main MazeGame class will handle interactions with the small games, such as starting a game when the player enters a room containing one.
The player will be rewarded with weapons or other items when they win a small game, and lose health points when they lose a small game.
5. Game Flow

The game starts with the player in an initial room and a brief introduction to the story and objective.
The player navigates the maze by choosing directions (e.g., north, south, east, west) to move between rooms.
When entering a room, the game displays a description of the room, any items or monsters present, and available actions.
If the player encounters a small game, they have the option to play it. The game's outcome affects the player's state (e.g., winning gives a weapon, losing reduces health points).
The player can use weapons to defeat monsters and progress through the maze.
The game ends when the player reaches the room containing the powerful artifact or runs out of health points.
This outline provides a starting point for your text-based maze adventure game with a Norse Mythology theme. You can expand on these ideas and implement the game in C++ using your preferred libraries and tools. Good luck!