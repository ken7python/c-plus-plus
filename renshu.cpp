#include <stdio.h>
#define 戻る return
#define 箱の形 struct


箱の形 敵{
    int x;
    int y;
    int hp;

    敵(int x, int y, int hp){
        (*this).x = x;
        (*this).y = y;
        (*this).hp = hp;
    }
    
    void ダメージ(int 量){
        (*this).hp = (*this).hp - 量;
    }

    void 合体(敵* あいて){
        (*this).hp = (*this).hp + (*あいて).hp;
        (*あいて).hp = 0;
    }

    void hpを見せる(){
        printf("teki hp:%d\n", (*this).hp);
    }
};

int main(){
    敵 敵A(100, 150, 10);

    敵A.hpを見せる();
    敵A.ダメージ(3);
    敵A.hpを見せる();
    敵A.ダメージ(6);
    敵A.hpを見せる();

    敵 敵B(30, 50, 5);
    敵B.hpを見せる();
    敵B.ダメージ(2);
    敵B.hpを見せる();


    敵A.合体(&敵B);
    敵A.hpを見せる();

    敵B.hpを見せる();

    戻る 0;
}
