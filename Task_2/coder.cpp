#include  "coder.h"

using namespace std;

coder::coder(std::wstring & ws_key)
{
	key1 = getValidKey(ws_key);
}

wstring coder::encrypt(const std::wstring& open_text) // шифрование
{
    wstring tabl = getValidOpenText(open_text);
    int len, nstrok, index, x;
    len = open_text.length(); // введенный текст
    nstrok = (len - 1) / key1 + 1; // количество столбцов
    x = 0;
    for (int i = key1; i > 0; i--) { // столбцы
        for (int j = 0; j < nstrok; j++) { // строки
            index = i+key1*j;
            if (index-1 < len) {
                tabl[x] = open_text[index-1];
                x++;
            }
        }
    }
    return tabl;
}

wstring coder::decrypt(const std::wstring& cipher_text) // расшифрование
{
    wstring tabl = getValidCipherText(cipher_text);
    int len, nstrok, index, x;
    len = cipher_text.length();
    nstrok = (len - 1) / key1 + 1; // количество столбцов
    x = 0;
    for (int i = key1; i > 0; i--) { // столбцы
        for (int j = 0; j < nstrok; j++) { // строки
            index = i+key1*j;
            if (index-1 < len) {
                tabl[index-1] = cipher_text[x];
                x++;
            }
        }
    }
    return tabl;
}

inline int coder::getValidKey(std::wstring & ws_key)
{
	if (ws_key.empty())
		throw cipher_error("Empty key");
	std::string s_key = codec.to_bytes(ws_key);
	for (auto & c:ws_key) {
		if (!iswdigit(c)) {
			throw cipher_error(std::string("Invalid key ") + s_key);
		}
	}
	int key = std::stoi(ws_key);
	if (key<=0) {
		throw cipher_error(std::string("Invalid key. Enter a number > 0"));
	}
	return key;
}

inline std::wstring coder::getValidOpenText(const std::wstring & ws_open_text)
{
	std::wstring tmp;
	for (auto c:ws_open_text) {
		if (iswalpha(c)) {
			if (iswlower(c))
				tmp.push_back(towupper(c));
			else
				tmp.push_back(c);
		}
	}
	if (tmp.empty())
		throw cipher_error("Input text is missing");
	return tmp;
}

inline std::wstring coder::getValidCipherText(const std::wstring & ws_cipher_text)
{
	if (ws_cipher_text.empty())
		throw cipher_error("Output text is missing");

	for (auto c:ws_cipher_text) {
		if (!iswupper(c)) {
			if (c != L'-') {
				throw cipher_error(std::string("Invalid text"));
			}
		}
	}
	return ws_cipher_text;
}
