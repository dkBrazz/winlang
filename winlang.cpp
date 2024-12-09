#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

void logValue(const std::wstring& label, unsigned int value) {
    std::wcout << std::left << std::setw(24) << label << "\t"
        << std::right << std::setw(10) << value << "\t"
        << "(0x" << std::hex << std::setw(4) << std::setfill(L'0')
        << value << ")" << std::dec << std::setfill(L' ')
        << ": ";

    wchar_t buf[100];

    if (GetLocaleInfo(value, LOCALE_SISO639LANGNAME, buf, 100)) std::wcout << buf << "_";
    if (GetLocaleInfo(value, LOCALE_SISO3166CTRYNAME, buf, 100)) std::wcout << buf << ", ";
    if (GetLocaleInfo(value, LOCALE_SENGLANGUAGE, buf, 100))  std::wcout << " - " << buf << " ";
    if (GetLocaleInfo(value, LOCALE_SCOUNTRY, buf, 100))  std::wcout << "(" << buf << ")";

    std::wcout << "\n";
}

int wmain()
{
    logValue(L"GetUserDefaultUILanguage", GetUserDefaultUILanguage());
    logValue(L"GetSystemDefaultUILanguage", GetSystemDefaultUILanguage());
    std::wcout << "\n";
    logValue(L"GetUserDefaultLangID", GetUserDefaultLangID());
    logValue(L"GetSystemDefaultLangID", GetSystemDefaultLangID());
    std::wcout << "\n";
    logValue(L"GetUserDefaultLCID", GetUserDefaultLCID());
    logValue(L"GetSystemDefaultLCID", GetSystemDefaultLCID());
    std::wcout << "\n";

    return 0;
}
