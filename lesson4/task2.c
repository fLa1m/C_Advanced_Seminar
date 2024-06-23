// Традиционная запись выражения выглядит так: (1+2) * 4+3. Она не удобна для вычислителя
// (компьютера), поэтому в микрокалькуляторах (спецвычислителях), например БЗ-34 и МК-61,
// применяется обратная польская запись: 1 2 + 4 ? 3 +.
// Напишем такого вида спецвычислитель.
// Необходимо вычислить выражение, написанное в обратной польской записи. На вход
// подается строка, состоящая из целых, неотрицательных чисел и арифметических символов.
// В ответ единственное целое число - результат.
// Выражение работает на сложение и вычитание.

#include <stdio.h>

int calculate(char str[])
{
    int firstOperand;
    int secondOperand;
    int flag = 1;
    for (int i = 0; str[i] != '.'; i++)
    {
        if (str[i] <= '9' && str[i] >= '0')
        {
            int val = 0;
            while (str[i] != ' ')
            {
                val = 10 * val + (str[i] - '0');
                i++;
            }
            if (flag)
            {
                firstOperand = val;
                flag = 0;
            }
            else
            {
                secondOperand = val;
            }
        }
        if (str[i] == '+')
        {
            firstOperand += secondOperand;
        }
        if (str[i] == '-')
        {
            firstOperand -= secondOperand;
        }
        if (str[i] == '*')
        {
            firstOperand *= secondOperand;
        }
        if (str[i] == '/')
        {
            firstOperand /= secondOperand;
        }
    }
    return firstOperand;
}

int main(int argc, char const *argv[])
{
    char str[100];
    scanf("%[^\n]s", &str);
    printf("res = %d", calculate(str));
    return 0;
}
