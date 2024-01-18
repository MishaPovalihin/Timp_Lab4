include  "coder.cpp"
#include <locale>
#include <iostream>
#include <codecvt>
using namespace std;


void check(wstring Text, wstring key, bool destructCipherText=false)
{ 
try {
	coder cipher(key);
	wstring enc_text = cipher.encrypt(Text);
	if (destructCipherText)
			enc_text.front() = towlower(enc_text.front());
    wstring dec_text = cipher.decrypt(enc_text);
	wcout<<L"key="<<key<<endl;
	wcout<<Text<<endl;
	wcout<<enc_text<<endl;
	wcout<<dec_text<<endl;
	} catch (const cipher_error & e) {
		cerr<<"Error: "<<e.what()<<endl;
	}
}

int main(int argc, char **argv)
{ 
	locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    wcout << L"1 test:  ";
	check(L"Cессия",L"0"); //ожидалось > 0
	wcout << L"2 test:  ";
	check(L"Cессия",L""); // ожидался ключ
	wcout << L"3 test:  ";
	check(L"Cессия",L">!-*k"); // ожидалось целое число 
	wcout << L"4 test:  ";
	check(L"Cессия",L"3",true); // "ломаем" текст, ожидалось неверный текст 
	wcout << L"5 test:  ";
	check(L"СЕССИЯ",L"3"); // ожидалось верный текст
	wcout << L"6 test:  ";
	check(L"Сес2сия",L"3"); // ожидалось неверный текст 
	wcout << L"7 test:  ";
	check(L"HELLO,СЕССИЯ",L"3"); //ожидалось неверный текст
	wcout << L"8 test:  ";
	check(L"",L"3"); //ожидался текст 
	wcout << L"9 test:  ";
	check(L"HELLOСЕССИЯ",L"3"); //ожидалось верный текст
	return 0;
}

/*******************
bool isValid(const wstring& s)
{
    for (auto c:s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int key;
    wstring text;
    int op;
    wcout<<L"<Введи ключ (целое число): ";
    wcin>>key;
    if (!wcin.good()) {
        wcerr<<L"Ключ недействителен.\n";
        return 0;
    }

    coder cipher(key);
    do {
        wcout<<L"Введи операцию (0-завершить, 1-зашифровать, 2-расшифровать): ";
        wcin>>op;
        if (op != 0 and op != 1 and op != 2) {
            wcout<<L"Незаконная операция!\n";
        } else if (op >0) {
            wcout<<L"Введи текст(без пробелов и капсом): ";
            wcin.ignore(); 
            getline(wcin, text);
            if (isValid(text)) {
                if (op == 1) {
                    wcout<<L"Зашифрованный текст: "<<cipher.encrypt(text)<<endl;
                } else if (op == 2){
                    wcout<<L"Расшифрованный текст: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                wcout<<L"Неверный текст\n";
            }
        }
    } while (op != 0);
    return 0;
}
*********************************/
