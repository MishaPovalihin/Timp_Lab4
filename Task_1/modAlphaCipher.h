/**
* @file modAlphaCipher.h
* @author Повалихин М.С.
* @version 1.0
* @brief Заголовочный файл для модуля modAlphaCipher
*/
#pragma once
#include <vector>
#include <string>
#include <map>
#include <codecvt>
#include <locale>

/** @brief Класс для шифрования и расшифрования агоритмом Гронсфеьда
 * @details Ключ(вектор тип данных int)
 * Для шифрования - метод encrypt
 * для расшифровки - метод decrypt
 * @warning Реализация только для русского языка!
 */
class modAlphaCipher
{
private:
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec; 
	std::wstring numAlpha = L"АБВГДЕЁЖЗИЙЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Алфавит по порядку
 	std::map <wchar_t,int> alphaNum; ///< Ассоциативный массив "номер по символу"
	std::vector <int> key; ///< Ключ
	/**
 	* @brief Преобразование из строки в ветор.
 	* @param [in] s Строка
 	* Исключения не возбуждаются
 	* @return Вектор, в котором хранятся индесы букв сообщения из алфавита "numAlpha"
 	*/
	std::vector<int> convert(const std::wstring& ws);
	/**
 	* @brief Преобразование из вектора в строку.
 	* @param [in] v Вектор данных
 	* Тип данных int
 	* Исключения не возбуждаются
 	* @return Строка теста типа "wstring"
 	*/
	std::wstring convert(const std::vector<int>& v);
public:
	/** @brief Запрет конструктора без параметров
	*/
	modAlphaCipher()=delete;
	/**
 	* @brief Конструтор класса
 	* @param [in] wskey Ключ для шифрования
 	* @warning Ключ должен состоять из символов алфавита
 	* @throw std::invalid_argument, при неверном ключе
 	*/
	modAlphaCipher(const std::wstring& wskey); 
	/**
 	* @brief Функция Зашифрования
 	* @param [in] open_text Исходный текст
 	* @return Зашифрованная строка
 	*/
	std::wstring encrypt(const std::wstring& open_text);
	/**
	* @brief Функция расшифрования
 	* @param [in] cipher_text Зашифрованная фраза
 	* @return Расшифрованная(исходная) строка
 	*/
	std::wstring decrypt(const std::wstring& cipher_text);
};
