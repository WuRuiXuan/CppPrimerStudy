
// Token 类型的对象只有一个成员，该成员的类型可能是下列类型中的任意一种
union Token
{
    // 默认情况下成员是公有的
    char cval;
    int ival;
    double dval;
};

int main()
{
    Token first_token = {'a'};      // 初始化 cval 成员
    Token last_token;               // 未初始化的 Token 对象
    Token *pt = new Token;          // 指向一个未初始化的 Token 对象的指针
    
    last_token.cval = 'z';
    pt->ival = 42;

    // 匿名 union
    union {
        char a_cval;
        int a_ival;
        double a_dval;
    };
    a_cval = 'c';
    a_ival = 42;
}