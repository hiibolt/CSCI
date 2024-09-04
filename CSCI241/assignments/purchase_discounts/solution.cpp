/**
    * @brief Calculates the discount for a purchase amount.
    *
    * @param amount The purchase amount
    *
    * @return The discounted amount
    */
double discount( double amount ) {
    if ( amount < 50.0 ) {
        // Add a 5% discount
        return amount * 0.95;
    } else if ( amount < 100.0 ) {
        // Add a 10% discount
        return amount * 0.90;
    } else {
        // Add a 15% discount
        return amount * 0.85;
    }
}