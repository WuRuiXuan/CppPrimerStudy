#include <string>

using namespace std;

class Token {
    public:
        // 因为 union 含有一个 string 成员，所以 Token 必须定义拷贝控制成员
        Token(): tok(INT), ival(0) { }
        Token(const Token& t): tok(t.tok) { copyUnion(t); }
        Token &operator=(const Token&);
        // 如果 union 含有一个 string 成员，则必须销毁它
        ~Token() { if (tok == STR) sval.~string(); }
        // 下面的赋值运算符负责设置 union 的不同成员
        Token& operator=(const string&);
        Token& operator=(char);
        Token& operator=(int);
        Token& operator=(double);
    private:
        enum { INT, CHAR, DBL, STR } tok;
        // 匿名 union
        union {
            char cval;
            int ival;
            double dval;
            string sval;
        };
        // 检查判别式，然后酌情拷贝 union 成员
        void copyUnion(const Token&);
};

Token &Token::operator=(int i)
{
    if (tok == STR) sval.~string();     // 如果当前存储的是 string，释放它
    ival = i;                           // 为成员赋值
    tok = INT;                          // 更新判别式
    return *this;
}

Token &Token::operator=(const string& s)
{
    if (tok == STR)                     // 如果当前存储的是 string，可以直接赋值
        sval = s;
    else
        new(&sval) string(s);           // 否则需要先构造一个 string
    tok = STR;                          // 更新判别式
    return *this;
}

void Token::copyUnion(const Token& t)
{
    switch (t.tok)
    {
        case Token::INT:
            ival = t.ival;
            break;
        case Token::CHAR:
            cval = t.cval;
            break;
        case Token::DBL:
            dval = t.dval;
            break;
        case Token::STR:
            new(&sval) string(t.sval);
            break;
        default:
            break;
    }
}

Token& Token::operator=(const Token& t)
{
    // 如果此对象的值是 string 而 t 的值不是，则我们必须释放原来的 string
    if (tok == STR && t.tok != STR) sval.~string();
    if (tok == STR && t.tok == STR) 
        sval = t.sval;  // tok 是 STR，t.tok 是 STR，无须创造一个新 string
    else
        copyUnion(t);   // tok 不是 STR，t.tok 是 STR，需要构造一个 string
    tok = t.tok;
    return *this;
}