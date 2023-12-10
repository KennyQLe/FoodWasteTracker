#ifndef FOOD_WASTAGE_REPORT_H_
#define FOOD_WASTAGE_REPORT_H_
#include <iostream>
#include <map>
#include <vector>

#include "food_wastage_record.h"

// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>

class FoodWastageReport {
  // ======================= YOUR CODE HERE =======================
  // Write the FoodWastageReport class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================
 public:
  FoodWastageReport() {}
  FoodWastageReport(const std::vector<FoodWastageRecord>& food_wastage_records)
      : food_wastage_records_{food_wastage_records} {}

  std::vector<std::string> GetNames() const {
    std::map<std::string, int> name_counter_;
    int max = 0;
    for (FoodWastageRecord record : food_wastage_records_) {
      std::string record_name_ = record.GetFoodName();
      if (name_counter_.count(record_name_) == 0) {
        name_counter_.insert({record_name_, 1});
        if (max < 1) {
          max = 1;
        }  // if max < 1 --> try to add something(lunch) --> max = 1; how do we
           // check if max < 1;
      } else {
        name_counter_[record_name_]++;
        if (name_counter_[record_name_] > max) {
          max = name_counter_[record_name_];
        }
      }
    }
    std::vector<std::string> max_vector_;
    for (std::map<std::string, int>::iterator it = name_counter_.begin();
         it != name_counter_.end(); it++) {
      if (it->second == max) {
        max_vector_.push_back(it->first);
      }
    }
    return max_vector_;
    // needs to find the highest name, if tied then give both?
  }

  std::vector<std::string> GetMostCost()
      const {  // need to generate most common wasted meal(Breakfast, Lunch, or
               // Dinner)
    std::map<std::string, int> name_quantity_;
    int max = 0;
    for (FoodWastageRecord record : food_wastage_records_) {
      std::string names_to_add_quantity_ = record.GetMeal();
      if (name_quantity_.count(names_to_add_quantity_) == 0) {
        name_quantity_.insert({names_to_add_quantity_, 1});
        if (max < 1) {
          max = 1;
        }
      } else {
        name_quantity_[names_to_add_quantity_]++;
        if (name_quantity_[names_to_add_quantity_] > max) {
          max = name_quantity_[names_to_add_quantity_];
        }
      }
    }
    std::vector<std::string> max_vector_;
    for (std::map<std::string, int>::iterator it = name_quantity_.begin();
         it != name_quantity_.end(); it++) {
      if (it->second == max) {
        max_vector_.push_back(it->first);
      }
    }
    return max_vector_;
  }

  double GetTotalCost() const {
    double sum = 0.0;
    for (FoodWastageRecord record : food_wastage_records_) {
      sum += record.GetCost();
    }  // total cost of food
    return sum;
  }
  std::vector<std::string> GetMostReasons()
      const {  //(Too much left overs, Tastes bad, Expired)
    std::map<std::string, int> reason_counter_;
    int max = 0;
    for (FoodWastageRecord record : food_wastage_records_) {
      std::string record_name_ = record.GetWastageReason();
      if (reason_counter_.count(record_name_) == 0) {
        reason_counter_.insert({record_name_, 1});
        if (max < 1) {
          max = 1;
        }
      } else {
        reason_counter_[record_name_]++;
        if (reason_counter_[record_name_] > max) {
          max = reason_counter_[record_name_];
        }
      }
    }
    std::vector<std::string> max_vector_;
    for (std::map<std::string, int>::iterator it = reason_counter_.begin();
         it != reason_counter_.end(); it++) {
      if (it->second == max) {
        max_vector_.push_back(it->first);
      }
    }
    return max_vector_;
  }
  // Sink, Trash, Feed to pet, Compost, Donation
  std::vector<std::string> GetMostMechanisms() const {
    std::map<std::string, int> mechanism_counter_;
    int max = 0;
    for (FoodWastageRecord record : food_wastage_records_) {
      std::string record_name_ = record.GetDisposalMechanism();
      if (mechanism_counter_.count(record_name_) == 0) {
        mechanism_counter_.insert({record_name_, 1});
        if (max < 1) {
          max = 1;
        }
      } else {
        mechanism_counter_[record_name_]++;
        if (mechanism_counter_[record_name_] > max) {
          max = mechanism_counter_[record_name_];
        }
      }
    }
    std::vector<std::string> max_vector_;
    for (std::map<std::string, int>::iterator it = mechanism_counter_.begin();
         it != mechanism_counter_.end(); it++) {
      if (it->second == max) {
        max_vector_.push_back(it->first);
      }
    }
    return max_vector_;
  }
  // Buy less food, Cook small servings, Recycle left overs (if Expired = Donate
  // before expieration) if Tastes bad = Buy less food, if Too much left overs =
  // Buy less food and Cook small servings if not Expired = Recycle left overs
  std::vector<std::string> GetStrategies() const {
    std::vector<std::string> suggestions_;
    bool Donate{false};
    bool Buylessfood{false};
    bool Cooksmaller(false);
    bool Recycle(true);
    for (std::string reason : GetMostReasons()) {
      if (reason == "Expired") {
        Donate = true;
        Recycle = false;
      }
      if (reason == "Tastes bad") {
        Buylessfood = true;
      }
      if (reason == "Too much left overs") {
        Buylessfood = true;
        Cooksmaller = true;
      }
    }
    if (Donate) {
      suggestions_.push_back("Donate before expiration");
    }
    if (Buylessfood) {
      suggestions_.push_back("Buy less food");
    }
    if (Cooksmaller) {
      suggestions_.push_back("Cook small servings");
    }
    if (Recycle) {
      suggestions_.push_back("Recycle left overs");
    }
    if (GetMostReasons().empty()) {
      suggestions_.clear();
    }
    return suggestions_;
  }

 private:
  std::vector<FoodWastageRecord> food_wastage_records_;
};

#endif