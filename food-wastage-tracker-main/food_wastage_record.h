#ifndef FOOD_WASTAGE_RECORD_H_
#define FOOD_WASTAGE_RECORD_H_
#include <iostream>

// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>

class FoodWastageRecord {
  // ======================= YOUR CODE HERE =======================
  // Write the FoodWastageRecord class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================
 public:
  // FoodWastageRecord(std::string date, std::string meal, std::string
  // food_name, double quantity, std::string wastage_reason, std::string
  // disposal_mechanism, double cost): date_{date}; meal_{meal};
  // food_name_{food_name}; quanity_{quantity}; wastage_reason_{wastage_reason};
  // disposal_mechanism_{disposal_mechanism}{}
  void SetDate(const std::string& date) { date_ = date; }
  std::string GetDate() const { return date_; }
  void SetMeal(const std::string& meal) { meal_ = meal; }
  std::string GetMeal() const { return meal_; }
  void SetFoodName(const std::string& food_name) { food_name_ = food_name; }
  std::string GetFoodName() const { return food_name_; }
  void SetQuantity(double quantity) { quantity_ = quantity; }
  double GetQuantity() const { return quantity_; }
  void SetWastageReason(const std::string& wastage_reason) {
    wastage_reason_ = wastage_reason;
  }
  std::string GetWastageReason() const { return wastage_reason_; }
  void SetDisposalMechanism(const std::string& disposal_mechanism) {
    disposal_mechanism_ = disposal_mechanism;
  }
  std::string GetDisposalMechanism() const { return disposal_mechanism_; }
  void SetCost(double cost) { cost_ = cost; }
  double GetCost() const { return cost_; }

  bool operator==(const FoodWastageRecord& other) const {
    if (date_ == other.GetDate() && meal_ == other.GetMeal() &&
        food_name_ == other.GetFoodName() && quantity_ == GetQuantity() &&
        wastage_reason_ == other.GetWastageReason() &&
        disposal_mechanism_ == other.GetDisposalMechanism() &&
        cost_ == other.GetCost()) {
      return true;
    } else {
      return false;
    }
  }

 private:
  std::string date_;
  std::string meal_;
  std::string food_name_;
  double quantity_;
  std::string wastage_reason_;
  std::string disposal_mechanism_;
  double cost_;
};

#endif