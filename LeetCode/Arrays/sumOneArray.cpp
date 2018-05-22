vector<int> sumOneArray(vector<int> number) {
    reverse(number.begin(), number.end());
    int carry = 1;
    for(int i = 0; i < number.size(); i++) {
        number[i] += carry;
        if (number[i] >= 10) {
            number[i] %= 10;
            carry = 1;
        }
    }

    if (carry) {
        number.push_back(carry);
    }
    reverse(number.begin(), number.end());
}