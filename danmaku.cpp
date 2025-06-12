//c++ -std=c++11 danmaku.cpp libraylib.a -framework Cocoa -framework IOkit

#include "raylib.h"
#include <vector>

struct 主人公{
    int x;
    int y;
    void 動け(){
        if(IsKeyDown(KEY_LEFT)){
            x = x - 3;
        }
        if(IsKeyDown(KEY_RIGHT)){
            x = x + 3;
        }
        if(IsKeyDown(KEY_UP)){
            y = y - 3;
        }
        if(IsKeyDown(KEY_DOWN)){
            y = y + 3;
        }
    }
    void draw(){
        DrawCircle(x, y, 12, YELLOW);
    }
};


struct 弾; 
std::vector<弾*> 弾たち;

struct 弾{
    int x;
    int y;
    int sx;
    int sy;
    int 動け(){
        x = x + sx;
        y = y + sy;
        if(x<0 || 800<x || y<0 || 450<y){
            return 0;
        }
        return 1;
    }
    int check被弾(主人公* shujin){
        return CheckCollisionCircles(
             (Vector2){(float)x,(float)y}, 5,
              (Vector2){(float)(*shujin).x, (float)(*shujin).y}, 12);
    }
    void draw(){
        DrawCircle(x, y, 5, YELLOW);
  
    };
};

struct てき{
    int x;
    int y;
    int xs;
    int ys;
    int 銃口x;
    int 銃口y;
    int 銃口xs;

    void 動け(){
        x = x + xs;
        y = y + ys;
        if(800<x){
            xs = -xs;
        }
        if(x<0){
            xs = -xs;
        }
        if(450<y){
            ys = -ys;
        }
        if(y<0){
            ys = -ys;
        }
    }

    void 弾出す(){
        弾たち.push_back( new 弾{x, y, 銃口x+xs, 銃口y+ys} );
        銃口x = 銃口x + 銃口xs;
        if(銃口x < -20){
            銃口xs = -銃口xs;
        }
        if(+20 < 銃口x){
            銃口xs = -銃口xs;
        }
    }

    void draw(){
        DrawCircle(x, y, 20, BROWN);
    }
};



int main(){
    InitWindow(800, 450, "Danmaku++");
    SetTargetFPS(60);

    主人公 shujin0{ 400, 400};
    てき teki0{ 400, 50, 5, 0, 1, 3, -3 };

    while( !WindowShouldClose() ){
       shujin0.動け();
       teki0.動け();
       teki0.弾出す();

       int gameover = 0;

       {auto i = 弾たち.begin();
       while(i !=弾たち.end()){
        if((**i).check被弾(&shujin0) == 1){
            gameover = 1;
        }
        i = i + 1;
       }}

       if(gameover == 1){
        break;
       }
  
       {auto i = 弾たち.begin();
       while(i != 弾たち.end()){
        int まだいる = (**i).動け();
        if(まだいる == 0){
            delete *i;
           i = 弾たち.erase(i);
        }else{
            i = i + 1;
        }
       }}


        BeginDrawing();

            ClearBackground(BLACK);

            DrawText(TextFormat("%0.1f", GetTime()), 10, 10, 20, WHITE);

            teki0.draw();

       {auto i = 弾たち.begin();
       while(i != 弾たち.end()){
        (**i).draw();
        i = i + 1;
       }}
       shujin0.draw();
        EndDrawing();
    }
    
     float time = GetTime();
     while(! WindowShouldClose() ){
                BeginDrawing();

            ClearBackground(BLACK);

            DrawText(TextFormat("%0.1f", time), 10, 10, 20, WHITE);

            teki0.draw();

       {auto i = 弾たち.begin();
       while(i != 弾たち.end()){
        (**i).draw();
        i = i + 1;
       }}
       shujin0.draw();
        EndDrawing();
    
     }
    

    CloseWindow();
    return 0;
}