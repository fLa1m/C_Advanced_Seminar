// ������������ ������ ��������� �������� ���: (1+2) * 4+3. ��� �� ������ ��� �����������
// (����������), ������� � ������������������ (����������������), �������� ��-34 � ��-61,
// ����������� �������� �������� ������: 1 2 + 4 ? 3 +.
// ������� ������ ���� ���������������.
// ���������� ��������� ���������, ���������� � �������� �������� ������. �� ����
// �������� ������, ��������� �� �����, ��������������� ����� � �������������� ��������.
// � ����� ������������ ����� ����� - ���������.
// ��������� �������� �� �������� � ���������.

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
