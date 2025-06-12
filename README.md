# C-Plus-Plus
プログラミング教室「勝山クラブ」で扱うC++プログラムです。
## 作品
 - 弾幕ゲーム
 - リズムマシーン
## 使用音源
この作品は以下の音源を使用しています。
 - 効果音ラボ
 https://soundeffect-lab.info/
 - 魔王魂
 https://maou.audio/

##　使い方
### 弾幕ゲーム
#### 実行
```shell
c++ -std=c++11 danmaku.cpp libraylib.a -framework Cocoa -framework IOkit
./a.out
```
####　操作方法
矢印キーで移動して、敵の弾幕をよける
行き残った時間がスコアになります。

### リズムマシーン
#### 実行
```shell
c++ -std=c++11 rhythm.cpp libraylib.a -framework IOkit -framework Cocoa
./a.out
```
#### 操作方法
マウスクリックで丸を配置
右矢印キー：リズム加速

左矢印キー：リズム減速

上矢印キー：赤丸青丸切り替え