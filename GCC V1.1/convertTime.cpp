#include <iostream>
#include <string>
#include <vector>

void convertTime(const int& hour, const int& minute){
    std::vector<std::string> intToNumber{
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
        "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three",
        "twenty four", "twenty five", "twenty seven", "twenty eight", "twenty nine",
        "thirty", "thirty one", "thirty two", "thirty three", "thirty four", "thirty five",
        "thirty six", "thirty seven", "thirty eight", "thirty nine", "fourty", "fourty one",
        "fourty two", "fourty three", "fourty four", "fourty five", "fourty six", "fourty seven",
        "fourty eight", "fourty nine", "fifty", "fifty one", "fifty two", "fifty three",
        "fifty four", "fifty five", "fifty six", "fifty seven", "fifty eight", "fifty nine"
    };
    if(minute == 0) {std::cout << intToNumber[hour] << " o' clock";}
    if(minute == 1) {std::cout << "one minute past " << intToNumber[hour]; return;}
    if(minute == 15) {std::cout << "quarter past " << intToNumber[hour]; return;}
    if(minute == 30) {std::cout << "half past " << intToNumber[hour]; return;}
    if(minute == 45) {std::cout << "quarter to " << intToNumber[hour + 1]; return;}

    
    if(minute > 0 && minute < 30) {
        std::cout << intToNumber[minute] << " minutes past " << intToNumber[hour];
        return;
    }
    if (minute > 30 && minute < 60){
        std::cout << intToNumber[(60 - minute)] << " minutes to " << intToNumber[hour + 1];
        return;
    }
}

int main() {
    convertTime(5,40);
}