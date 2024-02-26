#include <iostream>

int main()
{
    int x, result;
    std::cin >> x;
    std::cout << std::endl;
    //(4*x-1)*(4*x+1)/4
    __asm
    {
        mov ecx, 4;
        mov eax, x;
        mul ecx;
        sub eax, 1;
        mov ebx, eax;
        mov eax, x;
        mul ecx;
        add eax, 1;
        mul ebx;
        cdq;
        div ecx;
        mov result, eax;
    }
    std::cout << result << std::endl;

    unsigned int num, sum;

    std::cin >> num;
    std::cout << std::endl;

    __asm
    {
        mov eax, num;
        mov ecx, 10;
        mov sum, 0;
        cdq;
    check:
        cmp eax, 0;
        jz end;
        div ecx;
        add sum, edx;
        mov edx, 0;
        jmp check;
    end:
    }

    std::cout << "num = " << num << std::endl;
    std::cout << "sum = " << sum << std::endl;

    return 0;
}
