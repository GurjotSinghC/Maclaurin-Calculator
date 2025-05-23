// ============================================================================
// Name        : Maclaurin Series Calculator
// Author      : Gurjot Singh
// Version     : 23
// Copyright   : Your copyright notice
// Description : Hello world in C++, Ansi-style
// ============================================================================

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

short int terms;
unsigned long long int factorial[50]; // first 11 factorials pre calculated

double finalval;
long double input;
short int accuracy = 30;
long double error;

void clearcin() {
    std::cin.clear();
    std::cin.ignore(10000000, '\n');
}

void setfactorials() {
    factorial[0] = 1;

    for (int i = 1; i <= terms; i++) {
        factorial[i] = std::tgamma(2*i + 1);
    }
}

void StartUP() {
    std::cout << std::endl;
    std::cout
            << "For How many terms will you calculate the Maclaurin Seres of Cosine?"
            << std::endl;
    std::cin >> terms;
    if(terms <0) {
        terms = 0;
    }

    setfactorials();
    std::cout << std::endl;
    std::cout << "For what value would you like x to be for cos(x)"
            << std::endl;
    std::cin >> input;
}

void Output(long double somevalue) {
    std::cout << std::endl;
    std::cout << somevalue;
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(accuracy) << "Your Answer is "
                  << somevalue << std::endl;
        std::cout << std::endl;
        error = pow(input,terms+1) / (std::tgamma(terms+2));
        std::cout << "With an error no greater than " << error << std::endl;
    }

    bool zero_pi_2(long double inputval) {
        if ((0 < inputval) || (0 == inputval)) {
            if ((inputval < M_PI / 2) || (inputval == M_PI / 2)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    bool pi_by2_and_pi(long double inputval) {
        if ((M_PI / 2 < inputval) || (M_PI / 2 == inputval)) {
            if ((inputval < M_PI) || (inputval == M_PI)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    bool pi_and_3pi_by2(long double inputval) {
        if ( (M_PI < inputval) || (M_PI == inputval) ) {
            if ((inputval < 3*M_PI/2) || (inputval == 3*M_PI/2)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    bool threepi2_by_2pi(long double inputval) {

        if ( (3*M_PI/2 < inputval) || (3*M_PI/2 == inputval) ) {
            if ((inputval < 2*M_PI) || (inputval == 2*M_PI)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }


    int main() {
        int a = 2;
        int negativeone = -1;

        while (true) { /***/

        finalval = 0;

        StartUP();

        if (input < 0) {
            input = input * negativeone;
        }
        while(input > (2*M_PI)) {
            input = input - (2*M_PI);
        }

        if (zero_pi_2(input)) {
            for (int e = 0; factorial[e] != 0; e++) {
                finalval = finalval + (pow(negativeone, e) * pow(input, a
    * e)) / factorial[e];
            }
            Output(finalval);
        }

        else if (pi_by2_and_pi(input)) {
            input = M_PI - input;

            for (int e = 0; e <= terms; e++) {
                finalval = finalval + (pow(negativeone, e) * pow(input, a
    * e)) / factorial[e];
            }
            finalval = finalval * negativeone;
            Output(finalval);
        }

        else if (pi_and_3pi_by2(input)) {
            input = input - M_PI;

            for (int e = 0; e <= terms; e++) {
                finalval += (pow(negativeone, e) * pow(input, a * e)) /
    factorial[e];
            }
            finalval = finalval * negativeone;

            Output(finalval);
        }

        else if (threepi2_by_2pi(input)) {
            input = 2*M_PI - input;

            for (int e = 0; e <= terms; e++) {
                finalval += (pow(negativeone, e) * pow(input, a * e)) /
    factorial[e];
            }
            finalval = finalval * negativeone;

            Output(finalval);
        }
        clearcin();
        } /****/
    }

    return 0;

    }
