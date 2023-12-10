#ifndef FOOD_WASTAGE_TRACKER_H_
#define FOOD_WASTAGE_TRACKER_H_
#include <algorithm>
#include <iostream>
#include <vector>

#include "food_wastage_record.h"
#include "food_wastage_report.h"
// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>

class FoodWastageTracker {
  // ======================= YOUR CODE HERE =======================
  // Write the FoodWastageTracker class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================
 public:
  // FoodWastageTracker(std::vector<FoodWastageRecord> foodwastagerecord):
  // foodwastagerecord_{foodwastagerecord} {}

  bool AddRecords(const FoodWastageRecord& foodwastagerecord) {
    std::vector<FoodWastageRecord>::iterator it =
        std::find(foodwastagerecord_.begin(), foodwastagerecord_.end(),
                  foodwastagerecord);
    if (it != foodwastagerecord_.end()) {
      return false;
    } else {
      foodwastagerecord_.push_back(foodwastagerecord);
    }
    if (it != foodwastagerecord_.end()) {
      return true;
    } else {
      return false;
    }
  }

  bool DeleteRecords(FoodWastageRecord& foodwastagerecord) {
    std::vector<FoodWastageRecord>::iterator it =
        std::find(foodwastagerecord_.begin(), foodwastagerecord_.end(),
                  foodwastagerecord);
    if (it != foodwastagerecord_.end()) {
      foodwastagerecord_.erase(it);
      return true;
    } else {
      return false;
    }
  }

  const std::vector<FoodWastageRecord>& GetRecords() const {
    return foodwastagerecord_;
  };
  FoodWastageReport GetFoodWastageReport() const {
    FoodWastageReport report(foodwastagerecord_);
    return report;
  }

 private:
  std::vector<FoodWastageRecord> foodwastagerecord_;
};

#endif