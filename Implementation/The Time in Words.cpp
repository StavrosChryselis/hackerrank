/*
****************************************************************
****************************************************************
-> Coded by Stavros Chryselis				   
-> Visit my github for more solved problems over multiple sites 
-> https://github.com/StavrosChryselis			  
-> Feel free to email me at stavrikios@gmail.com	
****************************************************************
****************************************************************
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

const std::string
int_to_word(int m)
{
    const std::vector<std::string> numbers = {
        "xxxx", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
        "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", 
        "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", 
        "twenty nine", "thirty"};

    if (m < 1 || m > 29) {
        std::cout << "Bad number: " << m << std::endl;
        return "error in in_to_word!";
    }
    return numbers[m];
}

int
main()
{
    int h;
    std::cin >> h;
    int m;
    std::cin >> m;

    const std::string hour = int_to_word(h);
    if (m == 0) {
        std::cout << hour << " o' clock";
    } else if (m == 15) {
        std::cout << "quarter past " << hour;
    } else if (m == 30) {
        std::cout << "half past " << hour;
    } else if (m == 1) {
        std::cout << "one minute past " << hour;
    } else if (m < 30) {
        std::cout << int_to_word(m) << " minutes past " << hour;
    } else {
        const std::string next_hour = (h < 12 ? int_to_word(h+1) : int_to_word(1));
        
        if (m == 45) {
            std::cout << "quarter to " << next_hour;
        } else if (m == 59) {
            std::cout << "one minute to " << next_hour;
        } else {
            std::cout << int_to_word(60-m) << " minutes to " << next_hour;
        }
    }
    
    std::cout << std::endl;
    
    return 0;
}
