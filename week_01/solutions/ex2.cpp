#include <iostream>

int main() {

  // you can also check if the hours
  // and  minutes are valid  
  int startHour1, startMins1, endHour1, endMins1;
  int startHour2, startMins2, endHour2, endMins2;
  int startHour3, startMins3, endHour3, endMins3;
  std::cin >> startHour1 >> startMins1 >> endHour1 >> endMins1;
  std::cin >> startHour2 >> startMins2 >> endHour2 >> endMins2;
  std::cin >> startHour3 >> startMins3 >> endHour3 >> endMins3;

  int currHour, currMins;
  std::cin >> currHour >> currMins;

  // pretty obnoxious, i know
  bool isOutsideFirstInterval = currHour < startHour1 || currHour > endHour1 ||
      (currHour == startHour1 && currMins < startMins1) ||
      (currHour == endHour1 && currMins > endMins1);

  bool isOutsideSecondInterval = currHour < startHour2 || currHour > endHour2 ||
      (currHour == startHour2 && currMins < startMins2) ||
      (currHour == endHour2 && currMins > endMins2);

  bool isOutsideThirdInterval = currHour < startHour3 || currHour > endHour3 ||
      (currHour == startHour3 && currMins < startMins3) ||
      (currHour == endHour3 && currMins > endMins3);


  if (isOutsideFirstInterval &&
      isOutsideSecondInterval &&
      isOutsideThirdInterval) {
    std::cout << "Let's do it!\n";
  } 
  else {
    std::cout << "They will catch you!\n";
  }

  
  // another elegant solution would be
  // to convert everything into minutes and then compare

  int totalStartMins1 = startHour1*60 + startMins1;
  int totalEndMins1 = endHour1*60 + endMins1;

  int totalStartMins2 = startHour2*60 + startMins2;
  int totalEndMins2 = endHour2*60 + endMins2;
  
  int totalStartMins3 = startHour3*60 + startMins3;
  int totalEndMins3 = endHour3*60 + endMins3;

  int totalCurrMins = currHour*60 + currMins;


  if ((totalStartMins1 <= totalCurrMins &&
      totalEndMins1 >= totalCurrMins) ||
      (totalStartMins2 <= totalCurrMins &&
      totalEndMins2 >= totalCurrMins) ||
      (totalStartMins3 <= totalCurrMins &&
      totalEndMins3 >= totalCurrMins)) {

    std::cout << "They will catch you!\n";
  }
  else {
    std::cout << "Let's do it!\n";
  }

  return 0;
}