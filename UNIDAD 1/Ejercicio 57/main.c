int var1;
int var2;
int var3=0;
int var4 = 69;
int var5 = 666;

void func(){
    static int i = 10;
    i++;
}

int main(int argc, char* argv[]){
    func();
    return 0;
}