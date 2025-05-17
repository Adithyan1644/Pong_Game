# 🏓 Classic Pong Game

A retro-style Pong arcade game implementation using **Raylib** and **C++**. This project demonstrates modern game development techniques while maintaining the nostalgic feel of the original 1972 classic.

A modern implementation of the classic Pong arcade game using Raylib in C++. Features player vs CPU gameplay with score tracking and dynamic ball physics.

![Game Screenshot](Screenshot%202025-05-17%20152344.png)

## Features
- 🕹️ Player-controlled paddle (Right side)
- 🤖 CPU opponent with basic AI (Left side)
- 🎯 Score tracking system
- 🏓 Ball collision physics
- 🎨 Modern visual design with:
  - Custom color scheme
  - Center court circle
  - Dynamic score display
- ⚡ Smooth 60 FPS gameplay

## Controls
- `UP ARROW`: Move paddle upward![Uploading Screenshot (3).png…]()

- `DOWN ARROW`: Move paddle downward

## Installation
### Requirements
- Raylib 4.5+
- C++17 compatible compiler

### Build Instructions
1. Clone repository:
```bash
git clone https://github.com/your-username/pong-game.git
cd pong-game


OUTPUT:
![Screenshot 2025-05-17 152344](https://github.com/user-attachments/assets/3d75a55f-bb0e-4fb4-9dab-b0a373c36279)


Gameplay Mechanics
Score points by getting the ball past opponent's paddle

Ball speed increases after paddle collisions

Random ball direction on serve

First to 15 points wins (as shown in screenshot)

Technical Implementation
Object-Oriented Design:

Ball class handles movement and collisions

Paddle base class with player/CpuPaddle specialization

Collision Detection:

Circle-Rectangle collision for ball-paddle interaction

Wall bouncing physics

AI System:

CPU paddle follows ball's Y-axis position

Predictive movement algorithm

Future Improvements
🔊 Sound effects for collisions and scoring

🚀 Adjustable difficulty levels

🌐 Multiplayer (2-player) mode

🏆 Win condition and celebration animation

📈 High score tracking system

