#include <stdio.h>
#include <string.h>

// example 1 - strings
void print_string(const char * data, __uint8_t len);

// example 2 - modify data
void modify_value(__uint8_t * data);

// example 3 - function pointers
#define PRINT_VARIABLE_VAL 1

#if PRINT_VARIABLE_VAL == 1
void print_variable_value(int a);
#else
void pva(int a);
#endif

#if PRINT_VARIABLE_VAL == 1
    void (*func_ptr)(int) = print_variable_value;
#else
    void (*func_ptr)(int) = pva;
#endif

int main(void)
{
    // example 1 - strings
   const char *my_str = "MY new string \n";
   print_string(my_str, strlen(my_str));

    // example 2 - modify data
    __uint8_t my_num = 42u;
    printf("Data before: %d \n", my_num);
    modify_value(&my_num);
    printf("Data after: %d \n", my_num);

    // example 3 - function pointers
    func_ptr(42);

    return 0;
}

// example 1 - strings
/*!
 * \brief     Basic function which takes a pointer input of a given length and prints each character individually.
 * \param[in] input_str - pointer to string we want to print.
 * \param[in] len - length of the input string.
 */
void print_string(const char * input_str, __uint8_t len)
{
    for(__uint8_t i = 0; i < len; i++)
    {
        printf("%c", input_str[i]);
    }
}

// example 2 - modify data
/*!
 * \brief         Basic function which takes an input pointer, then modifies the value at that pointer address.
 * \param[in/out] input_ptr - pointer to the address where we want to change the value. 
 */
void modify_value(__uint8_t *input_ptr)
{
    *input_ptr = 5;
}

// example 3 - function pointers
#if PRINT_VARIABLE_VAL == 1
/*!
 * \brief     Basic function which prints the value of variable a
 * \param[in] a - basic integer value.
 */
void print_variable_value(int a) 
{ 
    printf("Value of a is %d\n", a); 
}
#else
/*!
 * \brief     Basic function which prints the address of variable a
 * \param[in] a - basic integer value.
 */
void pva(int a) 
{ 
    printf("Address of a is %p\n", &a); 
}
#endif
