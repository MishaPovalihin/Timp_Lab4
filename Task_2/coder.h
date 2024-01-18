/**
* @file modAlphaCipher.h
* @author Повалихин М.С.
* @version 1.0
* @brief Заголовочный файл для модуля coder
*/

#pragma once
#include <string>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>

/** @brief Класс для шифрования и расшифрования методом маршрутной перестановки
 * @details Ключ
 * Для шифрования - метод encrypt
 * для расшифровки - метод decrypt
 * @warning Реализация для русского и английского языка!
 */
class coder
{
private:
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
	int key1;
    int getValidKey(std::wstring & ws_key);
    /** @brief Метод класса, проверяющий текс на валидность
     ** @param [in] s Текст на русском/английском языке
     ** @return result
     */
    std::wstring getValidOpenText(const std::wstring & ws_open_text);
    /** @brief Метод класса, проверяющий расшифрованный текст на валидность
     ** @param [in] s Зашифрованный текст на русском/английском языке
     ** @return result
     */
    std::wstring getValidCipherText(const std::wstring & ws_cipher_text);
public:
/** @brief Запрет конструктора без параметров
	*/
    coder()=delete; 
    /**
 	* @brief Конструктор класса
 	* @param [in] ws_key Ключ для шифрования
 	* @warning Ключ должен быть целым числов
 	* @throw Invalide key, при неверном ключе
 	*/
    coder(std::wstring & ws_key);
    /** @brief Зашифрование
     ** @param [in] open_text Открытый текст на русском/английском языке
     ** @warning Текст не должен содержать цифры, специальные знаки.
     ** @return result Зашифрованный текст
     ** @throw cipher_error Если в качестве текста введена пустая строка
     */
    std::wstring encrypt(const std::wstring& open_text);
    /** @brief Расшифрование
     ** @param [in] cipher_text Зашифрованный текст на русском/английском языке
     ** @warning Текст не должен содержать цифры, специальные знаки.
     ** @return result Расшифрованный текст
     ** @throw cipher_error Если в качестве текста введена пустая строка
     */
    std::wstring decrypt(const std::wstring& cipher_text); // расшифрование
};

/** @brief Класс вызова исключений 
**  @class cipher_error
 */
class cipher_error: public std::invalid_argument {
public:
     /** @brief Обработка ошибки
     ** @param [in] what_arg Открытый текст на русском/английском языке
     */
	explicit cipher_error (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
	/** @brief Обработка ошибки
     ** @param [in] what_arg Открытый текст на русском/английском языке
     */
	explicit cipher_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
};
