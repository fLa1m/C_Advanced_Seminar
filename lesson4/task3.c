// �� ����������� ������ ����� �������� ��� ���������� ������, ���������� �������� ��������
// ������. ������ �� ����� �� ��������� �� ����� 104
// . � ������� �� ����������� ���������� �������.
// �� ����������� ����� ������ ����������� ��� �����, ���������� ��������: ������ ����� � �����
// ����������� �������� ������ ������, ����������� ��������� ������; ������ ����� � ��������, �����
// ����������� �������� ������ ������, ����������� ��������� ������. ��������� �������� ���������
// � ������ �������� (�.�. ������� 'a' � 'A' ��������).

#include <stdio.h>
#include <string.h>

int findMaxPrefSuff(char *str1, char *str2)
{
    for (int i = 0; i < strlen(str1); i++)
    {
        int match = 1;
        for (int j = 0; ((i + j) < strlen(str1) && j < strlen(str2)); j++)
        {
            if (str1[i+j] != str2[j])
            {
                match = 0;
                break;
            } 
        }
        if (match && (strlen(str1) - i <= strlen(str2)))
        {
            return strlen(str1) - i;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char *str1 = "monty_python";
    char *str2 = "python_has_list_comprehensions";
    printf("%d\n", findMaxPrefSuff(str1, str2));
    printf("%d\n", findMaxPrefSuff(str2, str1));
    return 0;
}
