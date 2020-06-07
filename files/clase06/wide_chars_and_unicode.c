// From:
//		https://c-for-dummies.com/blog/?p=2593
//	Set locale from:
//		locale | grep LC_CTYPE

#include <locale.h>
#include <wchar.h>

int main()
{
    wchar_t suits[4] = {
        0x2660, 0x2665, 0x2663, 0x2666
    };

    wchar_t s;
    int x;

    setlocale(LC_CTYPE,"en_US.UTF-8");

    wprintf(L"Enter suit: ( ");
    for(x=0;x<4;x++)
    {
        wprintf(L"%lc ",suits[x]);
    }
    wprintf(L"): ");

    wscanf(L"%lc",&s);
    wprintf(L"Suit set to %lc\n",s);

    return(0);
} 
