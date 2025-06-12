#include <map>
#include <string>
int main(){
    std::map<std::string, int> 持ち物;

    持ち物["パスポート"] = 1;
    持ち物["財布"] = 0;
    持ち物["パンツ"] = 0;

   { 
    printf("[ まだの物 ]\n");
    auto i = 持ち物.begin();
    while(i != 持ち物.end()){
        if(i->second == 0){
            printf("* %s\n", i->first.c_str());
        }
        ++i;
    }

   }
   {
    printf("[ 持った物 ]\n");
    auto i = 持ち物.begin();
    while(i != 持ち物.end()){
        if(i->second == 1){
            printf("- %s\n", i->first.c_str());
        }
        ++i;
    }
    return 0;
}
}