#include<iostream>
#include<raylib.h>

using namespace std;
int player_score = 0;
int cpu_score = 0;
Color Green = Color{ 113, 227, 125,255 };
Color Yellow = Color{ 252, 255, 0,255 };
Color Orange = Color{ 227, 181, 105,255 };
Color LightGreen = Color{ 163, 235, 121,255 };
class Ball {
public:
    float x, y;
    int radious;
    int speed_x, speed_y;
    void Draw() {
        DrawCircle(x, y, radious, Yellow);
    }
    void Update() {
        x += speed_x;
        y += speed_y;
        if (y + radious >= GetScreenHeight() || y - radious <= 0) {
            speed_y *= -1;
        }

        if (x + radious >= GetScreenWidth())
        {
            cpu_score++;
            ResetBall();
        }

        if (x - radious <= 0) {
            player_score++;
            ResetBall();
        }
    }
    void ResetBall() {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;
        int speed_choices[2] = { -1,1 };
        speed_x *= speed_choices[GetRandomValue(0, 1)];
        speed_y *= speed_choices[GetRandomValue(0, 1)];
    }
};
class Paddle {
protected:
    void LimitedMovement() {
        if (y <= 0) {
            y = 0;
        }
        if (y + hight >= GetScreenHeight()) {
            y = GetScreenHeight() - hight;
        }
    }
public:
    float x, y;
    float hight, width;
    int speed;

    void Draw() {
        DrawRectangleRounded(Rectangle{ x,y,width,hight }, 0.8, 0, WHITE);
    }
    void Update() {
        if (IsKeyDown(KEY_UP)) {
            y = y - speed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            y = y + speed;
        }
        LimitedMovement();
    }
};
class CpuPaddle : public Paddle {
public:
    void Update(int ball_y) {
        if (y + hight / 2 > ball_y) {
            y = y - speed;
        }
        if (y + hight / 2 <= ball_y) {
            y = y + speed;
        }
        LimitedMovement();
    }
};

Ball ball;
Paddle player;
CpuPaddle cpu;
int main() {
    cout << "start game" << endl;
    const int screen_width = 1280;
    const int screen_hight = 800;
    InitWindow(screen_width, screen_hight, "my pong game!");
    SetTargetFPS(60);
    ball.radious = 20;
    ball.x = screen_width / 2;
    ball.y = screen_hight / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;
    player.width = 20;
    player.hight = 120;
    player.x = screen_width - player.width - 10;
    player.y = screen_hight / 2 - player.hight / 2;
    player.speed = 6;
    cpu.hight = 120;
    cpu.width = 20;
    cpu.x = 10;
    cpu.y = screen_width / 2 - screen_hight / 2;
    cpu.speed = 6;
    while (WindowShouldClose() == false) {
        ball.Update();
        player.Update();
        cpu.Update(ball.y);
        BeginDrawing();
        ClearBackground(Green);
        DrawCircle(screen_width / 2, screen_hight / 2, 150, Orange);
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_hight, WHITE);
        ball.Draw();
        player.Draw();
        cpu.Draw();
        if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radious, Rectangle{ player.x,player.y,player.width,player.hight }))
        {
            ball.speed_x *= -1;
        }
        if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radious, Rectangle{ cpu.x,cpu.y,cpu.width,cpu.hight }))
        {
            ball.speed_x *= -1;
        }
        DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 80, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}