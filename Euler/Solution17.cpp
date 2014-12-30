//
//  Solution17.cpp
//  Euler
//
//  Created by Dani on 2014-12-30.
//  Copyright (c) 2014 Rikard Javelind. All rights reserved.
//

#include "Solution.h"

std::string belowTwenty(int);
std::string belowHundred(int);
std::string belowThousand(int);

void printSolution17() {
    
    int sum = 0;
    for (int n = 1; n <= 1000; n++) {
        sum += belowThousand(n).size();
    }
    
    std::cout << sum;
}

std::string belowThousand(int n) {
    if (n < 100)
        return belowHundred(n);
    
    if (n == 1000)
        return "onethousand";
    
    std::string prefix = belowTwenty((n - n % 100) / 100).append("hundred");
    
    if (n % 100 > 0) {
        return prefix.append("and").append(belowHundred(n % 100));
    }
    
    return prefix;
}
std::string belowHundred(int n) {
    if (n < 20)
        return belowTwenty(n);
    
    std::string prefix;
    
    switch (n - n % 10) {
        case 20:
            prefix = "twenty"; break;
        case 30:
            prefix = "thirty"; break;
        case 40:
            prefix = "forty"; break;
        case 50:
            prefix = "fifty"; break;
        case 60:
            prefix = "sixty"; break;
        case 70:
            prefix = "seventy"; break;
        case 80:
            prefix = "eighty"; break;
        case 90:
            prefix = "ninety"; break;
            
        default:
            break;
    }
    
    return prefix.append(belowTwenty(n % 10));
}

std::string belowTwenty(int n) {
    switch (n) {
        case 0: return "";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 15: return "fifteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
        case 20: return "twenty";
            
        default:
            return "???";
    }
}