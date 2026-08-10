# Q1 Intuition - Coupon Code Validator

A coupon is valid when:
1. code is non-empty
2. code contains only letters, digits, and underscore
3. businessLine is one of electronics, grocery, pharmacy, restaurant
4. isActive is true

After filtering, sort by businessLine first, then code.
