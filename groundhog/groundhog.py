#! /usr/bin/python3

from sys import argv
from math import *


tendency_switch = 0


def header():
    print("SYNOPSIS")
    print("    ./groundhog period\n")
    print("DESCRIPTION")
    print("    period        the number of days defining a period")


def error_handler():
    if len(argv) != 2:
        return 84
    if argv[1].isnumeric() == False:
        return 84
    if int(argv[1]) <= 0:
        return 84


def n_first_values(inc, arg):
    if inc + 1 < arg:
        print("g=nan       r=nan%       s=nan")
        return 0


def temperature_average(arg, input_list, inc):
    ind = 1
    average = 0
    res_list = []

    while ind < len(input_list):
        res = float(input_list[ind]) - float(input_list[ind - 1])
        if res >= 0:
            res_list.append(res)
        else:
            res_list.append(0.0)
        ind += 1
    if inc >= arg:
        average = sum(res_list[-arg:]) / arg
        return '{:.2f}'.format(average)


def temperature_evolution(arg, input_list, inc):
    ind = 1
    evolution = 0
    
    while ind < len(input_list):
        if inc >= arg:
            evolution = ((float(input_list[inc]) - float(input_list[inc - arg])) / float(input_list[inc - arg])) * 100
            return evolution
        ind += 1


def ecart_type(arg, input_list):
    a = list(map(float, input_list))
    moy = (1/len(a[-arg:])) * sum(a[-arg:])
    var = 0

    for nb in a[-arg:]:
        var += (nb - moy)**2
    return sqrt(var/len(a[-arg:]))


def print_values(arg, input_list, inc):
    global tendency_switch
    ind = 0
    average = temperature_average(arg, input_list, inc)
    evolution = temperature_evolution(arg, input_list, inc)
    last_evolution = ((float(input_list[inc - 1]) - float(input_list[inc - 1 - arg])) / float(input_list[inc - 1 - arg])) * 100
    appropriate = ecart_type(arg, input_list)

    if inc < arg:
        print(f"g=nan       r=nan%       s={appropriate:.2f}")
    while ind < len(input_list):
        if inc >= arg and (abs(evolution + last_evolution) == abs(evolution) + abs(last_evolution)) or ind == arg:
            print(f"g={average}       r={evolution:.0f}%       s={appropriate:.2f}")
            return 0
        elif inc >= arg and inc != arg and (abs(evolution + last_evolution) != abs(evolution) + abs(last_evolution)):
            print(f"g={average}       r={evolution:.0f}%       s={appropriate:.2f}       a switch occurs")
            tendency_switch += 1
            return 0
        ind += 1


def stop():
    global tendency_switch
    print(f"Global tendency switched {tendency_switch} times")
    print(f"{tendency_switch} weirdest values are []")


def groundhog(arg):
    input_str = str
    input_list = []
    inc = 0

    while input_str != "STOP":
        try:
            input_str = input()
        except EOFError:
            return 84
        if input_str == "STOP" and inc < arg:
            return 84
        if input_str == "STOP":
            stop()
            return 0
        try:
            input_value = float(input_str)
        except:
            return 84
        input_list.append(input_str)
        n_first_values(inc, arg)
        if inc + 1 >= arg:
            print_values(arg, input_list, inc)
        inc += 1
    return 0


def main():
    if "-h" in argv or "--help" in argv and len(argv) == 2:
        header()
        return 0
    if error_handler() == 84:
        return 84
    if groundhog(int(argv[1])) == 84:
        return 84


if __name__ == "__main__":
    exit(main())