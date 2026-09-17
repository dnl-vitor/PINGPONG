#include <raylib.h>
#include <iostream>
#include "Ball.h"
#include "Globals.h"
#include "Paddle.h"

//int player1_score = 0;
//int player2_score = 0;

Ball ball;
Paddle player;
Player2 player2;

int main(){
    const int scr_width = 1920;
    const int scr_height = 1200;
    const float base_ball_speed = 7.0f;
    const float base_paddle_speed = 10.0f;

    ball.radius = 20;
    ball.x = scr_width/2;
    ball.y = scr_height/2;
    ball.speed_x = base_ball_speed;
    ball.speed_y = base_ball_speed;

    player.width = 25;
    player.height = 120;
    player.x = scr_width - player.width -10;
    player.y = scr_height/2 - player.height/2;
    player.speed = base_paddle_speed;

    player2.width = 25;
    player2.height = 120;
    player2.x = 10;
    player2.y = scr_height/2 - player2.height/2;
    player2.speed = base_paddle_speed;

    InitWindow(scr_width, scr_height, "Ping-Pong!");
    InitAudioDevice();
    SetTargetFPS(60);

    Music soundtrack = LoadMusicStream("assets/mrkillmyself.mp3");
    PlayMusicStream(soundtrack);

    while(WindowShouldClose() == false){
        UpdateMusicStream(soundtrack);
        
        int tempoTotalSegundos = (int)GetTime();
        int minutos = tempoTotalSegundos / 60;
        int segundos = tempoTotalSegundos % 60;
        double tempoEmSegundos = GetTime();
        float fatorAceleracao = 1.0f + ((float)tempoEmSegundos/60.0f) * 1.0f;

        const char* textoTempo = TextFormat("%02i:%02i", minutos, segundos);
        int larguraTexto = MeasureText(textoTempo, 40);
        int posX = (scr_width/2) - (larguraTexto/2);

        player.speed = base_paddle_speed * fatorAceleracao;
        player2.speed = base_paddle_speed * fatorAceleracao;

        ball.speed_x = (ball.speed_x > 0 ? 1 : -1) * (base_ball_speed * fatorAceleracao);
        ball.speed_y = (ball.speed_y > 0 ? 1 : -1) * (base_ball_speed * fatorAceleracao);


        BeginDrawing();
        
            ball.Update();
            player.Update();
            player2.Update();

            if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height})){
                ball.speed_x *= -1;
            }
            if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player2.x, player2.y, player2.width, player2.height})){
                ball.speed_x *= -1;
            }

            ClearBackground(darkBlue);
            DrawRectangle(scr_width/2, 0, scr_width/2, scr_height, cobaltBlue);
            DrawLine(scr_width/2, 0, scr_width/2, scr_height, WHITE);
            
            ball.Draw();
            player.Draw();
            player2.Draw();
            DrawText(TextFormat("%i", player2_score), scr_width/4 - 20, 20, 50, WHITE);
            DrawText(TextFormat("%i", player1_score), 3 * scr_width/4 - 20, 20, 50, WHITE);
            DrawText(textoTempo, posX, 20, 40, YELLOW);
            
        EndDrawing();
    }

    UnloadMusicStream(soundtrack);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
