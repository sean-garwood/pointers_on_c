/*
 * Long-winded preamble:
 *
 *   Writing the code to process cli args is tedious, which suggests there ought
 * to be a std fn to do it. Diff programs handle ther args in diff ways,
 * however, so the fn must be flexible in order for it to be useful in more than
 * just a couple of programs.
 *
 *   For this project, you will write such a function!
 *
 * ***********************************specs*************************************
 *
 * * Provide flexibility by:
 *   * locating args
 *   * extracting args
 *
 * * Callback functions will be provided by the user to process the args.
 *
 * * The prototype must be the following:
 *
 *     char **do_args(int argc, char **argv, char *control,
 *                    void (*do_arg)(int ch, char *value),
 *                    void (*illegal_arg)(int ch));
 *
 *     ***note that the fourth and fifth args are prototypes for callback fns***
 *
 * * do_args must not modify either the cli arg pointers or the args themselves.
 *
 * *********************************parameters**********************************
 *
 * * argc: the number of args, received by main
 * * argv: the args, received by main
 * * control: a string of chars that specify the args that are to be processed
 * * do_arg: a callback fn that processes the args
 * * illegal_arg: a callback fn that processes illegal args
 *
 * *************************processing chars from cli***************************
 *
 * do_args does the following:
 *
 * skip past program name arg
 * while next arg begins with a dash do
 *   for each char in the arg after the dash do
 *     process the char
 * return pointer to next arg pointer
 *
 * *************************processing chars as args****************************
 *
 * check if char is in control string.
 *   if not, call the illegal_arg fn
 *   if it is, and if
 *     is NOT followed by a plus:
 *       call the fn to which do_arg points
 *       pass char and NULL pointer as args
 *     is followed by a plus:
 *   should be a value associated with character. If there are any more
 *   characters in the current argument, then they are the desired value.
 *   Otherwise, the next arg is the value.
 *
 *   In either case, call the fn to which do_arg points, passing the char and
 *   the pointer to the value.
 *
 * If there wasn't a value (no additional chars and no next arg), then call the
 * illegal_arg fn instead.
 *
 * ***Note: be sure that the chars in the value are not processed as args here**
 *
 * *************************returning a pointer*********************************
 *
 * when all the args that begin with a dash have been processed:
 *   return a pointer to the pointer to the next cli arg
 *     (e.g. a value such as &argv[i] or argv + i)
 * If all cli args began with dashes:
 *   return a pointer to the NULL that terminates the cli arg list.
 *
 *
 * OK... now that you have the specs, you can write the code! You've got your
 * work cut out for you, but you can do it!
 */

#include "5.h"

int main(void)
{
    // stub
    return 0;
}

char **do_args(int argc, char **argv, char *control,
               void (*do_arg)(int ch, char *value),
               void (*illegal_arg)(int ch))
{
    // return a pointer to the next arg pointer

    char *str;
    while (*++argv != NULL && **argv == '-') // skip program name
    {
        for (char *arg = *argv + 1; *arg; ++arg) // arg pointing to first char
                                                 // after the dash
        {
            if ((str = strchr(control, *arg)) != NULL)
            {
                if (*(str + 1) == '+')
                {
                    if (*(arg + 1) != '\0')
                    {
                        do_arg(*arg, arg + 1);
                        break;
                    }
                    else if (*(argv + 1) != NULL)
                    {
                        do_arg(*arg, *++argv);
                        break;
                    }
                    else
                    {
                        illegal_arg(*arg);
                        break;
                    }
                }
                else
                    do_arg(*arg, NULL);
            }
            else
                illegal_arg(*arg);
        }
    }
    return argv;
}

void do_arg(int ch, char *value)
{
    printf("do_arg: %c, %s\n", ch, value);
}

void illegal_arg(int ch)
{
    printf("illegal_arg: %c\n", ch);
}
