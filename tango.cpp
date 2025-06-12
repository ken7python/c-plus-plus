// c++ tango.cpp
#include <map>
#include <string>

int main(){
    std::map<std::string, std::string> 単語帳;

    単語帳["apple"] = "りんご";
    単語帳["orange"] = "みかん";
    単語帳["草生える"] = "おもろい";
    単語帳["enjoy"] = "楽しむ";
    単語帳["reason"] = "理由";
    単語帳["ploblem"] = "問題";
    単語帳["福井"] = "恐竜";
    単語帳["石川"] = "金箔";
    単語帳["富山"] = "チューリップ";
    単語帳["大阪"] = "たこ焼き";
    単語帳["遣唐使廃止"] = "894";
   

    auto i = 単語帳.begin();
    while(i != 単語帳.end()){
        printf("%s\n", i->first.c_str());
        printf(" ...");
        getchar();//enterを待つ
        printf(" = %s\n", i->second.c_str());
        ++i;
    }

    return 0;
}

