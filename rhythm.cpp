//c++ -std=c++11 rhythm.cpp libraylib.a -framework IOkit -framework Cocoa

#include "raylib.h"
#include <vector>

int main(){
    InitAudioDevice();
    InitWindow(800, 450, "rhythm!");
    SetTargetFPS(60);

    Sound sndRed = LoadSound("pa.mp3");
    Sound sndBlue = LoadSound("pow.mp3");

    int bar_x = 0;
    int bar_s = 1;
    std::vector<Vector2> reds;
    std::vector<Vector2> blues;
    
    std::vector<Vector2>* nows = &reds; 

    while(! WindowShouldClose() ){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Vector2 p = GetMousePosition();

            int keshita = 0;
            {
                auto i = reds.begin();
                while(i !=  reds.end()) {
                    if (CheckCollisionPointCircle(p, *i, 10)){
                        i = reds.erase(i);
                        keshita = keshita + 1;
                    } else{
                        ++i;
                    }
                }
            }
            {
                auto i = blues.begin();
                while(i !=  blues.end()) {
                    if (CheckCollisionPointCircle(p, *i, 10)){
                        i = blues.erase(i);
                        keshita = keshita + 1;
                    } else{
                        ++i;
                    }
                }
            }
            if (keshita == 0){
                p.x = ((int)p.x + 25) / 50 * 50;
                p.y = ((int)p.y + 50) / 100 * 100;
                (*nows).push_back(p);
            }
        }
        if(IsKeyPressed(KEY_UP)){
            if(nows == &reds){
                nows = &blues;
            }else
            if(nows == &blues){
                nows = &reds;
            }
        } 
        if(IsKeyPressed(KEY_RIGHT)){
            bar_s = bar_s + 1;
        }
        if(IsKeyPressed(KEY_LEFT)){
            bar_s = bar_s - 1;
        }

        {
            auto i = reds.begin();
            while(i != reds.end()){
                if(bar_x-bar_s < i->x && i->x <= bar_x){
                    PlaySound(sndRed);
                }
                ++i;
            }
        }
        {
            auto i = blues.begin();
            while(i != blues.end()){
                if(bar_x-bar_s < i->x && i->x <= bar_x){
                    PlaySound(sndBlue);
                }
                ++i;
            }
        }

        BeginDrawing();
            ClearBackground(WHITE);
            if (nows == &reds){
                DrawRectangle(0, 0, 800, 10, RED);
            }else
            if (nows == &blues){
                DrawRectangle(0, 0, 800, 10, BLUE);
            }else
            {}
            DrawLine(bar_x, 0, bar_x, 450, BLACK);
            {
                auto i = reds.begin();
                while(i != reds.end()){
                    DrawCircleV(*i, 10, RED);
                    ++i;
                }
            }
            {
                auto i = blues.begin();
                while(i != blues.end()){
                    DrawCircleV(*i, 10, BLUE);
                    ++i;
                }
            }
        EndDrawing();

        bar_x = bar_x + bar_s;
        if(800 <= bar_x){
            bar_x = 0;
        }
    }

    CloseWindow();
    return 0;

}